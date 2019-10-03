<?php

namespace Drupal\Tests\atomium\Unit;

use Symfony\Component\Yaml\Yaml;

/**
 * Class CommonFunctionsTest.
 *
 * @internal
 * @coversNothing
 */
final class CommonFunctionsTest extends AbstractUnitTest {

  /**
   * Setup test.
   */
  protected function setUp() {
    parent::setUp();

    theme_enable(array('atomium_test', 'atomium_test_test'));
  }

  /**
   * Return atomium_get_theme_info fixtures.
   *
   * @return array
   *   List of component fixtures.
   */
  public function atomiumFieldAttachViewAlterProvider() {
    return Yaml::parseFile(
      __DIR__ . '/../../fixtures/Unit/atomium_field_attach_view_alter.yml'
    );
  }

  /**
   * Return atomium_get_theme_hook_suggestions fixtures.
   *
   * @return array
   *   List of component fixtures.
   */
  public function atomiumGetThemeHookSuggestionsProvider() {
    return Yaml::parseFile(
      __DIR__ . '/../../fixtures/Unit/atomium_get_theme_hook_suggestions.yml'
    );
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
   * Test atomium_field_attach_view_alter().
   *
   * @dataProvider atomiumGetThemeHookSuggestionsProvider
   */
  public function testAtomiumExtendThemeHook($base, $suggestions, $output) {
    $input = _atomium_extend_theme_hook($base, $suggestions);

    $this::assertSame($input, $output);
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

  /**
   * Test atomium_field_attach_view_alter().
   *
   * @dataProvider atomiumFieldAttachViewAlterProvider
   */
  public function testAtomiumRecursiveElementChildren($input, $context, $output) {
    atomium_field_attach_view_alter($input, $context);

    $this::assertSame($input, $output);
  }

}
