<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\Attributes;
use Symfony\Component\Yaml\Yaml;

/**
 * Class AttributesTest.
 *
 * @internal
 * @coversNothing
 */
final class AttributesTest extends AbstractUnitTest {

  /**
   * Methods provider.
   *
   * @return array
   *   Test data.
   */
  public function methodsProvider() {
    return Yaml::parse(\file_get_contents(__DIR__ . '/../../fixtures/attributes/attributes.yml'));
  }

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
   * @covers \Attributes::contains
   * @covers \Attributes::exists
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

    self::assertTrue($attributes->exists('class', 'foo'));
    self::assertFalse($attributes->exists('class', 'fooled'));
    self::assertFalse($attributes->exists('foo', 'bar'));
    self::assertFalse($attributes->exists('class', NULL));
    self::assertTrue($attributes->exists('id', 'atomium'));
    self::assertTrue($attributes->exists('data-closable', FALSE));
    self::assertTrue($attributes->exists('data-closable'));
    self::assertTrue($attributes->contains('class', 'fo'));
    self::assertFalse($attributes->contains('role'));
    self::assertTrue($attributes->contains('id', 'tomi'));
  }

}
