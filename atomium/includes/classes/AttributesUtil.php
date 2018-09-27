<?php

namespace Drupal\atomium;

/**
 * Contains static methods related to attributes.
 */
class AttributesUtil {

  /**
   * List of known attribute names.
   */
  const ALLOWED_NAMES_MAP_INITIAL = [
    'accept' => TRUE,
    'accesskey' => TRUE,
    'action' => TRUE,
    'alt' => TRUE,
    'checked' => TRUE,
    'class' => TRUE,
    'cols' => TRUE,
    'contenteditable' => TRUE,
    'contextmenu' => TRUE,
    'dir' => TRUE,
    'draggable' => TRUE,
    'for' => TRUE,
    'hidden' => TRUE,
    'href' => TRUE,
    'id' => TRUE,
    'label' => TRUE,
    'lang' => TRUE,
    'name' => TRUE,
    'placeholder' => TRUE,
    'readonly' => TRUE,
    'size' => TRUE,
    'spellcheck' => TRUE,
    'src' => TRUE,
    'style' => TRUE,
    'tabindex' => TRUE,
    'target' => TRUE,
    'title' => TRUE,
    'type' => TRUE,
    'value' => TRUE,
    'width' => TRUE,
  ];

  /**
   * Map initialized with the most common attribute names.
   *
   * Additional names are added later.
   *
   * @var true[]
   */
  private static $validNamesMap = self::ALLOWED_NAMES_MAP_INITIAL;

  /**
   * Resets the internal cache of allowed attribute names.
   *
   * This method can be useful for profiling.
   */
  public static function resetAllowedNamesCache() {
    self::$validNamesMap = self::ALLOWED_NAMES_MAP_INITIAL;
  }

  /**
   * @param mixed[] $attributes
   *   Attribute values to check.
   *   Format: $[$name] = $raw_value_or_parts
   * @param bool $notice
   *   TRUE, to raise a notice if the attribute name is invalid.
   */
  public static function removeInvalidAttributeNames(array &$attributes, $notice = TRUE) {

    $invalid_names = [];
    foreach (array_diff_key($attributes, self::$validNamesMap) as $name => $value) {
      if (!self::unknownAttributeNameIsValid($name)) {
        $invalid_names[] = var_export($name, TRUE);
        unset($attributes[$name]);
      }
    }

    if ([] !== $invalid_names && $notice) {
      trigger_error(
        sprintf(
          'Invalid attribute names: %s',
          implode(', ', $invalid_names)));
    }
  }

  /**
   * Checks if an attribute name is valid, and raises a notice if not.
   *
   * @param string $name
   *   Attribute name to be checked.
   *
   * @return bool
   */
  public static function attributeNameIsValidOrNotice($name) {

    return isset(self::$validNamesMap[$name])
      || self::unknownAttributeNameIsValidOrNotice($name);
  }

  /**
   * Checks if an attribute name is valid, and raises a notice if not.
   *
   * @param string $name
   *   Attribute name to be checked.
   *
   * @return bool
   */
  private static function unknownAttributeNameIsValidOrNotice($name) {

    if (self::unknownAttributeNameIsValid($name)) {
      return TRUE;
    }

    trigger_error(
      sprintf(
        'Invalid attribute name %s.',
        var_export($name, TRUE)));

    return FALSE;
  }

  /**
   * Checks if an attribute name is valid.
   *
   * @param string $name
   *   Attribute name to be checked.
   *
   * @return bool
   */
  public static function attributeNameIsValid($name) {

    return isset(self::$validNamesMap[$name])
      || self::unknownAttributeNameIsValid($name);
  }

  /**
   * Checks if an attribute name is valid, that is not already in the map.
   *
   * @param string $name
   *   Attribute name to be checked.
   *
   * @return bool
   */
  private static function unknownAttributeNameIsValid($name) {

    if ('' === $name || preg_match('/[\t\n\f \/>"\'=]/', $name)) {
      return FALSE;
    }

    self::$validNamesMap[$name] = TRUE;
    return TRUE;
  }

}
