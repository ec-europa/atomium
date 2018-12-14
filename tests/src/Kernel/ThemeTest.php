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
      self::assertArraySubset($expected, $actual);
    }
  }

  /**
   * Test the Drupal 7 theme registry.
   *
   * Test if every theme hooks of the theme registry contains
   * the atomium_preprocess callback at first position.
   */
  public function testRegistry() {
    foreach (theme_get_registry(TRUE) as $info) {
      self::assertArrayHasKey('preprocess functions', $info);
      self::assertInternalType('array', $info['preprocess functions']);
      self::assertContains('atomium_preprocess', $info['preprocess functions']);
      self::assertEquals('atomium_preprocess', $info['preprocess functions'][0]);
    }
  }

}
