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
        // This is only for hook_atomium_definition_hook().
        'pager_page_array' => NULL,
        'pager_total' => NULL,
        'interval' => 1,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager() {
  return array(
    'label' => 'Pager',
    'description' => 'The pager',
    'preview' => array(
      'pager_page_array' => array(
        0 => \mt_rand(0, 30),
      ),
      'pager_total' => array(
        0 => 30,
      ),
    ),
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

  $pager_page_array = isset($GLOBALS['pager_page_array']) ?
    $GLOBALS['pager_page_array'] :
    array();
  $pager_total = isset($GLOBALS['pager_total']) ?
    $GLOBALS['pager_total'] :
    array();

  // This is for the hook_atomium_definition_hook() to work.
  if (isset($variables['pager_page_array']) && $variables['pager_page_array'] !== NULL) {
    $pager_page_array = $variables['pager_page_array'];
  }
  $pager_page_array_element = (int) $pager_page_array[$element];

  if (isset($variables['pager_total']) && $variables['pager_total'] !== NULL) {
    $pager_total = $variables['pager_total'];
  }
  $pager_total_element = (int) $pager_total[$element];

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

  // End of generation loop preparation.
  if ($pager_total_element <= 1) {
    return;
  }

  if ($pager_page_array_element > 0) {
    $items[] = array(
      'pager_item' => array(
        '#theme' => 'pager_first',
        '#text' => isset($tags[0]) ? $tags[0] : NULL,
        '#element' => $element,
      ),
      '#attributes' => array(
        'class' => array(
          'pager-first',
        ),
      ),
      '#pager_item_type' => 'pager_first',
      '#pager_page' => 0,
    );

    $page = pager_load_array(
      $pager_page_array[$element] - $interval,
      $element,
      $pager_page_array
    );

    $items[] = array(
      'pager_item' => array(
        '#theme' => 'pager_previous',
        '#interval' => $interval,
        '#text' => isset($tags[1]) ? $tags[1] : NULL,
        '#element' => $element,
      ),
      '#attributes' => array(
        'class' => array(
          'pager-previous',
        ),
      ),
      '#pager_item_type' => 'pager_previous',
      '#pager_page' => $page[$element],
    );
  }

  // When there is more than one page, create the pager list.
  if ($i !== $pager_max) {
    if ($i > 1) {
      $items[] = array(
        'pager_item' => array(
          '#theme' => 'pager_ellipsis',
        ),
        '#attributes' => array(
          'class' => array(
            'pager-ellipsis',
          ),
        ),
        '#pager_item_type' => 'pager_ellipsis',
      );
    }

    // Now generate the actual pager piece.
    for (; $i <= $pager_last && $i <= $pager_max; $i++) {
      if ($i < $pager_current || $i > $pager_current) {
        $pager = pager_load_array(
          $pager_page_array_element + ($i - $pager_current),
          $element,
          $pager_page_array
        );

        $page = isset($_GET['page']) ? $_GET['page'] : '';
        // Todo: See if this is really needed, maybe we can use the previous
        // pager variable.
        $pager_new = pager_load_array(
          $pager[$element],
          $element,
          explode(',', $page)
        );
        if (!empty($pager_new)) {
          $page = implode(',', $pager_new);
        }

        $items[] = array(
          'pager_item' => array(
            '#theme' => 'pager_link',
            '#text' => $i,
            '#page_new' => $pager,
            '#element' => $element,
          ),
          '#attributes' => array(
            'class' => array(
              'pager-item',
            ),
          ),
          '#pager_item_type' => 'pager_link',
          '#pager_page' => (int) $page,
        );
      }

      if ($i === $pager_current) {
        $items[] = array(
          'pager_item' => array(
            '#theme' => 'pager_current',
            '#text' => $i,
          ),
          '#attributes' => array(
            'class' => array(
              'pager-current',
            ),
          ),
          '#pager_item_type' => 'pager_current',
          '#pager_page' => $i - 1,
        );
      }
    }

    if ($i < $pager_max) {
      $items[] = array(
        'pager_item' => array(
          '#theme' => 'pager_ellipsis',
        ),
        '#attributes' => array(
          'class' => array(
            'pager-ellipsis',
          ),
        ),
        '#pager_item_type' => 'pager_ellipsis',
      );
    }
  }
  // End generation.
  // If we are anywhere but the last page.
  if ($pager_page_array_element < ($pager_total_element - 1)) {
    $pager = pager_load_array(
      $pager_page_array[$element] + $interval,
      $element,
      $pager_page_array
    );
    $page = isset($_GET['page']) ? $_GET['page'] : '';
    $pager_new = pager_load_array(
      $pager[$element],
      $element,
      explode(',', $page)
    );
    if (!empty($pager_new)) {
      $page = implode(',', $pager_new);
    }

    // If the next page is the last page, mark the link as such.
    $items[] = array(
      'pager_item' => array(
        '#theme' => 'pager_next',
        '#text' => isset($tags[3]) ? $tags[3] : NULL,
        '#element' => $element,
      ),
      '#attributes' => array(
        'class' => array(
          'pager-next',
        ),
      ),
      '#pager_item_type' => 'pager_next',
      '#pager_page' => $page,
    );
  }

  // If we are anywhere but the last page.
  if ($pager_page_array_element < ($pager_total_element - 1)) {
    $pager = pager_load_array($pager_total[$element] - 1, $element, $pager_page_array);

    $page = isset($_GET['page']) ? $_GET['page'] : '';
    $pager_new = pager_load_array(
      $pager[$element],
      $element,
      explode(',', $page)
    );
    if (!empty($pager_new)) {
      $page = implode(',', $pager_new);
    }

    $items[] = array(
      'pager_item' => array(
        '#theme' => 'pager_last',
        '#text' => isset($tags[4]) ? $tags[4] : NULL,
        '#element' => $element,
      ),
      '#attributes' => array(
        'class' => array(
          'pager-last',
        ),
      ),
      '#pager_item_type' => 'pager_last',
      '#pager_page' => (int) $page,
    );
  }

  foreach ($items as $key => &$item) {
    $item['pager_item']['#theme'] = _atomium_extend_theme_hook(
      $item['pager_item']['#theme'],
      $variables['theme_hook_original']
    );
  }

  $variables['atomium']['attributes']['wrapper']->append('class', 'pager');

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        array($variables['theme_hook_original'])
      ),
      '#items' => $items,
      '#attributes' => $variables['atomium']['attributes']['wrapper']
        ->toArray(),
    ),
  );

  $GLOBALS['pager_total'] = $pager_total;
  $GLOBALS['pager_page_array'] = $pager_page_array;
}
