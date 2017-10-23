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
  public function testMethods(array $given, array $run, array $expect) {
    $attributes = new Attributes($given);

    foreach ($run as $method => $arguments) {
      call_user_func_array(array($attributes, $method), $arguments);
    }

    foreach ($expect as $method => $item) {
      $item += array('arguments' => array());
      $actual = call_user_func_array(array($attributes, $method), $item['arguments']);
      expect($actual)->to->equal($item['return']);
    }
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
