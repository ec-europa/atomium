<?php

namespace Drupal\Tests\atomium\Unit;

use Drupal\atomium\AttributesContainer;

/**
 * Class AttributesContainerTest.
 *
 * @internal
 * @coversNothing
 */
final class AttributesContainerTest extends AbstractUnitTest {

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

    self::assertInstanceOf('drupal\atomium\Attributes', $container->offsetGet('foo'));
  }

  /**
   * Test offsetUnset().
   */
  public function testOffsetUnset() {
    $container = new AttributesContainer();
    $container['foo'] = array('class' => 'bar');

    self::assertEquals(array('bar'), $container->offsetGet('foo')['class']);

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

    self::assertEquals(array('class' => array('bar')), $container['foo']->toArray());
    self::assertEquals(array('class' => array('foo')), $container['bar']->toArray());
  }

}
