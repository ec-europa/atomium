<?php

/**
 * @file
 * admin-block.tpl.php
 */
?>
<div<?php print $attributes; ?>>
    <?php if (!empty($block['title'])): ?>
      <h3><?php print $block['title']; ?></h3>
    <?php endif; ?>

    <?php if (!empty($block['content'])): ?>
        <div class="body"><?php print $block['content']; ?></div>
    <?php else: ?>
        <div class="description"><?php print $block['description']; ?></div>
    <?php endif; ?>
</div>
