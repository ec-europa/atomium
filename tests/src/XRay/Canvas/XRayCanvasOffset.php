<?php

namespace Drupal\Tests\atomium\XRay\Canvas;

class XRayCanvasOffset implements XRayCanvasInterface {

  /**
   * @var \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  private $decorated;

  /**
   * @var string
   */
  private $path;

  /**
   * @var string
   */
  private $key;

  /**
   * @param \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface $decorated
   * @param string $path
   * @param string $key
   */
  public function __construct(XRayCanvasInterface $decorated, $path, $key) {
    $this->decorated = $decorated;
    $this->path = $path;
    $this->key = $key;
  }

  /**
   * @param string $path
   *   Fragment of a file path.
   * @param string $key
   *   Key or key fragment for within a file, or NULL to make this the top-level
   *   value.
   * @param mixed $value
   *   Value to store the file under the given key.
   */
  public function add($path, $key = NULL, $value) {
    $this->decorated->add(
      NULL !== $path
        ? $this->path . '.' . $path
        : $this->path,
      NULL !== $key
        ? $this->key . '/' . $key
        : $this->key,
      $value);
  }

  /**
   * @param mixed $value
   */
  public function set($value) {
    $this->add(NULL, NULL, $value);
  }

  /**
   * @param string|null $path
   * @param string|null $key
   * @param bool $prepend
   *
   * @return static
   */
  public function offset($path, $key = NULL, $prepend = FALSE) {
    $clone = clone $this;
    if (NULL !== $path) {
      $clone->path = $prepend
        ? $path . '.' . $clone->path
        : $clone->path . '.' . $path;
    }
    if (NULL !== $key) {
      $clone->key = $prepend
        ? $key . '.' . $clone->key
        : $clone->key . '.' . $key;
    }
    return $clone;
  }

  /**
   * @param string $path
   * @param bool $prepend
   *
   * @return static
   */
  public function offsetPath($path, $prepend = FALSE) {
    $clone = clone $this;
    $clone->path = $prepend
      ? $path . '.' . $clone->path
      : $clone->path . '.' . $path;
    return $clone;
  }

  /**
   * @param string $key
   * @param bool $prepend
   *
   * @return static
   */
  public function offsetKey($key, $prepend = FALSE) {
    $clone = clone $this;
    $clone->key = $prepend
      ? $key . '.' . $clone->key
      : $clone->key . '.' . $key;
    return $clone;
  }
}
