<?php

/**
 * @file
 * Contains template file.
 */
?>
<section<?php print $atomium['attributes']['wrapper']; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($title['#markup']): ?>
      <h2<?php print $atomium['attributes']['subject']->append(
  'class',
  'title'
); ?>><?php print render($title); ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
    <div<?php print $atomium['attributes']['content']->append(
  'class',
  'block-content'
); ?>>
      <?php print render($content); ?>
    </div>
</section>
