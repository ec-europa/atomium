<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\Attributes;
use Symfony\Component\Yaml\Yaml;

/**
 * Tests the Attributes class.
 */
class AttributesExplicitTest extends UnitTestBase {

  /**
   * Tests whether attributes are ordered by name.
   */
  public function testAttributesOrder() {

    self::assertToString(
      ' aaa class="sidebar" x="y" zzz',
      new Attributes(
        [
          'zzz' => TRUE,
          'x' => 'y',
          'aaa' => FALSE,
          'class' => ['sidebar'],
        ]));
  }

  /**
   * Tests whether attributes value fragments are sorted.
   */
  public function testValueOrder() {
    self::assertToString(
      ' class="b a z" name="z b a"',
      new Attributes(
        [
          'class' => ['z', 'b a'],
          'name' => ['z', 'b a'],
        ]));
  }

  /**
   * Tests Attributes->offsetGet() and ->offsetExists().
   */
  public function testOffset() {

    $attributes = new Attributes();
    self::assertToArray(
      [],
      $attributes);
    self::assertToString(
      '',
      $attributes);
    // offsetGet() used to have a side effect, but now that is fixed.
    self::assertSame(
      [],
      $attributes['class']);
    self::assertToArray(
      [],
      $attributes);
    self::assertToString(
      '',
      $attributes);

    foreach ([
      [TRUE, TRUE],
      [FALSE, TRUE],
      [['a', 'b', 'c'], ['a', 'b', 'c']],
      ['cat', ['cat']],
      ['', [], TRUE],
      [0, []],
    ] as $data) {
      list($value, $expectedOffsetGet, $expectedOffsetExists) = $data
      + [NULL, NULL, TRUE];

      $attributes = new Attributes(['_name_' => $value]);

      self::assertSame(
        $expectedOffsetGet,
        $attributes->offsetGet('_name_'),
        sprintf(
          '(new Attributes([\'_name_\' => %s]))->offsetGet(\'_name_\')',
          var_export($value, TRUE)));

      self::assertSame(
        $expectedOffsetExists,
        $attributes->offsetExists('_name_'),
        sprintf(
          '(new Attributes([\'_name_\' => %s]))->offsetExists(\'_name_\')',
          var_export($value, TRUE)));
    }

    $attributes = new Attributes();
    self::assertFalse($attributes->offsetExists('_name_'));
  }

  /**
   * Tests Attributes->append()
   */
  public function testAppend() {

    $attributes = new Attributes($array = ['boolean' => TRUE]);
    $message = '(new Attributes(' . json_encode($array) . '))';

    self::assertToString(
      ' boolean',
      $attributes);

    self::assertAppend(
      ' boolean="1 xx"',
      [
        'boolean' => ['1', 'xx'],
      ],
      $attributes,
      [
        ['boolean', 'xx'],
      ],
      $message);

    self::assertAppend(
      ' boolean',
      [
        'boolean' => TRUE,
      ],
      $attributes,
      [
        ['boolean', TRUE],
      ],
      $message);

    $attributes = new Attributes($array = ['parts' => ['aa', 'bb']]);
    $message = '(new Attributes(' . json_encode($array) . '))';

    self::assertAppend(
      ' parts',
      [
        'parts' => TRUE,
      ],
      $attributes,
      [
        ['parts', TRUE],
      ],
      $message);

    self::assertAppend(
      ' parts="aa bb 1"',
      [
        'parts' => ['aa', 'bb', '1'],
      ],
      $attributes,
      [
        ['parts', [TRUE]],
      ],
      $message);

    self::assertAppend(
      ' parts="1 zz"',
      [
        'parts' => ['1', 'zz'],
      ],
      $attributes,
      [
        ['parts' , 'xx'],
        ['parts', TRUE],
        ['parts', ['zz']],
      ],
      $message);

    self::assertAppend(
      ' parts="aa bb uu vv yy zz"',
      [
        'parts' => ['aa', 'bb', 'uu vv', 'yy zz'],
      ],
      $attributes,
      [
        ['parts', 'uu vv'],
        ['parts', ['yy zz']],
      ],
      $message);

    self::assertAppend(
      ' parts="aa bb zz dd cc"',
      [
        'parts' => ['aa', 'bb', 'zz', 'dd cc'],
      ],
      $attributes,
      [
        ['parts', 'zz'],
        ['parts', ['dd cc']],
      ],
      $message);
  }

