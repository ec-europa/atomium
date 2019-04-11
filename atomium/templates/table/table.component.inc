<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_table(array $existing, $type, $theme, $path) {
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
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_table() {
  return array(
    'label' => 'Table',
    'description' => 'Table description.',
    'disable' => TRUE,
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_table(array $form, array &$form_state) {
  $form['element1'] = array(
    '#theme' => 'table',
    '#caption' => 'Default simple table.',
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
    ),
    '#sticky' => FALSE,
  );

  $form['element2'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with empty heading',
    '#header' => array(
      array('', 'header cell 1.2', 'header cell 1.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
    ),
    '#sticky' => FALSE,
  );

  $form['element3'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan #1.',
    '#header' => array(
      array(
        array(
          'data' => 'header cell 1.1',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.3',
          'colspan' => '3',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element4'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan #2.',
    '#header' => array(
      array(
        array(
          'data' => 'header cell 1.1',
          'colspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.3',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.4',
          'rowspan' => '2',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element5'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan #3.',
    '#header' => array(
      array(
        array(
          'data' => 'header cell 1.1',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'colspan' => '2',
        ),
        array(
          'data' => 'header cell 1.3',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.4',
          'rowspan' => '2',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element6'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with colspan and empty heading.',
    '#header' => array(
      array(
        array(
          'data' => '',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.1',
          'rowspan' => '2',
        ),
        array(
          'data' => 'header cell 1.2',
          'colspan' => '3',
        ),
      ),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array(
        'body cell 1.1', 'body cell 1.2', 'body cell 1.3', 'body cell 1.4',
        'body cell 1.5',
      ),
      array(
        'body cell 2.1', 'body cell 2.2', 'body cell 2.3', 'body cell 2.4',
        'body cell 2.5',
      ),
      array(
        'body cell 3.1', 'body cell 3.2', 'body cell 3.3', 'body cell 3.4',
        'body cell 3.5',
      ),
    ),
    '#footer' => array(
      array(
        'footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3',
        'footer cell 1.4', 'footer cell 1.5',
      ),
    ),
    '#sticky' => FALSE,
  );

  $form['element7'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with sticky enabled.',
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
      array('footer cell 2.1', 'footer cell 2.2', 'footer cell 2.3'),
    ),
  );

  $form['element8'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with a colgroup and a single col element.',
    '#colgroups' => array(
      array(
        array(
          'style' => 'background-color: red;',
        ),
      ),
    ),
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
      array('footer cell 2.1', 'footer cell 2.2', 'footer cell 2.3'),
    ),
  );

  $form['element9'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with a colgroup and a multiple col elements.',
    '#colgroups' => array(
      array(
        'data' => array(
          array(
            'style' => 'background-color: red;',
          ),
          array(),
          array(
            'style' => 'background-color: green;',
          ),
        ),
        'class' => 'jazzy',
      ),
    ),
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
      array('footer cell 2.1', 'footer cell 2.2', 'footer cell 2.3'),
    ),
  );

  $form['element10'] = array(
    '#theme' => 'table',
    '#caption' => 'Table with multiple colgroups and a multiple col elements.',
    '#colgroups' => array(
      array(
        'data' => array(
          array(
            'style' => 'background-color: green;',
          ),
          array(
            'style' => 'background-color: white;',
          ),
        ),
        'class' => 'bar',
      ),
      array(
        'data' => array(
          array(
            'style' => 'background-color: red;',
          ),
        ),
        'class' => 'foo',
      ),
    ),
    '#header' => array(
      array('header cell 1.1', 'header cell 1.2', 'header cell 1.3'),
      array('header cell 2.1', 'header cell 2.2', 'header cell 2.3'),
    ),
    '#rows' => array(
      array('body cell 1.1', 'body cell 1.2', 'body cell 1.3'),
      array('body cell 2.1', 'body cell 2.2', 'body cell 2.3'),
      array('body cell 3.1', 'body cell 3.2', 'body cell 3.3'),
    ),
    '#footer' => array(
      array('footer cell 1.1', 'footer cell 1.2', 'footer cell 1.3'),
      array('footer cell 2.1', 'footer cell 2.2', 'footer cell 2.3'),
    ),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function atomium_preprocess_table(array &$variables, $hook) {
  $header = $variables['header'];
  $rows = $variables['rows'];
  $sticky = $variables['sticky'];
  $empty = $variables['empty'];

  if (isset($variables['attributes'])) {
    $variables['atomium']['attributes']['wrapper']
      ->merge($variables['attributes']);
  }

  // Allows to have multiple lines in the header.
  foreach ($variables['header'] as $item) {
    if (!\is_array($item) || (\is_array($item) && isset($item['data']))) {
      $header = $variables['header'] = array($variables['header']);

      break;
    }
  }

  // Add sticky headers, if applicable.
  if ($sticky === TRUE && \is_array($header) && \count($header) !== 0) {
    drupal_add_js('misc/tableheader.js');
    // Add 'sticky-enabled' class to the table to identify it for JS.
    // This is needed to target tables constructed by this function.
    $variables['atomium']['attributes']['wrapper']
      ->append('class', 'sticky-enabled');
  }

  // Add the 'empty' row message if available.
  if (empty($rows) && !empty($empty)) {
    $header_count = 0;
    foreach ($header[0] as $header_cell) {
      if (\is_array($header_cell)) {
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

  $ts = !empty($header) ? tablesort_init($header[0]) : array();

  // Format the table colgroups row.
  $variables['colgroups'] = _atomium_table_format_rows(
    'colgroups',
    $variables['colgroups'],
    $header,
    $ts,
    FALSE,
    $variables
  );

  // Format the table header rows.
  $variables['header'] = _atomium_table_format_rows(
    'header',
    $variables['header'],
    $header,
    $ts,
    TRUE,
    $variables
  );

  // Format the table footer rows.
  $variables['rows'] = _atomium_table_format_rows(
    'rows',
    $variables['rows'],
    $header,
    $ts,
    FALSE,
    $variables
  );

  // Format the table footer rows.
  $variables['footer'] = _atomium_table_format_rows(
    'footer',
    $variables['footer'],
    $header,
    $ts,
    FALSE,
    $variables
  );
}

/**
 * Helper function that format table rows.
 *
 * @param string $type
 *   Type.
 * @param array $rows
 *   Rows.
 * @param array $header
 *   Header.
 * @param array $ts
 *   Table sort.
 * @param bool $is_header
 *   Is header?
 * @param array $variables
 *   Variables.
 *
 * @return array
 *   A proper render array of rows.
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function _atomium_table_format_rows($type, array $rows, array $header, array $ts, $is_header = FALSE, array &$variables = array()) {
  $rows_array = array();

  if (empty($rows)) {
    return $rows_array;
  }

  $header = isset($header[0]) ?
    $header[0] :
    array();

  // We will need this map later when adding classes to the row.
  $type_map = array(
    'header' => 'thead',
    'rows' => 'tbody',
    'footer' => 'tfoot',
    'colgroups' => 'colgroup',
  );

  $flip = array('even' => 'odd', 'odd' => 'even');
  $class = 'even';
  $rows_count = count($rows);
  $rows_indexed_by_int = array_values($rows);

  for ($j = 0; $j < $rows_count; $j++) {
    $row = $rows_indexed_by_int[$j];
    $attributes = array();

    // Check if we're dealing with a simple or complex row.
    if (isset($row['data']) && !empty($row['data'])) {
      $cells = $row['data'];
      $no_striping = isset($row['no_striping']) ? $row['no_striping'] : FALSE;
      $attributes = $row;
    }
    else {
      $cells = $row;
      $no_striping = FALSE;
    }

    // Remove any value that has a numeric key.
    $attributes = array_filter(
      $attributes,
      function ($key) {
        return !is_numeric($key);
      },
      ARRAY_FILTER_USE_KEY
    );

    // Add odd/even class.
    if (!$no_striping) {
      $class = $flip[$class];
      $attributes += array('class' => array());
      $attributes['class'] = (array) $attributes['class'];
      $attributes['class'][] = $class;
    }

    $variables['atomium']['attributes'][$type . '-row-' . $j]
      ->merge($attributes)
      ->delete('data')
      ->delete('no_stripping')
      ->append('class', 'row-type-' . $type_map[$type]);

    if (!\is_array($cells)) {
      continue;
    }

    if (empty($cells)) {
      continue;
    }

    // Process cells.
    $i = 0;
    foreach ($cells as $index => $cell) {
      if ($is_header === TRUE) {
        $cells[$index] = tablesort_header($cell, $header, $ts);
      }
      else {
        $cells[$index] = tablesort_cell($cell, $header, $ts, $i++);
      }
    }

    // Build cells and their attributes.
    $i = 0;
    foreach ($cells as $cell) {
      $attributes_array = array();

      if (\is_array($cell)) {
        $cell += array('data' => NULL);
        $attributes_array = $cell;
        $cell = $cell['data'];
      }

      $variables['atomium']['attributes'][$type . '-cell-' . $j . '-' . $i]
        ->merge($attributes_array)
        ->delete('data')
        ->delete('header');

      $rows_array['row-' . $j]['cells']['cell-' . $i] = $cell;
      $i++;
    }
  }

  return $rows_array;
}
