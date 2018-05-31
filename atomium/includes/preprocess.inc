<?php

/**
 * @file
 * preprocess.inc
 */

use Drupal\Atomium\AttributesContainer;

/**
 * Implements hook_preprocess().
 */
function atomium_preprocess(array &$variables, $hook) {
  // Make sure the 'atomium' key is created.
  $variables += array(
    'atomium' => array(
      'attributes' => new AttributesContainer(),
    ),
  );

  // Make sure the 'attributes' key is created.
  $variables['atomium'] += array(
    'attributes' => new AttributesContainer(),
  );

  if (!($variables['atomium']['attributes'] instanceof AttributesContainer)) {
    $variables['atomium']['attributes'] = new AttributesContainer($variables['atomium']['attributes']);
  }

  $variables['base_hook'] = atomium_get_base_hook($hook);
}
