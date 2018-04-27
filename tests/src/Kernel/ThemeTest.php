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
   * Test the Drupal 7 theme registry.
   *
   * Test if every theme hooks of the theme registry contains
   * the atomium_preprocess callback at first position.
   */
  public function testRegistry() {
    foreach (theme_get_registry(TRUE) as $info) {
      expect($info)->to->include->keys(['preprocess functions']);
      expect($info['preprocess functions'])
        ->to->be->an('array')
        ->to->contain('atomium_preprocess');
      expect($info['preprocess functions'][0])->equal('atomium_preprocess');
    }
  }

}
