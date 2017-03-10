<?php

namespace Drupal\Tests\atomium\Unit;

use function bovigo\assert\assert;
use function bovigo\assert\predicate\isTrue;

/**
 * Class SmokeTest.
 *
 * @package Drupal\Tests\atomium\Unit\SmokeTest
 */
class SmokeTest extends AbstractUnitTest {

  /**
   * Smoke test.
   */
  public function testSmoke() {
    assert(TRUE, isTrue());
  }

}
