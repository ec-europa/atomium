<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']->append('class', 'admin-panel'); ?>>
  <?php if (!empty($block['title'])): ?>
      <h3><?php print $block['title']; ?></h3>
  <?php endif; ?>

  <?php if (!empty($block['content'])): ?>
      <div<?php print $atomium['attributes']['content']->append('class', 'body'); ?>><?php print render($block['content']); ?></div>
  <?php else: ?>
      <div<?php print $atomium['attributes']['description']->append('class', 'description'); ?>><?php print render($block['description']); ?></div>
  <?php endif; ?>
</div>
