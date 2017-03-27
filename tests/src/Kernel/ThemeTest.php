<?php

namespace Drupal\Tests\atomium\Kernel;

use function bovigo\assert\assert;
use function bovigo\assert\predicate\equals;
use function Drupal\Tests\atomium\predicate\containsArray;

/**
 * Class ThemeTest.
 *
 * @package Drupal\Tests\atomium\Kernel\ThemeTest
 */
class ThemeTest extends AbstractThemeTest {

  /**
   * Test arguments received by theme functions just before being rendered.
   *
   * @dataProvider componentsProvider
   */
  public function testThemeArguments($hook, $content) {
    $actual = theme($hook);
    foreach ($content as $expected) {
      assert($actual, containsArray($expected));
    }
  }

  /**
   * Test attributes generation.
   *
   * @dataProvider attributesProvider
   */
  public function testThemeAttributes($attributes) {
    foreach ($attributes as $attribute) {
      assert(atomium_drupal_attributes($attribute['actual']), equals($attribute['expected']));
    }
  }

}
