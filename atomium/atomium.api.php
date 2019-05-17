<?php

/**
 * @file
 * API file of Atomium theme.
 */

/**
 * Register one or more Drupal element implementations.
 *
 * This function is a subfunction of the Drupal's hook_element_info() hook.
 * Its signature and the return values are identical.
 *
 * It must live in: [path_to_theme]/elements/[type]/[type].element.inc
 *
 * @see hook_theme()
 */
function hook_atomium_element_info_hook() {
  return array(
    'custom_element' => array(
      '#attributes' => array(),
      '#pre_render' => array(
        'drupal_pre_render_conditional_comments',
        'atomium_pre_render_tag',
        'atomium_pre_render_children',
        'atomium_pre_render_extend_theme_property',
      ),
      '#theme' => 'tag',
      '#type' => 'tag',
      '#tag' => NULL,
      '#theme_hook_suggestions_parts' => array(),
    ),
  );
}

/**
 * Register one or many Atomium component implementations.
 *
 * This function is a subfunction of the Drupal's hook_theme() hook.
 * Its signature and the return values are identical.
 *
 * It must live in: [path_to_theme]/templates/[hook]/[hook].component.inc
 *
 * @see hook_theme()
 */
function hook_atomium_theme_hook(&$existing, $type, $theme, $path) {
  return array(
    'my_custom_component' => array(
      'template' => 'my-custom-component',
      'variables' => array(
        'var1' => NULL,
        'var2' => array(),
        'var3' => 'div',
      ),
    ),
  );
}

/**
 * Allows you to define a preview in the /atomium-overview page.
 *
 * If your components (hook_theme) has variables, you may define them
 * under the 'preview' key.
 *
 * It must live in: [path_to_theme]/templates/[hook]/[hook].component.inc.
 * 'disable': Set to TRUE to disable the preview.
 */
function hook_atomium_definition_hook() {
  return array(
    'label' => 'My component name',
    'description' => 'My component description.',
    'preview' => array(
      'text' => 'Random example of hook_theme variable',
    ),
  );
}

/**
 * Allows you to define a preview using a form in the /atomium-overview page.
 *
 * It must live in: [path_to_theme]/templates/[hook]/[hook].component.inc.
 *
 * @return array
 *   The Drupal form.
 */
function hook_atomium_definition_form_hook($form, &$form_state) {
  $form['component'] = array(
    '#theme' => array('username'),
    '#account' => user_load(1),
  );

  return $form;
}
