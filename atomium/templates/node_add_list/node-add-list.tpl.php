<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!empty($content)): ?>
  <dl class="node-type-list">
    <?php foreach ($content as $item): ?>
      <dt><?php print render($item['link']); ?></dt>
      <dd><?php print $item['description']; ?></dd>
    <?php endforeach; ?>
  </dl>
<?php else: ?>
  <p>
    <?php print $message; ?>
  </p>
<?php endif; ?>
