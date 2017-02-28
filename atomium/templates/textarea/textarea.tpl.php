<?php

/**
 * @file
 * textarea.tpl.php
 */
?>
<div<?php print $wrapper_attributes; ?>>
  <textarea<?php print $attributes; ?>><?php print check_plain(render($element['#value'])); ?></textarea>
</div>
