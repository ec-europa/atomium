<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if($title): ?>
    <span<?php print $attributes; ?>><?php print render($title); ?></span>
<?php endif; ?>
