<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if (!empty($block['title'])): ?>
      <h3><?php print $block['title']; ?></h3>
  <?php endif; ?>

  <?php if (!empty($block['content'])): ?>
      <div<?php print $atomium['attributes']['content']; ?>><?php print render($block['content']); ?></div>
  <?php else: ?>
      <div<?php print $atomium['attributes']['description']; ?>><?php print render($block['description']); ?></div>
  <?php endif; ?>
</div>
