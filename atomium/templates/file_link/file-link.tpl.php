<?php

/**
 * @file
 * Contains template file.
 */
?>
<span<?php print $atomium['attributes']['wrapper']->append('class', 'file'); ?>>
  <?php print render($file_link['file_icon']); ?>
  <?php print render($file_link['file_link']); ?>
</span>
