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

}
