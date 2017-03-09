<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
    <?php if (!empty($block['title'])): ?>
      <h3><?php print $block['title']; ?></h3>
    <?php endif; ?>

    <?php if (!empty($block['content'])): ?>
        <div<?php print $content_attributes; ?>><?php print render($block['content']); ?></div>
    <?php else: ?>
        <div<?php print $description_attributes; ?>><?php print render($block['description']); ?></div>
    <?php endif; ?>
</div>
