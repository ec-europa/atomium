<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($primary): ?>
    <ul<?php print $primary_attributes; ?>>
      <?php print render($primary); ?>
    </ul>
<?php endif; ?>
<?php if ($secondary): ?>
    <ul<?php print $secondary_attributes; ?>>
      <?php print render($secondary); ?>
    </ul>
<?php endif; ?>
