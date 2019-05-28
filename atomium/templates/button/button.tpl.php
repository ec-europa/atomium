<?php

/**
 * @file
 * Contains template file.
 */
?>
<button<?php print $atomium['attributes']['element']; ?>><?php print render($element['#value']); ?><?php print $element['#children']; ?></button>
