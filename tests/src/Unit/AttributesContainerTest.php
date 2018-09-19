<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\AttributesContainer;

/**
 * Class AttributesContainerTest.
 *
 * @package Drupal\Tests\atomium
 */
class AttributesContainerTest extends UnitTestBase {

  /**
   * Test AttributesContainer class.
   */
  public function testAttributesContainer() {
    $attributesContainer = new AttributesContainer();
    expect($attributesContainer)->to->be->instanceof('drupal\atomium\AttributesContainer');
  }

  /**
   * Test AttributesContainer class.
   */
  public function testSetAttributes() {
    $attributesContainer = new AttributesContainer();
    $attributesContainer['attributes'] = array('class', 'example');
    expect($attributesContainer['attributes'])->to->be->instanceof('drupal\atomium\Attributes');
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
    expect($container['foo'])->to->be->instanceof('drupal\atomium\Attributes');
    expect($container['foo']->getStorage())->to->be->empty();
  }

  /**
   * Test storage.
   */
  public function testStorage() {
    $container = new AttributesContainer();
    $container['foo'] = array('class' => 'bar');
    $container['bar'] = array('class' => 'foo');

    expect($container['foo'])->to->be->instanceof('drupal\atomium\Attributes');
    expect($container['bar'])->to->be->instanceof('drupal\atomium\Attributes');

    expect($container['foo']->toArray())->to->be->equal(array('class' => array('bar')));
    expect($container['bar']->toArray())->to->be->equal(array('class' => array('foo')));
  }

}
