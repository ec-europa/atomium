<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\AttributesContainer;
use drupol\htmltag\Attributes\AttributesInterface;

/**
 * Class AttributesContainerTest.
 */
class AttributesContainerTest extends AbstractUnitTest {

  /**
   * Test AttributesContainer class.
   */
  public function testAttributesContainer() {
    $attributesContainer = new AttributesContainer();

    self::assertInstanceOf(AttributesContainer::class, $attributesContainer);
  }

  /**
   * Test offsetGet().
   */
  public function testOffsetGet() {
    $container = new AttributesContainer();
    $container['foo'] = array('bar');

    self::assertInstanceOf(AttributesInterface::class, $container->offsetGet('foo'));
  }

  /**
   * Test offsetUnset().
   */
  public function testOffsetUnset() {
    $container = new AttributesContainer();
    $container['foo'] = array('class' => 'bar');
    self::assertEquals(array('bar'), $container->offsetGet('foo')['class']->getValuesAsArray());

    unset($container['foo']);

    self::assertInstanceOf(AttributesInterface::class, $container['foo']);
    self::assertEmpty($container['foo']);
  }

  /**
   * Test AttributesContainer class.
   */
  public function testSetAttributes() {
    $attributesContainer = new AttributesContainer();
    $attributesContainer['attributes'] = array('class', 'example');

    self::assertInstanceOf(AttributesInterface::class, $attributesContainer['attributes']);
  }

  /**
   * Test storage.
   */
  public function testStorage() {
    $container = new AttributesContainer();
    $container['foo'] = array('class' => 'bar');
    $container['bar'] = array('class' => 'foo');

    self::assertInstanceOf(AttributesInterface::class, $container['foo']);
    self::assertInstanceOf(AttributesInterface::class, $container['bar']);

    self::assertEquals(array('class' => array('bar')), $container['foo']->getValuesAsArray());
    self::assertEquals(array('class' => array('foo')), $container['bar']->getValuesAsArray());
  }

}
