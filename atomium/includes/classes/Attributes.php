<?php

namespace Drupal\atomium;

/**
 * Class Attributes.
 *
 * @package Drupal\atomium
 */
class Attributes implements \ArrayAccess, \IteratorAggregate {
  /**
   * Stores the attribute data.
   *
   * @var array
   */
  protected $storage = array();

  /**
   * {@inheritdoc}
   */
  public function __construct(array $attributes = array()) {
    $this->setAttributes($attributes);
  }

  /**
   * Set attributes.
   *
   * @param array|Attributes $attributes
   *   The attributes.
   *
   * @return $this
   */
  public function setAttributes($attributes = array()) {
    if ($attributes instanceof Attributes) {
      $this->storage = $attributes->toArray();
      $attributes = array();
    }

    foreach ($attributes as $name => $value) {
      if (is_numeric($name)) {
        $this->offsetSet($value);
      }
      else {
        $this->offsetSet($name, $value);
      }
    }

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function &offsetGet($name) {
    $this->storage += array($name => array());

    $value = array_values($this->storage[$name]);

    return $value;
  }

  /**
   * {@inheritdoc}
   */
  public function offsetSet($name, $value = FALSE) {
    $this->storage += array($name => array());

    if (is_bool($value)) {
      $data = $value;
    }
    else {
      $value_iterator = new \RecursiveIteratorIterator(new \RecursiveArrayIterator((array) $value));

      $data = array();

      foreach ($value_iterator as $item) {
        $data = array_merge($data, explode(' ', $item));
      }

      $data = array_values(array_filter($data));
      $data = array_combine($data, $data);
    }

    $this->storage[$name] = $data;
  }

  /**
   * {@inheritdoc}
   */
  public function offsetUnset($name) {
    unset($this->storage[$name]);
  }

  /**
   * {@inheritdoc}
   */
  public function offsetExists($name) {
    return isset($this->storage[$name]);
  }

  /**
   * Sets values for an attribute key.
   *
   * @param string $attribute
   *   Name of the attribute.
   * @param string|array|bool $value
   *   Value(s) to set for the given attribute key.
   *
   * @return $this
   */
  public function setAttribute($attribute, $value = FALSE) {
    $this->offsetSet($attribute, $value);

    return $this;
  }

  /**
   * Removes an attribute from an Attribute object.
   *
   * @param string|array ...
   *   Attributes to remove from the attribute array.
   *
   * @return $this
   */
  public function removeAttribute() {
    $args = func_get_args();
    foreach ($args as $arg) {
      // Support arrays or multiple arguments.
      if (is_array($arg)) {
        foreach ($arg as $value) {
          unset($this->storage[$value]);
        }
      }
      else {
        unset($this->storage[$arg]);
      }
    }

    return $this;
  }

  /**
   * Append a value into an attribute.
   *
   * @param string $key
   *   The attribute's name.
   * @param string|array|bool $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function append($key, $value = FALSE) {
    $attributes = $this->storage;

    if (is_bool($value)) {
      $attributes[$key] = $value;
      $this->storage = $attributes;
    }

    if (empty($value) || empty($key) || is_bool($value)) {
      return $this;
    }

    $attributes += array($key => array());

    $value_iterator = new \RecursiveIteratorIterator(new \RecursiveArrayIterator((array) $value));

    $data = array();
    foreach ($value_iterator as $item) {
      $data = array_merge($data, explode(' ', $item));
    }

    $attributes[$key] = array_merge((array) $attributes[$key], array_values(array_filter($data)));

    $this->storage = $attributes;

    return $this;
  }

  /**
   * Remove a value from a specific attribute.
   *
   * @param string $key
   *   The attribute's name.
   * @param string|array|bool $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function remove($key, $value = FALSE) {
    $attributes = $this->storage;

    if (!isset($attributes[$key])) {
      return $this;
    }

    if (is_bool($value)) {
      unset($attributes[$key]);
    }
    else {
      if (!is_array($value)) {
        $value = explode(' ', $value);
      }

      $attributes[$key] = array_values(array_diff($attributes[$key], $value));
    }

    $this->storage = $attributes;

    return $this;
  }

  /**
   * Delete an attribute.
   *
   * @param string|array $name
   *   The name of the attribute key to delete.
   *
   * @return $this
   */
  public function delete($name = array()) {
    $value_iterator = new \RecursiveIteratorIterator(
      new \RecursiveArrayIterator((array) $name)
    );

    foreach ($value_iterator as $item) {
      $this->offsetUnset($item);
    }

    return $this;
  }

  /**
   * Return the attributes.
   *
   * @param string $key
   *   The attributes's name.
   * @param array|string $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function without($key, $value) {
    $attributes = clone $this;

    return $attributes->remove($key, $value);
  }

  /**
   * Replace a value with another.
   *
   * @param string $key
   *   The attributes's name.
   * @param string $value
   *   The attribute's value.
   * @param array|string $replacement
   *   The replacement value.
   *
   * @return $this
   */
  public function replace($key, $value, $replacement) {
    $attributes = $this->getStorage();

    if (isset($attributes[$key])) {
      $attributes[$key] = array_replace($attributes[$key],
        array_fill_keys(
          array_keys($attributes[$key], $value),
          $replacement
        )
      );
    }

    $this->storage = $attributes;

    return $this;
  }

  /**
   * Merge attributes.
   *
   * @param mixed $data
   *   The data to merge.
   *
   * @return $this
   */
  public function merge($data = NULL) {
    if ($data instanceof Attributes) {
      $data = $data->toArray();
    }

    if (!is_array($data) || is_null($data)) {
      // @todo: error handling.
      return $this;
    }

    $this->storage = drupal_array_merge_deep($this->storage, $data);

    return $this;
  }

  /**
   * Check if attribute exists.
   *
   * @param string $key
   *   Attribute name.
   * @param string $value
   *   Attribute value.
   *
   * @return bool
   *   Whereas an attribute exists.
   */
  public function exists($key, $value) {
    if (!isset($this->storage[$key])) {
      return FALSE;
    }

    foreach ($this->storage[$key] as $item) {
      if ($value === $item) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Check if attribute contains a value.
   *
   * @param string $key
   *   Attribute name.
   * @param string $value
   *   Attribute value.
   *
   * @return bool
   *   Whereas an attribute contains a value.
   */
  public function contains($key, $value) {
    if (!isset($this->storage[$key])) {
      return FALSE;
    }

    if (empty($this->storage[$key])) {
      return FALSE;
    }

    $candidates = $this->storage[$key];

    if (!is_array($candidates)) {
      $candidates = array($candidates);
    }

    foreach ($candidates as $item) {
      if (stripos($item, $value) !== FALSE) {
        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    $attributes = $this->getStorage();

    // If empty, just return an empty string.
    if (empty($attributes)) {
      return '';
    }

    foreach ($attributes as $attribute => &$data) {
      if (is_numeric($attribute) || is_bool($data)) {
        $data = sprintf('%s', trim(check_plain($attribute)));
      }
      else {
        $data = array_map(function ($item) use ($attribute) {
          if ('placeholder' === $attribute) {
            $item = strip_tags($item);
          }

          /*
           * @todo: Disabled for now, it's causing issue in
           * @todo: admin/structure/views/settings.
           *
           * if ('id' === $attribute) {
           *   $item = drupal_html_id($item);.
           * }
           */

          return trim(check_plain($item));
        }, (array) $data);

        // By default, sort the value of the class attribute.
        if ('class' === $attribute) {
          asort($data);
        }

        // If the attribute is numeric, just display the value.
        // Ex: 0="data-closable" will be displayed: data-closable.
        $data = sprintf('%s="%s"', $attribute, implode(' ', $data));
      }
    }

    // Sort the attributes.
    asort($attributes);

    return $attributes ? ' ' . implode(' ', $attributes) : '';
  }

  /**
   * Returns all storage elements as an array.
   *
   * @return array
   *   An associative array of attributes.
   */
  public function toArray() {
    $return = array();

    foreach ($this->getStorage() as $name => $value) {
      $return[$name] = array_filter(array_values((array) $value));
    }

    return $return;
  }

  /**
   * {@inheritdoc}
   */
  public function getIterator() {
    return new \ArrayIterator($this->getStorage());
  }

  /**
   * Returns the whole array.
   */
  public function getStorage() {
    // Flatten the array.
    array_walk($this->storage, function (&$member) {
      // Take care of loners attributes.
      if (!is_bool($member)) {
        $value_iterator = new \RecursiveIteratorIterator(
          new \RecursiveArrayIterator((array) $member)
        );
        $member = iterator_to_array($value_iterator);
      }
    });

    return $this->storage;
  }

  /**
   * Returns a representation of the object for use in JSON serialization.
   *
   * @return string
   *   The safe string content.
   */
  public function jsonSerialize() {
    return (string) $this;
  }

}
