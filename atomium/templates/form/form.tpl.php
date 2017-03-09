<?php

/**
 * @file
 * Contains template file.
 */
?>
<form<?php print $attributes; ?>>
  <?php print render($element['#children']); ?>
</form>
