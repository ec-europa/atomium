<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php foreach (\array_values($metadata) as $index => $attributes): ?>
  <span<?php print $atomium['attributes']['index-' . $index]->setAttributes($attributes); ?>></span>
<?php endforeach; ?>
