<?php

namespace Drupal\Tests\atomium\predicate;

use bovigo\assert\predicate\Predicate;
use Underscore\Types\Arrays;

/**
 * Predicate to test that a value contains something.
 */
class ContainsArray extends Predicate {

  /**
   * Array that must be contained.
   *
   * @var array
   */
  private $needle;

  /**
   * Array element where the comparison fails.
   *
   * @var array
   */
  private $failing;

  /**
   * Current expected comparison value.
   *
   * @var array
   */
  private $expected;

  /**
   * Contains constructor.
   *
   * @param mixed $needle
   *   Array that must be contained.
   */
  public function __construct($needle) {
    $this->needle = $needle;
  }

  /**
   * {@inheritdoc}
   */
  public function test($value) {

    if (!is_array($value)) {
      throw new \InvalidArgumentException('Given value of type "' . gettype($value) . '" can not contain an array.');
    }

    foreach (Arrays::flatten($this->needle) as $dotted => $item) {
      $expected = Arrays::get($value, $dotted);
      if ($item != $expected) {
        $this->failing = [$dotted, $item];
        $this->expected = $expected;
        return FALSE;
      }
    }
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return "contains the following element: value at '{$this->failing[0]}' returned '{$this->expected}' but '{$this->failing[1]}' was expected";
  }

}
