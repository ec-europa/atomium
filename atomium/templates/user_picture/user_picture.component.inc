<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_user_picture() {
  return array(
    'user_picture' => array(
      'template' => 'user-picture',
      'variables' => array(
        'account' => NULL,
        'user_picture' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 */
function atomium_preprocess_user_picture(array &$variables, $hook) {
  if (variable_get('user_pictures', 0)) {
    $account = $variables['account'];
    $filepath = NULL;

    if (!empty($account->picture)) {
      // @TODO: Ideally this function would only be passed file objects, but
      // since there's a lot of legacy code that JOINs the {users} table to
      // {node} or {comments} and passes the results into this function if we
      // a numeric value in the picture field we'll assume it's a file id
      // and load it for them. Once we've got user_load_multiple() and
      // comment_load_multiple() functions the user module will be able to load
      // the picture files in mass during the object's load process.
      if (\is_numeric($account->picture)) {
        $account->picture = file_load($account->picture);
      }
      if (!empty($account->picture->uri)) {
        $filepath = $account->picture->uri;
      }
    }
    elseif (variable_get('user_picture_default', '')) {
      $filepath = variable_get('user_picture_default', '');
    }

    if (NULL === $filepath) {
      $alt = t("@user's picture", array('@user' => format_username($account)));

      $variables[$variables['base_hook']] = array(
        '#path' => $filepath,
        '#title' => $alt,
        '#alt' => $alt,
      );

      // If the image does not have a valid Drupal scheme (for eg. HTTP),
      // don't load image styles.
      if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
        $variables[$variables['base_hook']] += array(
          '#theme' => _atomium_extend_theme_hook('image_style', $variables['theme_hook_original']),
          '#style_name' => $style,
          '#attributes' => $variables['atomium']['attributes']['image']->toArray(),
        );
      }
      else {
        $variables[$variables['base_hook']] += array(
          '#theme' => _atomium_extend_theme_hook('image', $variables['theme_hook_original']),
          '#attributes' => $variables['atomium']['attributes']['image']->toArray(),
        );
      }

      if (!empty($account->uid) && user_access('access user profiles')) {
        $variables[$variables['base_hook']] = array(
          $variables['base_hook'] => array(
            '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
            '#text' => $variables['user_picture'],
            '#path' => 'user/' . $account->uid,
            '#options' => array(
              'html' => TRUE,
              'attributes' => $variables['atomium']['attributes']['link']->append('title', t('View user profile.'))->toArray(),
            ),
          ),
        );
      }
    }
  }
}
