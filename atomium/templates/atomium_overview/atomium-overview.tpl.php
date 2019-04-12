<?php

/**
 * @file
 * Contains template file.
 */
?>

<ul>
  <?php foreach ($definitions as $name => $definition): ?>
      <li>
          <a href="#<?php print $name ?>-preview"><?php print $definition['label'] ?></a>
      </li>
  <?php endforeach; ?>
</ul>

<h3><?php print t('Components') ?></h3>

<div>
  <?php foreach ($definitions as $name => $definition): ?>
      <a name="<?php print $name ?>-preview"></a>
      <h4><?php print $definition['label'] ?></h4>
      <fieldset>
          <legend><?php print t('Preview') ?></legend>
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
