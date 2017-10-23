<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($mark): ?>
<span<?php print $atomium['attributes']['wrapper']; ?>><i class="fi-info"></i><?php print render($mark); ?></span>
<?php endif; ?>
