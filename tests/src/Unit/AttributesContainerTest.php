<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\AttributesContainer;

/**
 * Class AttributesContainerTest.
 *
 * @package Drupal\Tests\atomium
 */
class AttributesContainerTest extends AbstractUnitTest {

  /**
   * Test AttributesContainer class.
   */
  public function testAttributesContainer() {
    $attributesContainer = new AttributesContainer();

    self::assertInstanceOf('drupal\atomium\AttributesContainer', $attributesContainer);
  }

  /**
   * Test offsetGet().
   */
  public function testOffsetGet() {
    $container = new AttributesContainer();
    $container['foo'] = array('bar');
    expect($container->offsetGet('foo'))->to->be->instanceof('drupal\atomium\Attributes');
  }

  /**
   * Test offsetUnset().
   */
  public function testOffsetUnset() {
    $container = new AttributesContainer();
    $container['foo'] = array('class' => 'bar');
    expect($container->offsetGet('foo')['class'])->to->equal(array('bar'));

    unset($container['foo']);

    self::assertInstanceOf('drupal\atomium\Attributes', $container['foo']);
    self::assertEmpty($container['foo']->getStorage());
  }

  /**
   * Test AttributesContainer class.
   */
  public function testSetAttributes() {
    $attributesContainer = new AttributesContainer();
    $attributesContainer['attributes'] = array('class', 'example');

    self::assertInstanceOf('drupal\atomium\Attributes', $attributesContainer['attributes']);
  }

  /**
   * Test storage.
   */
  public function testStorage() {
    $container = new AttributesContainer();
    $container['foo'] = array('class' => 'bar');
    $container['bar'] = array('class' => 'foo');

    self::assertInstanceOf('drupal\atomium\Attributes', $container['foo']);
    self::assertInstanceOf('drupal\atomium\Attributes', $container['bar']);

    expect($container['foo']->toArray())->to->be->equal(array('class' => array('bar')));
    expect($container['bar']->toArray())->to->be->equal(array('class' => array('foo')));
  }

}
