<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($primary): ?>
  <?php print render($primary); ?>
<?php endif; ?>
<?php if ($secondary): ?>
  <?php print render($secondary); ?>
<?php endif; ?>
