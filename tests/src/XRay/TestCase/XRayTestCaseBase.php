<?php

namespace Drupal\Tests\atomium\XRay\TestCase;

use Drupal\Tests\atomium\XRay\AssertUtil;
use Drupal\Tests\atomium\XRay\Canvas\XRayCanvas;
use Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface;
use Drupal\Tests\atomium\XRay\Store\XRayStore_YmlDirectory;
use PHPUnit\Framework\TestCase;

/**
 * Base class for xray tests.
 */
abstract class XRayTestCaseBase extends TestCase {

  /**
   * Generates fixtures files for expected results.
   *
   * @throws \Exception
   */
  final public static function generateFixturesStatic() {
    $instance = new static();
    $instance->generateFixtures();
  }

  /**
   * Generates fixtures files for expected results.
   *
   * @throws \Exception
   */
  final public function generateFixtures() {
    $actual = $this->getValuesByPath();
    $this->getStore()->save($actual);
  }

  /**
   * Compares the actual values to those in the generated fixtures.
   */
  public function testProjection() {

    $actual = $this->getValuesByPath();
    ksort($actual);

    $expected = $this->getStore()->load();
    ksort($expected);

    AssertUtil::assertSameAssoc($expected, $actual, '', 1);
  }

  /**
   * @return mixed[][]
   *   Format: $[$path] = $value
   */
  private function getValuesByPath() {
    $canvas = new XRayCanvas();
    $this->generateValues($canvas);
    return $canvas->getValuess();
  }

  /**
   * @return \Drupal\Tests\atomium\XRay\Store\XRayStoreInterface
   */
  private function getStore() {
    $root = $this->getExpectedValuesDirectory();
    return new XRayStore_YmlDirectory($root);
  }

  /**
   * @return string
   */
  abstract protected function getExpectedValuesDirectory();

  /**
   * @param \Drupal\Tests\atomium\XRay\Canvas\XRayCanvasInterface $canvas
   */
  abstract protected function generateValues(XRayCanvasInterface $canvas);

}
