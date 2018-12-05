<?php

/**
 * @file
 * Contains template file.
 */
?>
<aside<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if ('forum' != $node->type): ?>
      <h2><?php print t('Comments'); ?></h2>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
      <h3><?php print t('Add new comment'); ?></h3>
    <?php print render($content['comment_form']); ?>
  <?php endif; ?>
</aside>