  /**
   * Tests Attributes->offsetSet().
   */
  public function testOffsetSet() {

    foreach ([
      [TRUE, TRUE],
      [[TRUE], '1'],
      [['a', TRUE, 'z'], 'a 1 z'],
      [['a', [TRUE], 'z'], 'a 1 z'],
      ['', ''],
      [' ', ' '],
      [[''], ''],
      [[' '], ' '],
      [['a', ' ', 'z'], 'a   z'],
      [[1, ['two', [3]]], '1 two 3'],
      [' a  b', ' a  b'],
    ] as $value_and_expected) {
      list($value, $expected_output) = $value_and_expected;

      if (TRUE === $expected_output) {
        $expected = ' name';
      }
      elseif (NULL === $expected_output) {
        $expected = '';
      }
      else {
        $expected = ' name="' . $expected_output . '"';
      }

      self::assertOffsetSetToString(['name' => $value], $expected);
    }
  }

  /**
   * Asserts the behavior of Attributes->append().
   *
   * @param string $expected_to_string
   *   Expected value for ->__toString() after ->append().
   * @param array $expected_to_array
   *   Expected value for ->toArray() after ->append().
   * @param \Drupal\atomium\Attributes $attributes
   *   Attributes object to start with.
   * @param array $append_argss
   *   Arguments for ->append() calls.
   *   Format: $[] = [$name, $value].
   * @param string $message
   *   Message to send to self::assertSame().
   */
  private static function assertAppend($expected_to_string, array $expected_to_array, Attributes $attributes, array $append_argss, $message = '') {

    $attributes = clone $attributes;

    foreach ($append_argss as $name_and_args) {
      list($name, $args) = $name_and_args;
      $attributes->append($name, $args);
      $message .= "\n  ->append("
        . json_encode($name) . ', '
        . json_encode($args) . ')';
    }

    self::assertToString($expected_to_string, $attributes, $message);

    self::assertToArray($expected_to_array, $attributes, $message);
  }

  /**
   * Asserts the behavior of Attributes->offsetSet().
   *
   * @param array $values
   *   Values to pass into attributes via offsetSet().
   * @param string $expected
   *   Expected attributes output.
   */
  private static function assertOffsetSetToString(array $values, $expected) {

    $attributes = new Attributes();
    $message = '(new Attributes())';

    foreach ($values as $k => $v) {
      /* @see \Drupal\atomium\Attributes::offsetSet() */
      $attributes[$k] = $v;
      $message .= "\n  ->offsetSet("
        . json_encode($k) . ', '
        . json_encode($v) . ')';
    }

    self::assertToString(
      $expected,
      $attributes,
      $message);
  }

  /**
   * Tests behavior with empty string values.
   */
  public function testEmptyStringValue() {

    self::assertToString(
      ' name=""',
      new Attributes(['name' => '']));

    $attributes = new Attributes();
    $attributes->append('name', '');
    $attributes->remove('name', '');
    // Empty attribute remains.
    self::assertToString(
      ' name=""',
      $attributes);
  }

  /**
   * Tests behavior for broken attribute names.
   *
   * Note that this is an incorrect use of this library.
   */
  public function testBrokenAttributeNames() {

    foreach ([
      'name ' => '',
      'name  ' => '',
      ' name' => '',
      '  name' => '',
      'na m  e' => '',
      'nam$e' => ' nam$e="value"',
      'nam"e' => '',
      '' => '',
      ' ' => '',
      '  ' => '',
    ] as $name => $expected) {

      self::assertToString(
        $expected,
        new Attributes([$name => 'value']),
        var_export($name, TRUE));
    }
  }

  /**
   * Tests behavior for broken attribute names.
   *
   * Note that this is an incorrect use of this library.
   */
  public function testBrokenAttributeNamesEnclosed() {

    foreach ([
      'name ' => ' a z',
      'name  ' => ' a z',
      ' name' => ' a z',
      '  name' => ' a z',
      'na m  e' => ' a z',
      'nam$e' => ' a nam$e="value" z',
      '' => ' a z',
      ' ' => ' a z',
      '  ' => ' a z',
    ] as $name => $expected) {

      self::assertToString(
        $expected,
        new Attributes(
          [
            'a' => TRUE,
            $name => 'value',
            'z' => TRUE,
          ]),
        var_export($name, TRUE));
    }
  }

  /**
   * Tests behavior for broken attribute names.
   *
   * Note that this is an incorrect use of this library.
   */
  public function testBrokenAttributeNamesBoolean() {

    foreach ([
      'name ' => '',
      'name  ' => '',
      ' name' => '',
      '  name' => '',
      'na m  e' => '',
      'nam$e' => ' nam$e',
      '' => '',
      ' ' => '',
      '  ' => '',
    ] as $name => $expected) {

      self::assertToString(
        $expected,
        new Attributes([$name => TRUE]),
        var_export($name, TRUE));
    }
  }

