<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($links): ?>
  <?php if (!empty($heading)): ?>
        <<?php print $heading['level']; ?><?php print $heading_attributes; ?>><?php print $heading['text']; ?></<?php print $heading['level']; ?>>
  <?php endif; ?>
  <?php print render($links); ?>
<?php endif; ?>
