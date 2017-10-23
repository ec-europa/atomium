<?php

namespace Drupal\atomium;

/**
 * Class AttributesContainer.
 *
 * @package Drupal\atomium
 */
class AttributesContainer implements \ArrayAccess {
  /**
   * Stores the attribute data.
   *
   * @var array
   */
  protected $storage = array();

  /**
   * AttributesContainer constructor.
   *
   * @param array $attributes
   *   An array of attributes.
   */
  public function __construct(array $attributes = array()) {
    foreach ($attributes as $name => $value) {
      $this->offsetGet($name)->attributes($value);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function &offsetGet($name) {
    if (!isset($this->storage[$name])) {
      $this->storage[$name] = new Attributes();
    }

    return $this->storage[$name];
  }

  /**
   * {@inheritdoc}
   */
  public function offsetSet($name, $value) {
    $this->storage[$name] = $this->offsetGet($name)->attributes($value);
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
   * Returns the whole array.
   */
  public function storage() {
    return $this->storage;
  }

}
