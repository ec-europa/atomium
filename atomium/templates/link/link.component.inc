<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_link(array $existing, $type, $theme, $path) {
  return array(
    'link' => array(
      'template' => 'link',
      'variables' => array(
        'text' => NULL,
        'path' => NULL,
        'options' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_link() {
  return array(
    'label' => 'Link',
    'description' => 'Link',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_link(array $form, array &$form_state) {
  $form['element1'] = array(
    '#type' => 'atomium_link',
    '#title' => 'Demo link',
    '#href' => '/',
  );

  $form['container'] = array(
    '#type' => 'container',
  );

  $form['element2'] = array(
    '#type' => 'atomium_link',
    '#title' => 'Demo active link',
    '#href' => current_path(),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_link(array &$variables, $hook) {
  if (isset($variables['options']['attributes'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['options']['attributes']);
  }

  // This cannot be moved to a #pre_render because some contrib modules
  // uses #theme => link instead of #type => link (see admin_menu).
  $startWithHash = (\strpos($variables['path'], '#') === 0);
  $startWithJavascript = (\strpos($variables['path'], 'javascript:') === 0);

  if (!($startWithHash || $startWithJavascript)) {
    $variables['path'] = url($variables['path'], $variables['options']);
  }

  $variables['atomium']['attributes']['element']
    ->setAttribute('href', $variables['path']);

  // The text property must be a string.
  $variables['text'] = $variables['options']['html'] ?
    $variables['text'] :
    check_plain($variables['text']);
}
