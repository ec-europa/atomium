<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php print $element['#prefix']; ?>
<<?php print $element['#tag']; ?><?php print $atomium_attributes; ?>><?php print $element['#children']; ?></<?php print $element['#tag']; ?>>
<?php print $element['#suffix']; ?>
