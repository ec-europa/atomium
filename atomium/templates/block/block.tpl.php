<?php

/**
 * @file
 * Contains template file.
 */
?>
<section<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($title['#markup']): ?>
    <?php print render($title); ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php print render($content); ?>
</section>
