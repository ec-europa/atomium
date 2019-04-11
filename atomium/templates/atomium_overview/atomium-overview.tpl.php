<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php print render($component_list) ?>

<h3><?php print $h3_header ?></h3>

<div>
  <?php foreach ($definitions as $name => $definition): ?>
      <a name="<?php print $definition['attribute_name'] ?>"></a>
      <h4><?php print $definition['label'] ?></h4>
      <fieldset>
          <legend><?php print $fieldset_legend ?></legend>
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
