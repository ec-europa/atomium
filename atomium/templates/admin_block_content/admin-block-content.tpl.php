<?php

/**
 * @file
 * Contains template file.
 */
?>
<dl<?php print $attributes; ?>>
    <?php foreach ($variables['content'] as $item): ?>
      <dt><?php print render($item['link']); ?></dt>
      <?php if (!$compact && isset($item['description'])): ?>
        <dd><?php print render($item['description']); ?></dd>
      <?php endif; ?>
    <?php endforeach; ?>
</dl>
