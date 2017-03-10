<?php

/**
 * @file
 * Contains predicate functions.
 */

namespace Drupal\Tests\atomium\predicate;

// @codingStandardsIgnoreStart
/**
 * Run containsArray predicate.
 *
 * @param mixed $needle
 *   Array needle.
 *
 * @return \Drupal\Tests\atomium\predicate\ContainsArray
 *   Predicate object.
 */
function containsArray($needle) {
  return new ContainsArray($needle);
}
// @codingStandardsIgnoreEnd
