<?php

/**
 * @file
 * common.inc
 */

/**
 * Includes a theme file.
 *
 * @param string $theme
 *   Name of the theme to use for base path.
 * @param string $path
 *   Path relative to $theme.
 *
 * @return bool
 *   TRUE if file has been included, FALSE otherwise.
 */
function atomium_include($theme, $path) {
  static $themes = array();

  if (!isset($themes[$theme])) {
    $themes[$theme] = drupal_get_path('theme', $theme);
  }

  if ($themes[$theme] && ($file = DRUPAL_ROOT . '/' . $themes[$theme] . '/' . $path) && file_exists($file)) {
    if (is_dir($file)) {
      foreach (glob($file . '/*.{inc}', GLOB_BRACE) as $file_to_include) {
        include_once $file_to_include;
      }
    }
    if (is_file($file)) {
      include_once $file;
    }

    return TRUE;
  }

  return FALSE;
}

/**
 * Returns a list of base themes for active or provided theme.
 *
 * @param string $theme_key
 *   The machine name of the theme to check, if not set the active theme name
 *   will be used.
 * @param bool $include_theme_key
 *   Whether to append the returned list with $theme_key.
 *
 * @return array
 *   An indexed array of base themes.
 */
function _atomium_get_base_themes($theme_key = NULL, $include_theme_key = FALSE) {
  static $themes;
  if (!isset($theme_key)) {
    $theme_key = $GLOBALS['theme_key'];
  }
  if (!isset($themes[$theme_key])) {
    $themes[$theme_key] = array_unique(array_filter((array) atomium_get_theme_info($theme_key, 'base theme')));
  }
  if ($include_theme_key) {
    $themes[$theme_key][] = $theme_key;
  }
  return array_unique($themes[$theme_key]);
}

/**
 * Return information from the .info file of a theme (and possible base themes).
 *
 * @param string $theme_key
 *   The machine name of the theme.
 * @param string $key
 *   The key name of the item to return from the .info file. This value can
 *   include "][" to automatically attempt to traverse any arrays.
 * @param bool $base_themes
 *   Recursively search base themes, defaults to TRUE.
 *
 * @return string|array|false
 *   A string or array depending on the type of value and if a base theme also
 *   contains the same $key, FALSE if no $key is found.
 */
function atomium_get_theme_info($theme_key = NULL, $key = NULL, $base_themes = TRUE) {
  // If no $theme_key is given, use the current theme if we can determine it.
  if (!isset($theme_key)) {
    $theme_key = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : FALSE;
  }
  if ($theme_key) {
    $themes = list_themes();
    if (!empty($themes[$theme_key])) {
      $theme = $themes[$theme_key];
      // If a key name was specified, return just that array.
      if ($key) {
        $value = FALSE;
        // Recursively add base theme values.
        if ($base_themes && isset($theme->base_themes)) {
          foreach (array_keys($theme->base_themes) as $base_theme) {
            $value = atomium_get_theme_info($base_theme, $key);
          }
        }
        if (!empty($themes[$theme_key])) {
          $info = $themes[$theme_key]->info;
          // Allow array traversal.
          $keys = explode('][', $key);
          foreach ($keys as $parent) {
            if (isset($info[$parent])) {
              $info = $info[$parent];
            }
            else {
              $info = FALSE;
            }
          }
          if (is_array($value)) {
            if (!empty($info)) {
              if (!is_array($info)) {
                $info = array($info);
              }
              $value = drupal_array_merge_deep($value, $info);
            }
          }
          else {
            if (!empty($info)) {
              if (empty($value)) {
                $value = $info;
              }
              else {
                if (!is_array($value)) {
                  $value = array($value);
                }
                if (!is_array($info)) {
                  $info = array($info);
                }
                $value = drupal_array_merge_deep($value, $info);
              }
            }
          }
        }
        return $value;
      }
      // If no info $key was specified, just return the entire info array.
      return $theme->info;
    }
  }
  return FALSE;
}

/**
 * Retrieves an element's "attributes" array.
 *
 * @param array $element
 *   The individual renderable array element. It is possible to also pass the
 *   $variables parameter in [pre]process functions and it will logically
 *   determine the correct path to that particular theme hook's attribute array.
 *   Passed by reference.
 * @param string $property
 *   Determines which attributes array to retrieve. By default, this is the
 *   normal attributes, but can be "wrapper_attributes" or
 *   "input_group_attributes".
 *
 * @return array
 *   The attributes array. Passed by reference.
 */
function &_atomium_get_attributes(array &$element, $property = 'attributes') {
  // Attempt to retrieve a renderable element attributes first.
  if (
    isset($element['#type']) ||
    isset($element['#theme']) ||
    isset($element['#pre_render']) ||
    isset($element['#markup']) ||
    isset($element['#theme_wrappers']) ||
    isset($element["#$property"])
  ) {
    if (!isset($element["#$property"])) {
      $element["#$property"] = array();
    }
    return $element["#$property"];
  }
  // Treat $element as if it were a [pre]process function $variables parameter
  // and look for a renderable "element".
  elseif (isset($element['element'])) {
    if (!isset($element['element']["#$property"])) {
      $element['element']["#$property"] = array();
    }
    return $element['element']["#$property"];
  }

  // If all else fails, create (if needed) a default "attributes" array. This
  // will, at the very least, either work or cause an error that can be tracked.
  if (!isset($element[$property])) {
    $element[$property] = array();
  }

  return $element[$property];
}

/**
 * Copy of the drupal_attributes function.
 *
 * The only difference is that if a key is a numeric, it will only display the
 * value. Ex: 0="data-closable" will be displayed: data-closable.
 */
function atomium_drupal_attributes(array $attributes = array()) {
  foreach ($attributes as $attribute => &$data) {
    $data = array_map('trim', (array) $data);
    $data = array_filter($data);
    $value = implode(' ', $data);

    if (!is_numeric($attribute)) {
      $data = $attribute . '="' . check_plain($value) . '"';
    }
    else {
      $data = $value;
    }
  }

  return $attributes ? ' ' . implode(' ', $attributes) : '';
}

/**
 * Discover templates based on directory name.
 *
 * It is important that directories have the name of the hook for the moment.
 */
function atomium_find_templates() {
  $templates = array();

  foreach (_atomium_get_base_themes(NULL, TRUE) as $theme) {
    $path = drupal_get_path('theme', $theme) . '/templates';
    if (is_dir($path)) {
      $directories = array_diff(scandir($path), array('..', '.'));
      foreach ($directories as $directory) {
        $templates[$theme][$directory] = array(
          'theme' => $theme,
          'directory' => $path . '/' . $directory,
        );
      }
    }
  }

  return $templates;
}
