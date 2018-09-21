<?php

namespace Drupal\Tests\atomium\XRay;

use PHPUnit\Framework\Assert;
use Symfony\Component\Yaml\Yaml;

/**
 * Contains useful assertion methods.
 */
class AssertUtil {

  /**
   * Asserts that two associative arrays are the same.
   *
   * @param array $expected
   *   Expected value.
   * @param array $actual
   *   Actual value.
   * @param string $trail
   *   Trail to be used in assertion messages.
   * @param int $limit
   *   Recursion limit.
   */
  public static function assertSameAssoc(array $expected, array $actual, $trail, $limit) {

    if ($expected === $actual) {
      return;
    }

    $keys_expected = array_keys($expected);
    $keys_actual = array_keys($actual);
    $map_expected = array_fill_keys($keys_expected, TRUE);
    $map_actual = array_fill_keys($keys_actual, TRUE);

    self::assertSameYml(
      $map_expected,
      $map_actual,
      "Paths must be the same, at '$trail'.");

    foreach ($expected as $path => $values_expected) {
      $values_actual = $actual[$path];

      if (1
        && $limit > 0
        && is_array($values_expected)
        && is_array($values_actual)
      ) {
        self::assertSameAssoc(
          $values_expected,
          $values_actual,
          $trail . ': ' . $path,
          $limit - 1);
      }
      else {
        self::assertSameYml(
          $values_expected,
          $values_actual,
          $trail . ': ' . $path);
      }
    }
  }

  /**
   * Asserts that two values are the same, using Yaml::dump().
   *
   * @param mixed $expected
   *   Expected value.
   * @param mixed $actual
   *   Actual value.
   * @param string $message
   *   Message to send to Assert::assertSame().
   */
  public static function assertSameYml($expected, $actual, $message) {

    if ($expected === $actual) {
      return;
    }

    Assert::assertSame(
      Yaml::dump($expected, 10),
      Yaml::dump($actual, 10),
      $message);

    Assert::assertSame(
      $expected,
      $actual,
      $message);
  }

}
