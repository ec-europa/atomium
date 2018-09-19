<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\Attributes;

/**
 * Tests known issues in the Attributes class.
 */
class AttributesKnownIssuesTest extends UnitTestBase {

  /**
   * Tests existing behavior with Attributes->offsetGet().
   */
  public function testOffsetGetByReferenceIsPointless() {
    $attributes = new Attributes(['class' => ['sidebar']]);
    $attributes['class'][] = 'other-class';
    $attributes['id'][] = 'example-id';
    // The additional values are not added.
    // As an unrelated side effect, an empty attribute 'id' is created.
    self::assertSame(
      ' class="sidebar" id=""',
      $attributes->__toString());
  }

}
