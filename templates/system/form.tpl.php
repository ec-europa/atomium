<?php

/**
 * @file
 * form.tpl.php
 */
?>
<form<?php print $attributes; ?>>
  <?php print render($element['#children']); ?>
</form>
