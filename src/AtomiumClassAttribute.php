<?php

namespace Drupal\atomium;

use drupol\htmltag\Attribute\AbstractAttribute;

/**
 * Class AtomiumClassAttribute.
 */
class AtomiumClassAttribute extends AbstractAttribute {

  /**
   * {@inheritdoc}
   */
  public function preprocess(array $values, array $context = array()) {
    // Trim values.
    $values = array_map('trim', $values);

    // Remove duplicated values.
    $values = array_unique($values);

    // Sort values.
    natcasesort($values);

    return $values;
  }

}
