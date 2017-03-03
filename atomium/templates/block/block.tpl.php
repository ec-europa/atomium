<?php

/**
 * @file
 * Contains template file.
 */
?>
<section<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($block->title): ?>
    <h2<?php print $title_attributes; ?>><?php print $block->title ?></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <?php if ($content): ?>
    <div<?php print $content_attributes; ?>>
      <?php print render($content); ?>
    </div>
  <?php endif; ?>
</section>
