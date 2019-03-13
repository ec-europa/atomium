<?php

namespace Drupal\Tests\atomium\Unit;

use Symfony\Component\Yaml\Yaml;

/**
 * Class CommonFunctionsTest.
 */
class CommonFunctionsTest extends AbstractUnitTest {

  /**
   * Setup test.
   */
  public function setUp() {
    parent::setUp();

    theme_enable(array('atomium_test', 'atomium_test_test'));
  }

  /**
   * Return atomium_get_theme_info fixtures.
   *
   * @return array
   *   List of component fixtures.
   */
  public function atomiumGetThemeInfoProvider() {
    return Yaml::parseFile(
      __DIR__ . '/../../fixtures/Unit/atomium_get_theme_info.yml'
    );
  }

  /**
   * Test atomium_get_theme_info().
   *
   * @dataProvider atomiumGetThemeInfoProvider
   */
  public function testAtomiumGetThemeInfo($theme, $key, $base_themes, $test, $expected) {
    $settings = atomium_get_theme_info($theme, $key, $base_themes);

    $this::assertSame($expected, $settings[$test]);
  }

}
