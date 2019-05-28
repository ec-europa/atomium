<?php

namespace Drupal\atomium;

/**
 * Class Attributes.
 *
 * @SuppressWarnings(PHPMD.ExcessiveClassComplexity)
 */
class Attributes implements \ArrayAccess, \IteratorAggregate {
  /**
   * Stores the attribute data.
   *
   * @var array
   */
  private $storage = array();

  /**
   * {@inheritdoc}
   */
  public function __construct(array $attributes = array()) {
    $this->setAttributes($attributes);
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
      if (\is_numeric($attribute) || \is_bool($data)) {
        $data = \sprintf('%s', \trim(check_plain($attribute)));
      }
      else {
        $data = \array_map(function ($item) use ($attribute) {
          if ($attribute === 'placeholder') {
            $item = \strip_tags($item);
          }

          /*
           * @todo: Disabled for now, it's causing issue in
           * @todo: admin/structure/views/settings.
           *
           * if ('id' === $attribute) {
           *   $item = drupal_html_id($item);.
           * }
           */

          return \trim(check_plain($item));
        }, (array) $data);

        // By default, sort the value of the class attribute.
        if ($attribute === 'class') {
          \asort($data);
        }

        // If the attribute is numeric, just display the value.
        // Ex: 0="data-closable" will be displayed: data-closable.
        $data = \sprintf('%s="%s"', $attribute, \implode(' ', $data));
      }
    }

    // Sort the attributes.
    \asort($attributes);

    return $attributes ? ' ' . \implode(' ', $attributes) : '';
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
    $attributes = $this->getStorage();

    if (\is_bool($value)) {
      $attributes[$key] = $value;
      $this->storage = $attributes;
    }

    if (empty($key) || \is_bool($value)) {
      return $this;
    }

    $attributes += array($key => array());

    $value_iterator = new \RecursiveIteratorIterator(new \RecursiveArrayIterator((array) $value));

    $data = array();
    foreach ($value_iterator as $item) {
      $data = \array_merge($data, \explode(' ', $item));
    }

    $attributes[$key] = \array_unique(\array_merge((array) $attributes[$key], \array_values(\array_filter($data, 'strlen'))));

    return $this->setStorage($attributes);
  }

  /**
   * Check if attribute contains a value.
   *
   * @param string $key
   *   Attribute name.
   * @param string|bool $value
   *   Attribute value.
   *
   * @return bool
   *   Whereas an attribute contains a value.
   */
  public function contains($key, $value = FALSE) {
    $storage = $this->getStorage();

    if (!isset($storage[$key])) {
      return FALSE;
    }

    if (empty($storage[$key])) {
      return FALSE;
    }

    $candidates = $storage[$key];

    if (!\is_array($candidates)) {
      $candidates = array($candidates);
    }

    foreach ($candidates as $item) {
      if (\stripos($item, $value) !== FALSE) {
        return TRUE;
      }
    }

    return FALSE;
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
   * Check if attribute exists.
   *
   * @param string $key
   *   Attribute name.
   * @param string|bool $value
   *   Attribute value.
   *
   * @return bool
   *   Whereas an attribute exists.
   */
  public function exists($key, $value = FALSE) {
    $storage = $this->getStorage();

    if (!isset($storage[$key])) {
      return FALSE;
    }

    return $storage[$key] !== \array_filter(
      $storage[$key],
      function ($item) use ($value) {
        return $item !== $value;
      });
  }

  /**
   * {@inheritdoc}
   */
  public function getIterator() {
    return new \ArrayIterator($this->toArray());
  }

  /**
   * Returns the whole array.
   *
   * @return array
   *   The storage.
   */
  public function getStorage() {
    // Flatten the array.
    \array_walk($this->storage, function (&$member) {
      // Take care of loners attributes.
      if (!\is_bool($member)) {
        $value_iterator = new \RecursiveIteratorIterator(
          new \RecursiveArrayIterator((array) $member)
        );
        $member = \array_values(\array_unique(\iterator_to_array($value_iterator)));
      }
    });

    return $this->storage;
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

    if (!\is_array($data) || $data === NULL) {
      // @todo: error handling.
      return $this;
    }

    foreach ($data as $key => $value) {
      $this->append($key, $value);
    }

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function offsetExists($name) {
    $storage = $this->toArray();

    return isset($storage[$name]);
  }

  /**
   * {@inheritdoc}
   */
  public function offsetGet($name) {
    $return = $this->setStorage(
      $this->getStorage() + array($name => array())
    )->toArray();

    return $return[$name];
  }

  /**
   * {@inheritdoc}
   */
  public function offsetSet($name, $value = FALSE) {
    $storage = $this->getStorage() + array($name => array());

    $storage[$name] = $value;

    $this->setStorage($storage);
  }

  /**
   * {@inheritdoc}
   */
  public function offsetUnset($name) {
    $storage = $this->getStorage();

    unset($storage[$name]);

    $this->setStorage($storage);
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
    $attributes = $this->getStorage();

    if (!isset($attributes[$key])) {
      return $this;
    }

    if (\is_bool($value)) {
      unset($attributes[$key]);
    }
    else {
      if (!\is_array($value)) {
        $value = \explode(' ', $value);
      }

      $attributes[$key] = \array_values(\array_diff($attributes[$key], $value));
    }

    return $this->setStorage($attributes);
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
      $attributes[$key] = \array_replace($attributes[$key],
        \array_fill_keys(
          \array_keys($attributes[$key], $value, TRUE),
          $replacement
        )
      );
    }

    return $this->setStorage($attributes);
  }

  /**
   * Sets values for an attribute key.
   *
   * @param string $attribute
   *   Name of the attribute.
   * @param string|array|bool $value
   *   Value(s) to set for the given attribute key.
   * @param bool $explode
   *   Should we explode attributes value ?
   *
   * @return $this
   */
  public function setAttribute($attribute, $value = FALSE, $explode = TRUE) {
    $data = $value;

    if ($explode === TRUE && !\is_bool($value)) {
      $value = new \RecursiveIteratorIterator(new \RecursiveArrayIterator((array) $value));

      $data = array();

      foreach ($value as $item) {
        $data = \array_merge($data, \explode(' ', $item));
      }

      $data = \array_values(\array_filter($data, 'strlen'));
      $data = \array_combine($data, $data);
    }

    $this->offsetSet($attribute, $data);

    return $this;
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
      if (\is_numeric($name)) {
        $this->setAttribute($value, TRUE, $explode);
      }
      else {
        $this->setAttribute($name, $value, $explode);
      }
    }

    return $this;
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
   * Returns all storage elements as an array.
   *
   * @return array
   *   An associative array of attributes.
   */
  public function toArray() {
    return \array_map(
      function ($value) {
        return \array_filter((array) $value, 'strlen');
      },
      $this->getStorage()
    );
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

}
