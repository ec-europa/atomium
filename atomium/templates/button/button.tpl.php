<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $attributes; ?>><?php print render($element['#value']); ?><?php print render($element['#children']); ?></button>
