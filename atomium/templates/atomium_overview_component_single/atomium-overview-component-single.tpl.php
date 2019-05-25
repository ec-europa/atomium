<?php

/**
 * @file
 * Contains template file.admin_block
 */
?>

<div>
  <?php foreach ($definitions as $name => $definition): ?>
      <fieldset>
          <legend><?php print t('Component @', array('@' => $definition['label'])) ?></legend>
          <div>
            <?php if (isset($definition['description'])): ?>
                <p><?php print $definition['description'] ?></p>
            <?php endif; ?>
            <?php if (isset($definition['preview'])): ?>
                <div class="clearfix">
                  <?php print render($definition['preview']) ?>
                </div>
            <?php endif; ?>
            <?php if (isset($definition['form'])): ?>
                <div class="clearfix">
                  <?php print render($definition['form']) ?>
                </div>
            <?php endif; ?>

          </div>
      </fieldset>
  <?php endforeach; ?>
</div>
