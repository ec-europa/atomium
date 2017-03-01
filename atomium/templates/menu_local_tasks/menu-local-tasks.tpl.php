<?php

/**
 * @file
 * menu-local-tasks.tpl.php
 */
?>
<?php if ($menu): ?>
    <ul<?php print $attributes; ?>><?php print render($menu); ?></ul>
<?php endif; ?>