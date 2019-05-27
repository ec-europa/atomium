<?php

/**
 * @file
 * Contains template file.
 */
?>

<ul>
  <?php foreach ($definitions['#items'] as $name => $definition): ?>
      <li>
          <a href="#<?php print $definition['data']['#name']; ?>-preview"><?php print $definition['data']['#title']; ?></a>
      </li>
  <?php endforeach; ?>
</ul>

<h3><?php print t('Components'); ?></h3>

<div>
  <?php print render($definitions); ?>
</div>
