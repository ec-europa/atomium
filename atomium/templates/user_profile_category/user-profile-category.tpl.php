<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($title): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<dl<?php print $atomium['attributes']['wrapper']; ?>>
  <?php print $profile_items; ?>
</dl>
