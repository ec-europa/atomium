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
      <h1><a href="<?php print arg(0) . '/' . $name?>" target='_blank'><?php print $definition['label'] ?></a></h1>
      <fieldset>
          <legend><a href="<?php print arg(0) . '/' . $name?>" target='_blank'><?php print t('Preview') ?></a></legend>
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

390-atomium-overview-one-page-per-component-7.x-3.x
