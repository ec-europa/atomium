<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_rdf_metadata(array $existing, $type, $theme, $path) {
  return array(
    'rdf_metadata' => array(
      'template' => 'rdf-metadata',
      'variables' => array(
        'metadata' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_rdf_metadata() {
  return array(
    'label' => 'RDF Metadata group',
    'description' => 'RDF Metadata group.',
    'dependencies' => array('rdf'),
    'preview' => array(
      'metadata' => array(
        array(
          'data-propertyA' => array(
            'property1',
            'property2',
          ),
        ),
        array(
          'data-propertyB' => array(
            'property3',
            'property4',
          ),
        ),
      ),
    ),
  );
}
