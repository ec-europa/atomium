<?php

/**
 * @file
 * Contains template file.
 */
?>
<form<?php print $attributes; ?>>
    <div>
      <?php print render($element['#children']); ?>
    </div>
</form>
