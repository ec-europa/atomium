<?php

/**
 * @file
 * html-tag.tpl.php
 */
?>
<<?php print $element['#tag'];?><?php print $attributes; ?>><?php print render($element['#value']); ?></<?php print $element['#tag']; ?>>
