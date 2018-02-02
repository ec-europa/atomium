<?php

namespace Drupal\Tests\atomium\Unit;

use drupal\atomium\Attributes;
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
        call_user_func_array([$attributes, $method], $arguments);
      }
    }

    foreach ($expects as $expect) {
      foreach ($expect as $method => $item) {
        $item += array('arguments' => array());

        $actual = call_user_func_array(
          array($attributes, $method),
          $item['arguments']
        );

        expect($actual)->to->equal($item['return']);
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

    expect($attributes->exists('class', 'foo'))->to->equal(TRUE);
    expect($attributes->exists('class', 'fooled'))->to->equal(FALSE);
    expect($attributes->exists('foo', 'bar'))->to->equal(FALSE);
    expect($attributes->exists('class', NULL))->to->equal(FALSE);
    expect($attributes->exists('id', 'atomium'))->to->equal(TRUE);
    expect($attributes->exists('data-closable', FALSE))->to->equal(TRUE);
    expect($attributes->exists('data-closable'))->to->equal(TRUE);

    expect($attributes->contains('class', 'fo'))->to->equal(TRUE);
    expect($attributes->contains('role'))->to->equal(FALSE);
    expect($attributes->contains('id', 'tomi'))->to->equal(TRUE);
  }

  /**
   * Methods provider.
   *
   * @return array
   *   Test data.
   */
  public function methodsProvider() {
    return Yaml::parse(file_get_contents(__DIR__ . '/../../fixtures/attributes_class.yml'));
  }

}
