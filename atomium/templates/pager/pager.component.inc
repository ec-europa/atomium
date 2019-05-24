<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager(array $existing, $type, $theme, $path) {
  return array(
    'pager' => array(
      'template' => 'pager',
      'variables' => array(
        'tags' => array(),
        'element' => 0,
        'parameters' => array(),
        'quantity' => 9,
        'interval' => 1,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager() {
  $GLOBALS['pager_page_array'] = array(
    0 => \mt_rand(0, 30),
  );
  $GLOBALS['pager_total'] = array(
    0 => 30,
  );

  return array(
    'label' => 'Pager',
    'description' => 'The pager',
    'preview' => array(),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_pager(array &$variables, $hook) {
  $element = $variables['element'];
  $interval = $variables['interval'];
  $quantity = $variables['quantity'];
  $tags = $variables['tags'];

  $items = array();

  $pager_page_array = \array_key_exists('pager_page_array', $GLOBALS) ?
    $GLOBALS['pager_page_array'] :
    array();
  $pager_total = \array_key_exists('pager_total', $GLOBALS) ?
    $GLOBALS['pager_total'] :
    array();

  $pager_page_array_element = NULL;

  if (\array_key_exists($element, $pager_page_array)) {
    $pager_page_array_element = (int) $pager_page_array[$element];
  }

  $pager_total_element = NULL;

  if (\array_key_exists($element, $pager_total)) {
    $pager_total_element = (int) $pager_total[$element];
  }

  $pager_items = _atomium_pager_generate_items(
    $variables,
    $pager_page_array,
    $pager_total_element
  );

  // The setting value is taken form te .info file.
  $pager_type_vanilla = (bool) current(
    atomium_get_settings('pager.use_vanilla')
  );

  if ($pager_type_vanilla === TRUE) {
    // Unhide some items to mimic the default Drupal's pager.
    $pager_items = _atomium_pager_generate_vanilla(
      $variables,
      $pager_items,
      $pager_page_array,
      $pager_total_element
    );
  }
  else {
    // Unhide all the items.
    foreach ($pager_items as &$item) {
      show($item['wrapper']);
    }
  }

  $item_list = array(
    '#theme' => _atomium_extend_theme_hook(
      'item_list',
      array($variables['theme_hook_original'])
    ),
    '#items' => $pager_items,
    '#attributes' => $variables['atomium']['attributes']['wrapper']
      ->append('class', 'pager')
      ->toArray(),
  );

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $item_list,
  );

  $GLOBALS['pager_total'] = $pager_total;
  $GLOBALS['pager_page_array'] = $pager_page_array;
}

/**
 * Generate necessary informations for generating a pager.
 *
 * @param array $variables
 *   The variables.
 * @param int $pager_page_array_element
 *   The pager page array element.
 * @param int $pager_total_element
 *   The pager total element.
 *
 * @return array
 *   The informations.
 */
function _atomium_pager_generate_infos(array $variables, $pager_page_array_element, $pager_total_element) {
  $quantity = $variables['quantity'];

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = (int) \ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array_element + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total_element;
  // End of marker calculations.
  // Prepare for generation loop.
  $i = $pager_first;

  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i += ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }

  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last += (1 - $i);
    $i = 1;
  }

  return array(
    'pager_middle' => $pager_middle,
    'pager_current' => $pager_current,
    'pager_first' => $pager_first,
    'pager_last' => $pager_last,
    'pager_max' => $pager_max,
    'i' => $i,
  );
}

/**
 * Custom function to generate pager items.
 *
 * Compute all the pager items, without filtering them.
 * By default, this items (build arrays) are hidden by default.
 * Pager items are:
 *  - Pager first (1)
 *  - Pager previous (1 or 0)
 *  - Pager ellipsis (1)
 *  - Pager links (many)
 *  - Pager ellipsis (1 or 0)
 *  - Pager next (1)
 *  - Pager last (1)
 *
 * @param array $variables
 *   The variables.
 * @param array $pager_page_array
 *   The pager page array.
 * @param int $pager_total_element
 *   The pager total element.
 *
 * @return array
 *   The items.
 */
function _atomium_pager_generate_items(array $variables, array $pager_page_array, $pager_total_element) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $pager_page_array_element = (int) $pager_page_array[$element];

  $pager_infos = _atomium_pager_generate_infos($variables, $pager_page_array_element, $pager_total_element);

  $pager_middle = $pager_infos['pager_middle'];
  $pager_current = $pager_infos['pager_current'];
  $pager_first = $pager_infos['pager_first'];
  $pager_last = $pager_infos['pager_last'];
  $pager_max = $pager_infos['pager_max'];
  $i = $pager_infos['i'];

  $items = array();

  // End of generation loop preparation.
  if ($pager_total_element <= 1) {
    return $items;
  }

  $items['pager_first'] = array(
    'pager_first' => array(
      '#theme' => _atomium_extend_theme_hook(
        'pager_first',
        array($variables['theme_hook_original'])
      ),
      '#text' => isset($tags[0]) ? $tags[0] : t('« first'),
      '#element' => $element,
    ),
    '#attributes' => array(
      'class' => array(
        'pager-first',
      ),
    ),
  );

  $items['pager_previous'] = array(
    'pager_previous' => array(
      '#theme' => _atomium_extend_theme_hook(
        'pager_previous',
        array($variables['theme_hook_original'])
      ),
      '#text' => isset($tags[1]) ? $tags[1] : t('‹ previous'),
      '#element' => $element,
    ),
    '#attributes' => array(
      'class' => array(
        'pager-previous',
      ),
    ),
  );

  // When there is more than one page, create the pager list.
  $items['pager_ellipsis__' . $i] = array(
    '#theme' => _atomium_extend_theme_hook(
      'pager_ellipsis',
      array($variables['theme_hook_original'])
    ),
    '#attributes' => array(
      'class' => array(
        'pager-ellipsis',
      ),
    ),
  );

  // Now generate the actual pager piece.
  for (; $i <= $pager_last && $i <= $pager_max; $i++) {
    $pager = pager_load_array(
      $pager_page_array_element + ($i - $pager_current),
      $element,
      $pager_page_array
    );

    $items['pager_link__' . $i] = array(
      'pager_link' => array(
        '#theme' => _atomium_extend_theme_hook(
          'pager_link',
          array($variables['theme_hook_original'])
        ),
        '#text' => $i,
        '#page_new' => $pager,
        '#element' => $element,
      ),
      '#attributes' => array(
        'class' => array(
          'pager-item',
        ),
      ),
    );

    if ($i === $pager_current) {
      $items['pager_current'] = array(
        '#markup' => $i,
        '#attributes' => array(
          'class' => array(
            'pager-current',
          ),
        ),
      );
    }
  }

  if ($i < $pager_max) {
    $items['pager_ellipsis__' . $i] = array(
      '#theme' => _atomium_extend_theme_hook(
        'pager_ellipsis',
        array($variables['theme_hook_original'])
      ),
      '#attributes' => array(
        'class' => array(
          'pager-ellipsis',
        ),
      ),
    );
  }

  // If the next page is the last page, mark the link as such.
  $items['pager_next'] = array(
    'pager_next' => array(
      '#theme' => _atomium_extend_theme_hook(
        'pager_next',
        array($variables['theme_hook_original'])
      ),
      '#text' => isset($tags[3]) ? $tags[3] : t('next ›'),
      '#element' => $element,
    ),
    '#attributes' => array(
      'class' => array(
        'pager-next',
      ),
    ),
  );

  $items['pager_last'] = array(
    'pager_last' => array(
      '#theme' => _atomium_extend_theme_hook(
        'pager_last',
        array($variables['theme_hook_original'])
      ),
      '#text' => isset($tags[4]) ? $tags[4] : t('last »'),
      '#element' => $element,
    ),
    '#attributes' => array(
      'class' => array(
        'pager-last',
      ),
    ),
  );

  $pager_items = array();
  foreach ($items as $key => $item) {
    $pager_item = array(
      '#theme_wrappers' => _atomium_extend_with_suggestions(
        array('html_tag'),
        array('item_list', $variables['theme_hook_original'], $key)
      ),
      '#tag' => 'li',
    );

    if (isset($item['link'])) {
      $pager_item['#attributes'] = $item['link']['#options']['attributes'];
      unset($pager_item['#attributes']['title']);
    }

  foreach ($items as &$item) {
    $item['pager_item']['#theme'] = _atomium_extend_theme_hook(
      $item['pager_item']['#theme'],
      $variables['theme_hook_original']
    );

    hide($pager_item['wrapper']);

    $pager_items[$key] = $pager_item;
  }

  return $pager_items;
}

/**
 * Custom function to generate vanilla pager items.
 *
 * @param array $variables
 *   The variables.
 * @param array $pager_items
 *   The pager items.
 * @param array $pager_page_array
 *   The pager page array.
 * @param int $pager_total_element
 *   The pager total element.
 *
 * @return array
 *   The items.
 */
function _atomium_pager_generate_vanilla(array $variables, array $pager_items, array $pager_page_array, $pager_total_element) {
  $element = $variables['element'];
  $pager_page_array_element = (int) $pager_page_array[$element];

  $pager_infos = _atomium_pager_generate_infos($variables, $pager_page_array_element, $pager_total_element);

  $pager_middle = $pager_infos['pager_middle'];
  $pager_current = $pager_infos['pager_current'];
  $pager_first = $pager_infos['pager_first'];
  $pager_last = $pager_infos['pager_last'];
  $pager_max = $pager_infos['pager_max'];
  $i = $pager_infos['i'];

  if ($pager_page_array_element > 0) {
    show($pager_items['pager_first']['wrapper']);
    show($pager_items['pager_previous']['wrapper']);
  }

  if ($i !== $pager_max) {
    if ($i > 1) {
      show($pager_items['pager_ellipsis__' . $i]['wrapper']);
    }

    for (; $i <= $pager_last && $i <= $pager_max; $i++) {
      if ($i < $pager_current || $i > $pager_current) {
        show($pager_items['pager_link__' . $i]['wrapper']);
      }

      if ($i === $pager_current) {
        show($pager_items['pager_current']['wrapper']);
      }
    }

    if ($i < $pager_max) {
      show($pager_items['pager_ellipsis__' . $i]['wrapper']);
    }
  }

  if ($pager_page_array_element < ($pager_total_element - 1)) {
    show($pager_items['pager_next']['wrapper']);
  }

  if ($pager_page_array_element < ($pager_total_element - 1)) {
    show($pager_items['pager_last']['wrapper']);
  }

  return $pager_items;
}
