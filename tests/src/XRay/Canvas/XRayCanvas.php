<?php

namespace Drupal\Tests\atomium\XRay\Canvas;

class XRayCanvas implements XRayCanvasInterface {

  /**
   * @var mixed[][]
   *   Format: $[$path][$key] = $value
   */
  private $values = [];

  /**
   * @return mixed[][]
   */
  public function getValuess() {
    return $this->values;
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
    $this->values[(string) $path][(string) $key] = $value;
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
   * @return \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  public function offset($path, $key = NULL, $prepend = FALSE) {
    return new XRayCanvasOffset(
      $this,
      $path,
      $key);
  }

  /**
   * @param string $path
   * @param bool $prepend
   *
   * @return \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  public function offsetPath($path, $prepend = FALSE) {
    return new XRayCanvasOffset(
      $this,
      $path,
      '');
  }

  /**
   * @param string $key
   * @param bool $prepend
   *
   * @return \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  public function offsetKey($key, $prepend = FALSE) {
    return new XRayCanvasOffset(
      $this,
      '',
      $key);
  }
}
