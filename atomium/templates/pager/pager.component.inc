<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager() {
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
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_pager(&$variables, $hook) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $quantity = $variables['quantity'];
  $items = array();
  global $pager_page_array, $pager_total;

  // This is for the hook_atomium_definition_hook() to work.
  if (isset($variables['pager_page_array']) && !is_null($variables['pager_page_array'])) {
    $pager_page_array = $variables['pager_page_array'];
  }
  if (isset($variables['pager_total']) && !is_null($variables['pager_total'])) {
    $pager_total = $variables['pager_total'];
  }

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];
  /* End of marker calculations. */

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  /* End of generation loop preparation. */

  if ($pager_total[$element] > 1) {
    if ($pager_page_array[$element] > 0) {
      $options = array(
        'title' => t('Go to first page'),
        'attributes' => array(
          'class' => array(
            'pager-first',
          ),
        ),
      );
      $items['pager_first'] = _atomium_pager_item_to_link_helper((isset($tags[0]) ? $tags[0] : t('« first')), array(0 => 0), $element, $options, $variables);

      // If we are anywhere but the first page.
      $pager = pager_load_array($pager_page_array[$element] - 1, $element, $pager_page_array);
      // If the previous page is the first page, mark the link as such.
      if ($pager[$element] == 0) {
        $pager = array(0 => 0);
      }
      $options = array(
        'title' => t('Go to previous page'),
        'attributes' => array(
          'class' => array(
            'pager-previous',
          ),
        ),
      );
      $items['pager_previous'] = _atomium_pager_item_to_link_helper((isset($tags[1]) ? $tags[1] : t('‹ previous')), $pager, $element, $options, $variables);
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items['pager_ellipsis__' . $i] = array(
          '#theme' => _atomium_extend_theme_hook('pager_ellipsis', $variables['theme_hook_original']),
          '#attributes' => array(
            'class' => array(
              'pager-ellipsis',
            ),
          ),
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current || $i > $pager_current) {
          $options = array(
            'attributes' => array(
              'title' => t('Go to page @number', array('@number' => $i)),
              'class' => array(
                'pager-link',
              ),
            ),
          );
          $pager = pager_load_array($pager_page_array[$element] + ($i - $pager_current), $element, $pager_page_array);
          $items['pager_link__' . $i] = _atomium_pager_item_to_link_helper($i, $pager, $element, $options, $variables);
        }

        if ($i == $pager_current) {
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
          '#theme' => _atomium_extend_theme_hook('pager_ellipsis', $variables['theme_hook_original']),
          '#attributes' => array(
            'class' => array(
              'pager-ellipsis',
            ),
          ),
        );
      }
    }
    // End generation.
    // If we are anywhere but the last page.
    if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
      // If the next page is the last page, mark the link as such.
      $options = array(
        'title' => t('Go to next page'),
        'attributes' => array(
          'class' => array(
            'pager-next',
          ),
        ),
      );
      $pager = pager_load_array($pager_page_array[$element] + 1, $element, $pager_page_array);
      $items['pager_next'] = _atomium_pager_item_to_link_helper((isset($tags[3]) ? $tags[3] : t('next ›')), $pager, $element, $options, $variables);
    }

    // If we are anywhere but the last page.
    if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
      $options = array(
        'title' => t('Go to last page'),
        'attributes' => array(
          'class' => array(
            'pager-last',
          ),
        ),
      );
      $pager = pager_load_array($pager_total[$element] - 1, $element, $pager_page_array);
      $items['pager_last'] = _atomium_pager_item_to_link_helper((isset($tags[4]) ? $tags[4] : t('last »')), $pager, $element, $options, $variables);
    }

    foreach ($items as $key => &$item) {
      $item['#theme_wrappers'] = _atomium_extend_with_suggestions(
        array('html_tag'),
        array('item_list', $variables['theme_hook_original'], $key)
      );
      $item['#tag'] = 'li';
      if (isset($item['link'])) {
        $item['#attributes'] = $item['link']['#options']['attributes'];
        unset($item['#attributes']['title']);
      }
    }

    $variables['atomium']['attributes']['wrapper']->append('class', 'pager');

    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => array(
        '#theme' => _atomium_extend_theme_hook('item_list', $variables['theme_hook_original']),
        '#items' => $items,
        '#attributes' => $variables['atomium']['attributes']['wrapper']->toArray(),
      ),
    );
  }
}

/**
 * Helper for the pager.
 */
function _atomium_pager_item_to_link_helper($text = NULL, $pager = NULL, $element = 0, $options = array(), $variables = array()) {
  $options += array('query' => NULL, 'attributes' => array());
  $options['query'] = drupal_get_query_parameters($options['query'], array('q', 'page'));

  if ($query_pager = pager_get_query_parameters()) {
    $options['query'] = array_merge($options['query'], $query_pager);
  }

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if (!is_null($element)) {
    if ($new_page = implode(',', pager_load_array($pager[$element], $element, explode(',', $page)))) {
      $options['query']['page'] = $new_page;
    }
  }

  return array(
    'link' => array(
      '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
      '#text' => check_plain($text),
      '#path' => $_GET['q'],
      '#options' => $options,
    ),
  );
}
