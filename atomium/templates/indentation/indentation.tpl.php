<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php for ($n = 0; $n < $size; $n++): ?>
  <div<?php print $attributes; ?>><?php print $indentation; ?></div>
<?php endfor; ?>
