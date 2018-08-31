<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\Attributes;
use Drupal\atomium\AttributesContainer;

/**
 * Tests known issues in AttributesContainer.
 */
class AttributesContainerKnownIssuesTest extends UnitTestBase {

  /**
   * Tests existing behavior with AttributesContainer->offsetGet().
   */
  public function testOffsetGetByReferenceIsFragile1() {
    $container = new AttributesContainer();
    // Set an illegal value.
    $attribute_object_reference =& $container['element'];
    $attribute_object_reference = new \stdClass();
    // Internal variable is no longer replaced with illegal value.
    // See https://github.com/ec-europa/atomium/issues/142
    self::assertInstanceOf(
      Attributes::class,
      $container['element']);
  }

  /**
   * Tests existing behavior with AttributesContainer->offsetGet().
   */
  public function testOffsetGetByReferenceIsFragile2() {
    $container = new AttributesContainer();
    // Set an illegal value.
    $this->varAssignValue($container['element'], new \stdClass());
    // Internal variable is no longer replaced with illegal value.
    // See https://github.com/ec-europa/atomium/issues/142
    self::assertInstanceOf(
      Attributes::class,
      $container['element']);
  }

  /**
   * Example for a by-reference function that replaces the value.
   *
   * @param mixed $variable
   *   Variable to be modified.
   * @param mixed $value
   *   Value to assign to the variable.
   */
  private function varAssignValue(&$variable, $value) {
    $variable = $value;
  }

}
