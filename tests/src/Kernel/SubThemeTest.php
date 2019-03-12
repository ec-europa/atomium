<?php

namespace Drupal\Tests\atomium\Kernel;

/**
 * Class ThemeTest.
 */
class SubThemeTest extends AbstractThemeTest {

  /**
   * {@inheritdoc}
   */
  protected function setUp() {
    parent::setUp();

    $GLOBALS['conf']['theme_debug'] = FALSE;
    $GLOBALS['conf']['theme_default'] = 'atomium_test_test';

    theme_enable(array('atomium', 'atomium_test_test'));
  }

  /**
   * Test the rendering of a component using the default render.
   */
  public function testRenderMoreLink() {
    $GLOBALS['theme_engine'] = NULL;

    // We unset this variable to ensure drupal_theme_initialize() does its job.
    unset($GLOBALS['theme']);

    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
    drupal_flush_all_caches();

    $this::assertSame(
      'atomium_test_preprocess_more_link,atomium_test_test_preprocess_more_link,tests/themes/atomium_test_test/templates/more_link/more-link.tpl.php',
      theme('more_link')
    );
  }

  /**
   * Test the render of a specific component using a custom render engine.
   */
  public function testThemeMoreLink() {
    // We unset this variable to ensure drupal_theme_initialize() does its job.
    unset($GLOBALS['theme']);

    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
    drupal_flush_all_caches();

    $GLOBALS['theme_engine'] = 'atomium_test';

    $actual = theme('more_link');

    $this::assertSame('sites/all/themes/custom/atomium/tests/themes/atomium_test_test/templates/more_link/more-link.tpl.php', $actual['template']);
    $this::assertSame(
      array(
        'atomium_test_preprocess_more_link',
        'atomium_test_test_preprocess_more_link',
      ),
      $actual['variables']['callbacks']);
  }

}
