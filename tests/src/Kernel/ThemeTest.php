<?php

namespace Drupal\Tests\atomium\Kernel;

use function bovigo\assert\assert;
use function bovigo\assert\predicate\equals;
use function bovigo\assert\predicate\isSameAs;
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

  /**
   * Test preprocess variables generation.
   *
   * @dataProvider variablesPreprocessProvider
   */
  public function testThemeVariablesPreprocess($variables) {
    foreach ($variables as $variable) {
      $input = $variable['actual']['variables'];
      atomium_preprocess($input, $variable['actual']['hook']);
      assert($input, isSameAs($variable['expected']));
    }
  }

  /**
   * Test process variables generation.
   *
   * @dataProvider variablesProcessProvider
   */
  public function testThemeVariablesProcess($variables) {
    foreach ($variables as $variable) {
      $input = $variable['actual']['variables'];
      atomium_process($input, $variable['actual']['hook']);
      assert($input, isSameAs($variable['expected']));
    }
  }

}
