<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']->append('class', 'admin'); ?>>
  <?php print render($variables['toggle_link']); ?>
    <div class="left">
      <?php foreach ($variables['container']['left'] as $index => $block): ?>
          <div<?php print $atomium['attributes']['left-block-' . $index]; ?>>
            <?php print render($block); ?>
          </div>
      <?php endforeach; ?>
    </div>
    <div class="right">
      <?php foreach ($variables['container']['right'] as $index => $block): ?>
          <div<?php print $atomium['attributes']['right-block-' . $index]; ?>>
            <?php print render($block); ?>
          </div>
      <?php endforeach; ?>
    </div>
</div>
