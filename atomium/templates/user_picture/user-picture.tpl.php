<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($user_picture): ?>
  <div<?php print $atomium['attributes']['wrapper']->append('class', 'user-picture'); ?>>
    <?php print render($user_picture); ?>
  </div>
<?php endif; ?>
