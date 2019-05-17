<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_status_report(array $existing, $type, $theme, $path) {
  return array(
    'status_report' => array(
      'render element' => 'element',
      'template' => 'status-report',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_status_report(array &$variables, $hook) {
  $requirements = $variables['requirements'];
  $rows = array();

  $severities = array(
    REQUIREMENT_INFO => array(
      'title' => t('Info'),
      'class' => 'info',
    ),
    REQUIREMENT_OK => array(
      'title' => t('OK'),
      'class' => 'ok',
    ),
    REQUIREMENT_WARNING => array(
      'title' => t('Warning'),
      'class' => 'warning',
    ),
    REQUIREMENT_ERROR => array(
      'title' => t('Error'),
      'class' => 'error',
    ),
  );

  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'system-status-report');

  foreach ($requirements as $requirement) {
    if (!empty($requirement['#type'])) {
      continue;
    }

    $severity = $severities[isset($requirement['severity']) ? (int) $requirement['severity'] : REQUIREMENT_OK];

    $requirement['value'] = isset($requirement['value']) ? $requirement['value'] : '';

    $cells = array();

    $cells[] = array(
      'data' => array(
        'container' => array(
          '#theme_wrappers' => array('container'),
          '#attributes' => array(
            'title' => $severity['title'],
          ),
          array(
            '#type' => 'html_tag',
            '#tag' => 'span',
            '#attributes' => array(
              'class' => array(
                'element-invisible',
              ),
            ),
            '#value' => $severity['title'],
          ),
        ),
      ),
      'class' => array(
        'status-icon',
      ),
    );

    $cells[] = array(
      'data' => $requirement['title'],
      'class' => array(
        'status-title',
      ),
    );

    $cells[] = array(
      'data' => $requirement['value'],
      'class' => array(
        'status-value',
      ),
    );

    $rows[] = array(
      'data' => $cells,
      'class' => array(
        $severity['class'],
      ),
    );

    if (!empty($requirement['description'])) {
      $requirement_description = array(
        'data' => $requirement['description'],
        'colspan' => 3,
        'class' => array(
          'status-description',
        ),
      );

      $rows[] = array(
        'data' => array(
          'description' => $requirement_description,
        ),
        'class' => array(
          $severity['class'],
        ),
      );
    }
  }

  $table = array(
    '#theme' => _atomium_extend_theme_hook(
      'table',
      array(
        $variables['theme_hook_original'],
      )
    ),
    '#rows' => $rows,
  );

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $table,
  );
}
