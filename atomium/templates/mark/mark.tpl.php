<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($mark): ?>
    <span<?php print $atomium['attributes']['wrapper']; ?>><?php print render($mark); ?></span>
<?php endif; ?>
