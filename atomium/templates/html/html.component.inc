<?php

/**
 * @file
 * Html.theme.inc.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_html(&$variables, $hook) {
  // Add variables and paths needed for HTML5 and responsive support.
  $variables['base_path'] = base_path();

  // Attributes for html element.
  $variables['html_attributes_array'] = array(
    'lang' => $variables['language']->language,
    'dir' => $variables['language']->dir,
  );

  // Return early, so the maintenance page does not call any of the code below.
  if ('html' != $hook) {
    return;
  }

  // Serialize RDF Namespaces into an RDFa 1.1 prefix attribute.
  if ($variables['rdf_namespaces']) {
    $prefixes = array();
    foreach (explode("\n  ", ltrim($variables['rdf_namespaces'])) as $namespace) {
      // Remove xlmns: and ending quote and fix prefix formatting.
      $prefixes[] = str_replace('="', ': ', substr($namespace, 6, -1));
    }
    $variables['rdf_namespaces'] = implode(' ', $prefixes);
  }

  $variables['html_attributes_array']['prefix'] = $variables['rdf_namespaces'];

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
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

  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('html')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('not-front')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('front')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('logged-in')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('not-logged-in')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('two-sidebars')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('one-sidebar sidebar-first')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('one-sidebar sidebar-second')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('no-sidebars')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('toolbar')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('toolbar-drawer')));
  $variables['classes_array'] = preg_grep('/^page-node/', $variables['classes_array'], PREG_GREP_INVERT);
  $variables['classes_array'] = preg_grep('/^node-type/', $variables['classes_array'], PREG_GREP_INVERT);
  $path_all = drupal_get_path_alias($_GET['q']);
  $variables['classes_array'][] = 'path-' . $path_all;
  $path = explode('/', $_SERVER['REQUEST_URI']);
  if ($path['1']) {
    $variables['classes_array'][] = 'pathone-' . $path['1'];
  }

  $headers = drupal_get_http_header();
  if (isset($headers['status'])) {
    $variables['classes_array'][] = "status-" . $headers['status'];
    if ($headers['status'] == '404 Not Found') {
      $variables['theme_hook_suggestions'][] = 'html__404';
    }
  }

  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
}
