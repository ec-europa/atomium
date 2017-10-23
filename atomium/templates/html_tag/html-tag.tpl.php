<?php

/**
 * @file
 * Contains template file.
 */
?>
<<?php print $element['#tag']; ?><?php print $atomium['attributes']['element']; ?>><?php print render($element['#value']); ?><?php print render($element['#children']); ?></<?php print $element['#tag']; ?>>
