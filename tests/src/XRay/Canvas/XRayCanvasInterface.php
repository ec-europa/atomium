<?php

namespace Drupal\Tests\atomium\XRay\Canvas;

interface XRayCanvasInterface {

  /**
   * @param string $path
   *   Fragment of a file path.
   * @param string $key
   *   Key or key fragment for within a file, or NULL to make this the top-level
   *   value.
   * @param mixed $value
   *   Value to store the file under the given key.
   */
  public function add($path, $key = NULL, $value);

  /**
   * @param mixed $value
   */
  public function set($value);

  /**
   * @param string|null $path
   * @param string|null $key
   * @param bool $prepend
   *
   * @return \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  public function offset($path, $key = NULL, $prepend = FALSE);

  /**
   * @param string $path
   * @param bool $prepend
   *
   * @return \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  public function offsetPath($path, $prepend = FALSE);

  /**
   * @param string $key
   * @param bool $prepend
   *
   * @return \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface
   */
  public function offsetKey($key, $prepend = FALSE);

}
