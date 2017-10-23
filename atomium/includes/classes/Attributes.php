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
    $this->attributes($attributes);
  }

  /**
   * Set attributes.
   *
   * @param array|Attributes $attributes
   *   The attributes.
   */
  public function attributes($attributes = array()) {
    if ($attributes instanceof Attributes) {
      $this->storage = $attributes->toArray();
      $attributes = array();
    }

    foreach ($attributes as $name => $value) {
      $this->offsetSet($name, $value);
    }

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function &offsetGet($name) {
    if (!isset($this->storage[$name])) {
      $this->storage[$name] = array();
    }

    return $this->storage[$name];
  }

  /**
   * {@inheritdoc}
   */
  public function offsetSet($name, $value) {
    if (!isset($this->storage[$name])) {
      $this->storage[$name] = array();
    }

    if (!is_array($value)) {
      $value = explode(' ', $value);
    }

    $value_iterator = new \RecursiveIteratorIterator(new \RecursiveArrayIterator($value));

    $data = array();
    foreach (iterator_to_array($value_iterator, FALSE) as $item) {
      $data[] = trim($item);
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
   * @param string|array $value
   *   Value(s) to set for the given attribute key.
   *
   * @return $this
   */
  public function setAttribute($attribute, $value) {
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
   * @param string|array $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function append($key, $value) {
    if (empty($value) || empty($key)) {
      return $this;
    }

    $attributes = $this->storage;

    if (!isset($attributes[$key])) {
      $attributes[$key] = array();
    }

    if (!is_array($value)) {
      $value = explode(' ', $value);
    }

    foreach ($value as $item) {
      $attributes[$key][] = trim($item);
    }

    $this->storage = $attributes;

    return $this;
  }

  /**
   * Remove a value from a specific attribute.
   *
   * @param string $key
   *   The attribute's name.
   * @param string|array $value
   *   The attribute's value.
   *
   * @return $this
   */
  public function remove($key, $value) {
    $attributes = $this->storage;

    if (!isset($attributes[$key])) {
      return $this;
    }

    if (!is_array($value)) {
      $value = explode(' ', $value);
    }

    $attributes[$key] = array_values(array_diff($attributes[$key], $value));

    $this->storage = $attributes;

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
    $attributes = $this->storage();

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
    return atomium_drupal_attributes($this->storage);
  }

  /**
   * Returns all storage elements as an array.
   *
   * @return array
   *   An associative array of attributes.
   */
  public function toArray() {
    $return = array();

    foreach ($this->storage as $name => $value) {
      $return[$name] = $value;
    }

    return $return;
  }

  /**
   * {@inheritdoc}
   */
  public function getIterator() {
    return new \ArrayIterator($this->storage);
  }

  /**
   * Returns the whole array.
   */
  public function storage() {
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
