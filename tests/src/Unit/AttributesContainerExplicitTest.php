<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\AttributesContainer;

/**
 * Tests the AttributesContainer class.
 */
class AttributesContainerExplicitTest extends UnitTestBase {

  /**
   * Tests array access.
   */
  public function testAppend() {
    $container = new AttributesContainer();
    $container['element']->append('class', 'sidebar');
    self::assertSame(
      ' class="sidebar"',
      $container['element']->__toString());
  }

}
