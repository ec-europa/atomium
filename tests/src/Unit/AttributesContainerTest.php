<?php

namespace Drupal\Tests\atomium\Unit;

use drupal\atomium\AttributesContainer;

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
    $container['foo'] = ['bar'];
    expect($container->offsetGet('foo'))->to->be->instanceof('drupal\atomium\Attributes');
  }

  /**
   * Test offsetUnset().
   */
  public function testOffsetUnset() {
    $container = new AttributesContainer();
    $container['foo'] = ['class' => 'bar'];
    expect($container->offsetGet('foo')['class'])->to->equal(['bar']);

    unset($container['foo']);
    expect($container['foo'])->to->be->instanceof('drupal\atomium\Attributes');
    expect($container['foo']->getStorage())->to->be->empty();
  }

  /**
   * Test storage.
   */
  public function testStorage() {
    $container = new AttributesContainer();
    $container['foo'] = ['class' => 'bar'];
    $container['bar'] = ['class' => 'foo'];

    expect($container['foo'])->to->be->instanceof('drupal\atomium\Attributes');
    expect($container['bar'])->to->be->instanceof('drupal\atomium\Attributes');

    expect($container['foo']->toArray())->to->be->equal(['class' => ['bar']]);
    expect($container['bar']->toArray())->to->be->equal(['class' => ['foo']]);
  }

}
