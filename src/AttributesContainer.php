<?php

namespace Drupal\atomium;

/**
 * Class AttributesContainer.
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
      $this->set($name, $value);
    }
  }

  /**
   * Returns the storage array.
   *
   * @return array
   *   The storage array.
   */
  public function getStorage() {
    return $this->storage;
  }

  /**
   * {@inheritdoc}
   */
  public function offsetExists($name) {
    return isset($this->storage[$name]);
  }

  /**
   * {@inheritdoc}
   */
  public function offsetGet($name) {
    if (!isset($this->storage[$name])) {
      $this->set($name);
    }

    return $this->storage[$name];
  }

  /**
   * {@inheritdoc}
   */
  public function offsetSet($name, $value = array()) {
    $this->set($name, $value);
  }

  /**
   * {@inheritdoc}
   */
  public function offsetUnset($name) {
    unset($this->storage[$name]);
  }

  /**
   * Set an attributes.
   *
   * @param string $name
   *   The channel name.
   * @param mixed $value
   *   The data to import.
   *
   * @return $this
   */
  public function set($name, $value = array()) {
    $this->storage[$name] = atomium_get_attributes($value);

    return $this;
  }

}
