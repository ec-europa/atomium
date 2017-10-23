<?php

/**
 * @file
 * Contains template file.
 */
?>
<form<?php print $atomium['attributes']['element']; ?>>
  <?php print render($element['#children']); ?>
</form>
