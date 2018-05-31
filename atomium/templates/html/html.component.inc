<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_html(array &$variables, $hook) {
  // Add variables and paths needed for HTML5 and responsive support.
  $variables['base_path'] = base_path();

  // Attributes for html element.
  $variables['atomium']['attributes']['html']->merge(array(
    'lang' => $variables['language']->language,
    'dir' => $variables['language']->dir,
  ));

  // Return early, so the maintenance page does not call any of the code below.
  if ('html' != $hook) {
    return;
  }

  // Serialize RDF Namespaces into an RDFa 1.1 prefix attribute.
  if ($variables['rdf_namespaces']) {
    $prefixes = array();
    foreach (explode("\n  ", ltrim($variables['rdf_namespaces'])) as $namespace) {
      // Remove xlmns: and ending quote and fix prefix formatting.
      $prefixes[] = str_replace('="', ': ', drupal_substr($namespace, 6, -1));
    }
    $variables['rdf_namespaces'] = implode(' ', $prefixes);
  }

  $variables['atomium']['attributes']['html']->append('prefix', $variables['rdf_namespaces']);

  // Classes for body element. Allows advanced theming based
  // on context (home page, node of certain type, etc.).
  if (!$variables['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each website section.
    list($section,) = explode('/', $path, 2);
    $arg = explode('/', $_GET['q']);
    if ($arg[0] == 'node' && isset($arg[1])) {
      if ($arg[1] == 'add') {
        $section = 'node-add';
      }
      elseif (isset($arg[2]) && is_numeric($arg[1]) && ($arg[2] == 'edit' || $arg[2] == 'delete')) {
        $section = 'node-' . $arg[2];
      }
    }
    $variables['classes_array'][] = 'section-' . $section;
  }

  // Store the menu item since it has some useful information.
  $variables['menu_item'] = menu_get_item();
  if ($variables['menu_item']) {
    switch ($variables['menu_item']['page_callback']) {
      case 'views_page':
        // Is this a Views page?
        $variables['classes_array'][] = 'page-views';
        break;

      case 'page_manager_blog':
      case 'page_manager_blog_user':
      case 'page_manager_contact_site':
      case 'page_manager_contact_user':
      case 'page_manager_node_add':
      case 'page_manager_node_edit':
      case 'page_manager_node_view_page':
      case 'page_manager_page_execute':
      case 'page_manager_poll':
      case 'page_manager_search_page':
      case 'page_manager_term_view_page':
      case 'page_manager_user_edit_page':
      case 'page_manager_user_view_page':
        // Is this a Panels page?
        $variables['classes_array'][] = 'page-panels';
        break;
    }
  }

  $headers = drupal_get_http_header();
  if (isset($headers['status'])) {
    $variables['classes_array'][] = "status-" . $headers['status'];
    if ($headers['status'] == '404 Not Found') {
      $variables['theme_hook_suggestions'][] = 'html__404';
    }
  }

  $variables['atomium']['attributes']['body']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['body']->remove('class', atomium_get_settings('preprocess.html.classes_to_remove', TRUE));
}

/**
 * Implements hook_process_hook().
 */
function atomium_process_html(array &$variables, $hook) {
  if (theme_get_setting('atomium_convert_inline_js_into_files')) {
    preg_match_all('/<script(?![^>]+src).*?>([\s\S]*?)<\/script>/s', $variables['scripts'], $matches, PREG_SET_ORDER);
    foreach ($matches as $match) {
      if ($newtag = _atomium_convert_js_inline_to_file($match[1], $variables, $hook)) {
        $variables['scripts'] = str_replace($match[0], $newtag, $variables['scripts']);
      }
    }
  }
}

/**
 * Custom callback.
 */
function _atomium_convert_js_inline_to_file($data, $variables, $hook) {
  $directory = "public://js";
  $path = $directory . '/' . sha1($data) . '.js';

  if (!is_dir($directory) || !is_writable($directory)) {
    if (file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    }
  }

  $query_string = REQUEST_TIME;

  $element = array(
    '#tag' => 'script',
    '#value' => '',
    '#attributes' => array(
      'type' => 'text/javascript',
    ),
  );

  if (file_exists($path)) {
    $element['#attributes']['src'] = file_create_url($path) . '?' . $query_string;
    return theme('html_tag', array('element' => $element));
  }

  if ($path = file_unmanaged_save_data($data, $path, FILE_EXISTS_REPLACE)) {
    $element['#attributes']['src'] = file_create_url($path) . '?' . $query_string;
    return theme('html_tag', array('element' => $element));
  }

  return FALSE;
}
