<?php

/**
 * @file
 * Contains template file.
 */
?>
<div id="progress" class="progress">
    <div class="bar"><div class="filled" style="width: <?php print $variables['percent']; ?>%"></div></div>
    <div class="percentage"><?php print $variables['percent']; ?></div>';
    <div class="message"><?php print render($variables['message']); ?></div>
</div>
