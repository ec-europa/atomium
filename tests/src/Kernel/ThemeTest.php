<?php

namespace Drupal\Tests\atomium\Kernel;

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
      expect($actual)->to->containsArray($expected);
    }
  }

  /**
   * Test attributes generation.
   *
   * @dataProvider attributesProvider
   */
  public function testThemeAttributes($attributes) {
    foreach ($attributes as $attribute) {
      expect(atomium_drupal_attributes($attribute['actual']))->to->equal($attribute['expected']);
    }
  }

}
