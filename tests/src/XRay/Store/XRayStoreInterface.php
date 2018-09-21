<?php

namespace Drupal\Tests\atomium\XRay\Store;

interface XRayStoreInterface {

  /**
   * @return array
   */
  public function load();

  /**
   * @param array $value
   */
  public function save(array $value);

}
