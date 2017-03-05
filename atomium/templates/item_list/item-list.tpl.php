<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
  <?php if (isset($title) && $title !== ''):?>
      <h3><?php print $title; ?></h3>
  <?php endif; ?>

  <?php if (!empty($variables['items'])): ?>
    <?php if ($type): ?>
      <<?php print $type; ?><?php print $attributes; ?>>
    <?php endif; ?>
    <?php foreach ($variables['items'] as $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
    <?php if ($type): ?>
      </<?php print $type; ?>>
    <?php endif; ?>
  <?php endif; ?>
</div>
