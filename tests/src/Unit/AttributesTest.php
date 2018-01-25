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
   * Methods provider.
   *
   * @return array
   *   Test data.
   */
  public function methodsProvider() {
    return Yaml::parse(file_get_contents(__DIR__ . '/../../fixtures/attributes_class.yml'));
  }

}