  /**
   * Tests behavior for broken attribute names.
   *
   * Note that this is an incorrect use of this library.
   */
  public function testBrokenAttributeNamesBooleanEnclosed() {

    foreach ([
      'name ' => ' a z',
      'name  ' => ' a z',
      ' name' => ' a z',
      '  name' => ' a z',
      'na m  e' => ' a z',
      'nam$e' => ' a nam$e z',
      '' => ' a z',
      ' ' => ' a z',
      '  ' => ' a z',
    ] as $name => $expected) {

      self::assertToString(
        $expected,
        new Attributes(['a' => TRUE, $name => TRUE, 'z' => TRUE]),
        var_export($name, TRUE));
    }
  }

  /**
   * Tests example attributes from a profiling case.
   */
  public function testExample() {

    // Line breaks make this string easier to read, and nicer in git diff.
    // If done like below, GrumPHP won't complain.
    $expected = str_replace("\n", '', '
 bool-false
 bool-false-array=""
 bool-true
 bool-true-array="1"
 float-array="1.1 1.2 1.3 1.4 1.5"
 float-nested-array="1.1 1.2 1.3 1.4 1.5"
 float="3.1415926535898"
 integer-array="0 1 2 3 4 5"
 integer-nested-array="0 1 2 3 4 5"
 integer="0"
 string-array-spaces="a   b   c   d   e"
 string-array="a b c d e f"
 string-nested-array="a b c d e f"
 string=" a b c d e f "');

    $attributes = new Attributes(
      [
        'bool-true' => TRUE,
        'bool-false' => FALSE,
        'bool-true-array' => [TRUE, TRUE, TRUE],
        'bool-false-array' => [FALSE, FALSE, FALSE],
        'integer' => 0,
        'integer-array' => [0, 1, 2, 3, 4, 5],
        'integer-nested-array' => [0, [1, [2, [3, [4, [5]]]]]],
        'float' => M_PI,
        'float-array' => [1.1, 1.2, 1.3, 1.4, 1.5],
        'float-nested-array' => [1.1, [1.2, [1.3, [1.4, [1.5]]]]],
        'string' => ' a b c d e f ',
        'string-array' => range('a', 'f'),
        'string-array-spaces' => ['a ', ' b ', ' c ', ' d ', ' e'],
        'string-nested-array' => ['a', ['b', ['c', ['d', ['e', ['f']]]]]],
      ]);

    self::assertToStringAdvanced(
      $expected,
      $attributes);
  }

  /**
   * Asserts that Attributes->toArray() has the expected value.
   *
   * @param array $expected
   *   Expected return value of toArray().
   * @param \Drupal\atomium\Attributes $attributes
   *   The attributes object.
   * @param string $message
   *   Message to send to self::assertSame().
   */
  private static function assertToArray(array $expected, Attributes $attributes, $message = '') {
    // Prevent any side effects.
    $attributes = clone $attributes;
    self::assertSame(
      Yaml::dump($expected, 9),
      Yaml::dump($attributes->toArray(), 9),
      $message . "\n  ->toArray()");
  }

  /**
   * Asserts that Attributes->__toString() has the expected value.
   *
   * @param string $expected
   *   Expected string value.
   * @param \Drupal\atomium\Attributes $attributes
   *   The attributes object.
   * @param string $message
   *   Message to send to self::assertSame().
   */
  private static function assertToString($expected, Attributes $attributes, $message = '') {
    // Prevent any side effects.
    $attributes = clone $attributes;
    self::assertSame(
      var_export($expected, TRUE),
      var_export($attributes->__toString(), TRUE),
      $message . "\n  ->__toString()");
  }

  /**
   * Asserts that Attributes->__toString() has the expected value.
   *
   * Strings are broken to multiple lines for readability.
   *
   * @param string $expected
   *   Expected string value.
   * @param \Drupal\atomium\Attributes $attributes
   *   The attributes object.
   * @param string $message
   *   Message to send to self::assertSame().
   */
  private static function assertToStringAdvanced($expected, Attributes $attributes, $message = '') {
    // Prevent any side effects.
    $attributes = clone $attributes;
    self::assertSame(
      self::formatAtributesString($expected),
      self::formatAtributesString($attributes->__toString()),
      $message . "\n  ->__toString()");
  }

  /**
   * Formats an attributes string as multi-line PHP expression.
   *
   * @param string $string
   *   The original attributes string.
   *
   * @return string
   *   The PHP expression.
   */
  private static function formatAtributesString($string) {
    $parts = explode(' ', $string);
    $out = "''";
    foreach ($parts as $part) {
      $out .= "\n . " . var_export($part, TRUE);
    }
    return $out;
  }

}
