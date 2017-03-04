<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="item-list">
  <?php if (isset($title) && $title !== ''):?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>

    <?php if (!empty($variables['items'])): ?>
      <<?php print $type; ?><?php print $attributes; ?>>
        <?php foreach ($variables['items'] as $item): ?>
            <?php print render($item); ?>
        <?php endforeach; ?>
      </<?php print $type; ?>>
    <?php endif; ?>
</div>
