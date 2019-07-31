<?php

namespace Drupal\Tests\atomium\Kernel;

/**
 * Class AbstractThemeTest.
 *
 * @internal
 */
abstract class AbstractThemeTest extends AbstractKernelTest {

  /**
   * {@inheritdoc}
   */
  protected function setUp() {
    parent::setUp();

    global $theme_engine;
    global $conf;

    $conf['theme_debug'] = FALSE;
    $theme_engine = 'atomium_test';
  }

}
