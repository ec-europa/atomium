<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($content): ?>
  <div<?php print $atomium['attributes']['wrapper']->append('class', 'region'); ?>>
    <?php print $content; ?>
  </div>
<?php endif; ?>
