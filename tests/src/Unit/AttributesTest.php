<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\Attributes;
use Symfony\Component\Yaml\Yaml;

/**
 * Class AttributesTest.
 *
 * @package Drupal\Tests\atomium
 */
class AttributesTest extends AbstractUnitTest {

  /**
   * Test class methods.
   *
   * @dataProvider methodsProvider
   */
  public function testMethods(array $given, array $runs, array $expects) {
    $attributes = new Attributes($given);

    foreach ($runs as $run) {
      foreach ($run as $method => $arguments) {
        \call_user_func_array(array($attributes, $method), $arguments);
      }
    }

    foreach ($expects as $expect) {
      foreach ($expect as $method => $item) {
        $item += array('arguments' => array());

        $actual = \call_user_func_array(
          array($attributes, $method),
          $item['arguments']
        );

        self::assertEquals($item['return'], $actual);
      }
    }
  }

  /**
   * Test class methods.
   *
   * @covers Attributes::exists
   * @covers Attributes::contains
   */
  public function testVariousMethod() {
    $attributes = array(
      'class' => array(
        'foo',
        'bar',
      ),
      'id' => 'atomium',
      'data-closable' => FALSE,
    );

    $attributes = new Attributes($attributes);

    self::assertEquals(TRUE, $attributes->exists('class', 'foo'));
    self::assertEquals(FALSE, $attributes->exists('class', 'fooled'));
    self::assertEquals(FALSE, $attributes->exists('foo', 'bar'));
    self::assertEquals(FALSE, $attributes->exists('class', NULL));
    self::assertEquals(TRUE, $attributes->exists('id', 'atomium'));
    self::assertEquals(TRUE, $attributes->exists('data-closable', FALSE));
    self::assertEquals(TRUE, $attributes->exists('data-closable'));
    self::assertEquals(TRUE, $attributes->contains('class', 'fo'));
    self::assertEquals(FALSE, $attributes->contains('role'));
    self::assertEquals(TRUE, $attributes->contains('id', 'tomi'));
  }

  /**
   * Methods provider.
   *
   * @return array
   *   Test data.
   */
  public function methodsProvider() {
    return Yaml::parse(\file_get_contents(__DIR__ . '/../../fixtures/attributes/attributes.yml'));
  }

}
