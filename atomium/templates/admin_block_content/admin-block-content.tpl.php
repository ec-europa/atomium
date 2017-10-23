<?php

/**
 * @file
 * Contains template file.
 */
?>
<dl<?php print $atomium['attributes']['wrapper']; ?>>
  <?php foreach ($variables['content'] as $item): ?>
      <dt><?php print render($item['link']); ?></dt>
    <?php if (!$compact && isset($item['description'])): ?>
          <dd><?php print render($item['description']); ?></dd>
    <?php endif; ?>
  <?php endforeach; ?>
</dl>
