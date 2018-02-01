<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_table() {
  return array(
    'table' => array(
      'template' => 'table',
      'variables' => array(
        'attributes' => array(),
        'caption' => NULL,
        'header' => array(),
        'colgroups' => array(),
        'rows' => array(),
        'footer' => array(),
        'sticky' => TRUE,
        'empty' => '',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_table(&$variables, $hook) {
  $header = $variables['header'];
  $rows = $variables['rows'];
  $sticky = $variables['sticky'];
  $empty = $variables['empty'];

  if (isset($variables['attributes'])) {
    $variables['atomium']['attributes']['wrapper']->merge($variables['attributes']);
  }

  // Allows to have multiple lines in the header.
  foreach ($variables['header'] as $item) {
    if (!is_array($item) || (is_array($item) && isset($item['data']))) {
      $header = $variables['header'] = array($variables['header']);
      break;
    }
  }

  // Add sticky headers, if applicable.
  if (count($header) && $sticky) {
    drupal_add_js('misc/tableheader.js');
    // Add 'sticky-enabled' class to the table to identify it for JS.
    // This is needed to target tables constructed by this function.
    $variables['atomium']['attributes']['wrapper']->append('class', 'sticky-enabled');
  }

  // Add the 'empty' row message if available.
  if (!count($rows) && $empty) {
    $header_count = 0;
    foreach ($header[0] as $header_cell) {
      if (is_array($header_cell)) {
        $header_count += isset($header_cell['colspan']) ? $header_cell['colspan'] : 1;
      }
      else {
        $header_count++;
      }
    }
    $variables['rows'][] = array(
      array(
        'data' => $empty,
        'colspan' => $header_count,
        'class' => array('empty', 'message'),
      ),
    );
  }

  $ts = count($header) ? tablesort_init($header[0]) : array();

  // Format the table colgroups row.
  $variables['colgroups'] = _atomium_table_format_rows('colgroup', array($variables['colgroups']), $header, $ts, FALSE, $variables);

  // Format the table header rows.
  $variables['header'] = _atomium_table_format_rows('header', $variables['header'], $header, $ts, TRUE, $variables);

  // Format the table footer rows.
  $variables['rows'] = _atomium_table_format_rows('body', $variables['rows'], $header, $ts, FALSE, $variables);

  // Format the table footer rows.
  $variables['footer'] = _atomium_table_format_rows('footer', $variables['footer'], $header, $ts, FALSE, $variables);
}

/**
 * Helper function that format table rows.
 *
 * @return array
 *   A proper render array of rows.
 */
function _atomium_table_format_rows($type, array $rows, $header, $ts, $is_header = FALSE, array &$variables = array()) {
  $rows_array = array();

  if (isset($header[0])) {
    $header = $header[0];
  }

  if (count($rows)) {
    $flip = array('even' => 'odd', 'odd' => 'even');
    $class = 'even';
    foreach ($rows as $rowid => $row) {
      // Check if we're dealing with a simple or complex row.
      if (isset($row['data'])) {
        $cells = $row['data'];
        $no_striping = isset($row['no_striping']) ? $row['no_striping'] : FALSE;

        // Set the attributes array and exclude 'data' and 'no_striping'.
        $attributes = $row;
        unset($attributes['data']);
        unset($attributes['no_striping']);
      }
      else {
        $cells = $row;
        $attributes = array();
        $no_striping = FALSE;
      }

      if (count($cells)) {
        // Add odd/even class.
        if (!$no_striping) {
          $class = $flip[$class];
          $attributes['class'][] = $class;
        }

        $variables['atomium']['attributes'][$type . '-row-' . $rowid]->merge($attributes);

        // Build row.
        $i = 0;

        foreach ($cells as $cellid => $cell) {
          if (TRUE == $is_header) {
            $cell = tablesort_header($cell, $header, $ts);
          }
          else {
            $cellid = $i;
            $cell = tablesort_cell($cell, $header, $ts, $i++);
          }

          // @todo: Check this part of code.
          $attributes_array = array();
          if (is_array($cell)) {
            $cell += array('data' => '');
            $attributes_array = array_diff_key($cell, array('data' => 'data', 'header' => 'header'));
            $cell = $cell['data'];
          }

          $variables['atomium']['attributes'][$type . '-cell-' . $rowid . '-' . $cellid] = $attributes_array;
          $rows_array['row-' . $rowid]['cells']['cell-' . $cellid] = $cell;
        }
      }
    }
  }

  return $rows_array;
}
