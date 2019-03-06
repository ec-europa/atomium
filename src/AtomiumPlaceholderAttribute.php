<?php

namespace Drupal\atomium;

use drupol\htmltag\Attribute\AbstractAttribute;

/**
 * Class AtomiumPlaceholderAttribute.
 */
class AtomiumPlaceholderAttribute extends AbstractAttribute {

  /**
   * {@inheritdoc}
   */
  public function preprocess(array $values, array $context = array()) {
    return array_map('strip_tags', $values);
  }

}
