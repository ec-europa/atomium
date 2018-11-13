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
  private $storage = array();

  /**
   * Constructor.
   *
   * @param mixed[] $attributes
   *   Format:
   *   $[$attribute_name_unsafe] = true|false|string|array(..)
   *   $[$attribute_name_unsafe] = $value :string
   *   $[$attribute_name_unsafe][] = $value_part :string
   *   .
   */
  public function __construct(array $attributes = array()) {
    $this->setAttributes($attributes);
  }

  /**
   * Set attributes.
   *
   * @param array|Attributes $attributes
   *   The attributes.
   * @param bool $explode
   *   Should we explode attributes value ?
   *
   * @return $this
   */
  public function setAttributes($attributes = array(), $explode = TRUE) {
    if ($attributes instanceof Attributes) {
      $this->storage = $attributes->toArray();
      $attributes = array();
    }

    foreach ($attributes as $name => $value) {
      if (is_numeric($name)) {
        $this->setAttribute($value, TRUE, $explode);
      }
      else {
        $this->setAttribute($name, $value, $explode);
      }
    }

    return $this;
  }

  /**
   * Gets the value of an attribute.
   *
   * @param mixed $name
   *   The attribute name.
   *
   * @return mixed|null
   *   The attribute value, or an empty array if the attribute does not exist.
   *
   * @see \ArrayAccess::offsetGet()
   */
  public function &offsetGet($name) {
    $return = $this->setStorage(
      $this->getStorage() + array($name => array())
    )->toArray();

    return $return[$name];
  }

  /**
   * Sets the value of an attribute.
   *
   * @param string|int $name
   *   The attribute name.
   * @param bool|string|string[] $value
   *   The value to set.
   *
   * @see \ArrayAccess::offsetSet()
   */
  public function offsetSet($name, $value = FALSE) {
    $storage = $this->getStorage() + array($name => array());

    $storage[$name] = $value;

    $this->setStorage($storage);
  }

  /**
   * Removes an attribute completely.
   *
   * @param string $name
   *   The attribute name.
   *
   * @see \ArrayAccess::offsetUnset()
   */
  public function offsetUnset($name) {
    $storage = $this->getStorage();

    unset($storage[$name]);

    $this->setStorage($storage);
  }

  /**
   * Checks whether an attribute with the given name exists.
   *
   * @param string $name
   *   The attribute name.
   *
   * @return bool
   *   TRUE, if the attribute exists.
   *
   * @see \ArrayAccess::offsetExists()
   */
  public function offsetExists($name) {
    $storage = $this->toArray();

    return isset($storage[$name]);
  }

  /**
   * Sets values for an attribute key.
   *
   * @param string $name
   *   Name of the attribute.
   * @param string|array|bool $value
   *   Value(s) to set for the given attribute key.
   * @param bool $explode
   *   Should we explode attributes value ?
   *
   * @return $this
   */
  public function setAttribute($name, $value = FALSE, $explode = TRUE) {
    $data = $value;

    if (TRUE === $explode && !is_bool($value)) {
      $value = new \RecursiveIteratorIterator(new \RecursiveArrayIterator((array) $value));

      $data = array();

      foreach ($value as $item) {
        $data = array_merge($data, explode(' ', $item));
      }

      $data = array_values(array_filter($data, 'strlen'));
      $data = array_combine($data, $data);
    }

    $this->offsetSet($name, $data);

    return $this;
  }

  /**
   * Append a value into an attribute.
   *
   * @param string $name
   *   The attribute's name.
   * @param string|array|bool $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function append($name, $value = FALSE) {
    $attributes = $this->getStorage();

    if (is_bool($value)) {
      $attributes[$name] = $value;
      $this->storage = $attributes;
    }

    if (empty($name) || is_bool($value)) {
      return $this;
    }

    $attributes += array($name => array());

    $value_iterator = new \RecursiveIteratorIterator(new \RecursiveArrayIterator((array) $value));

    $data = array();
    foreach ($value_iterator as $item) {
      $data = array_merge($data, explode(' ', $item));
    }

    $attributes[$name] = array_unique(array_merge((array) $attributes[$name], array_values(array_filter($data, 'strlen'))));

    return $this->setStorage($attributes);
  }

  /**
   * Remove a value from a specific attribute.
   *
   * @param string $name
   *   The attribute's name.
   * @param string|array|bool $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function remove($name, $value = FALSE) {
    $attributes = $this->getStorage();

    if (!isset($attributes[$name])) {
      return $this;
    }

    if (is_bool($value)) {
      unset($attributes[$name]);
    }
    else {
      if (!is_array($value)) {
        $value = explode(' ', $value);
      }

      $attributes[$name] = array_values(array_diff($attributes[$name], $value));
    }

    return $this->setStorage($attributes);
  }

  /**
   * Delete an attribute.
   *
   * @param string|array $name
   *   The name of the attribute key to delete.
   *
   * @deprecated
   *
   * @return $this
   */
  public function removeAttribute($name = array()) {
    return $this->delete($name);
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
   * @param string $name
   *   The attributes's name.
   * @param array|string $value
   *   The attribute's value.
   *
   * @return static
   */
  public function without($name, $value) {
    $attributes = clone $this;

    return $attributes->remove($name, $value);
  }

  /**
   * Replace a value with another.
   *
   * @param string $name
   *   The attributes's name.
   * @param string $value
   *   The attribute's value.
   * @param array|string $replacement
   *   The replacement value.
   *
   * @return $this
   */
  public function replace($name, $value, $replacement) {
    $attributes = $this->getStorage();

    if (isset($attributes[$name])) {
      $attributes[$name] = array_replace($attributes[$name],
        array_fill_keys(
          array_keys($attributes[$name], $value),
          $replacement
        )
      );
    }

    return $this->setStorage($attributes);
  }

  /**
   * Merge attributes.
   *
   * @param array $data
   *   The data to merge.
   *
   * @return $this
   */
  public function merge(array $data = array()) {
    if ($data instanceof Attributes) {
      $data = $data->toArray();
    }

    if (!is_array($data) || is_null($data)) {
      // @todo: error handling.
      return $this;
    }

    foreach ($data as $name => $value) {
      $this->append($name, $value);
    }

    return $this;
  }

  /**
   * Check if attribute exists.
   *
   * @param string $name
   *   Attribute name.
   * @param string|bool $value
   *   Attribute value.
   *
   * @return bool
   *   Whereas an attribute exists.
   */
  public function exists($name, $value = FALSE) {
    $storage = $this->getStorage();

    if (!isset($storage[$name])) {
      return FALSE;
    }

    return $storage[$name] !== array_filter(
      $storage[$name],
      function ($item) use ($value) {
        return $item !== $value;
      });
  }

  /**
   * Check if attribute contains a value.
   *
   * @param string $name
   *   Attribute name.
   * @param string|bool|int $value
   *   Attribute value.
   *
   * @return bool
   *   Whereas an attribute contains a value.
   */
  public function contains($name, $value = FALSE) {
    $storage = $this->getStorage();

    if (!isset($storage[$name])) {
      return FALSE;
    }

    if (empty($storage[$name])) {
      return FALSE;
    }

    $candidates = $storage[$name];

    if (!is_array($candidates)) {
      $candidates = array($candidates);
    }

    foreach ($candidates as $item) {
      if (FALSE !== stripos($item, $value)) {
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

    foreach ($attributes as $name => &$data) {
      if (is_numeric($name) || is_bool($data)) {
        $data = sprintf('%s', trim(check_plain($name)));
      }
      else {
        $data = array_map(function ($item) use ($name) {
          if ('placeholder' === $name) {
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
        if ('class' === $name) {
          asort($data);
        }

        // If the attribute is numeric, just display the value.
        // Ex: 0="data-closable" will be displayed: data-closable.
        $data = sprintf('%s="%s"', $name, implode(' ', $data));
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
    $array = [];
    foreach ($this->getStorage() as $name => $value) {
      if (is_array($value)) {
        $array[$name] = [];
        foreach ($value as $k => $v) {
          if (!empty($v)) {
            $array[$name][$k] = $v;
          }
        }
      }
      else {
        if (!empty($value)) {
          $array[$name] = [$value];
        }
        else {
          $array[$name] = [];
        }
      }
    }
    return $array;
  }

  /**
   * Returns the whole array.
   *
   * @return array
   *   The storage.
   */
  public function getStorage() {
    // Flatten the array.
    foreach ($this->storage as $name => $member) {
      // Take care of loners attributes.
      if (is_array($member)) {
        $value_iterator = new \RecursiveIteratorIterator(
          new \RecursiveArrayIterator($member)
        );
        $this->storage[$name] = array_values(array_unique(iterator_to_array($value_iterator)));
      }
      elseif (NULL === $member) {
        $this->storage[$name] = [];
      }
      elseif (!is_bool($member)) {
        $this->storage[$name] = [$member];
      }
    }
    return $this->storage;
  }

  /**
   * Set the storage array.
   *
   * @param array $storage
   *   The storage.
   *
   * @return $this
   */
  public function setStorage(array $storage = array()) {
    $this->storage = $storage;

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getIterator() {
    return new \ArrayIterator($this->toArray());
  }

}
