<?php

/**
 * @file
 * fieldset.tpl.php
 */
?>
<fieldset<?php print $attributes; ?>>
  <?php if ($title): ?>
      <legend><span class="fieldset-legend"><?php print $title; ?></span></legend>
  <?php endif; ?>
    <div class="fieldset-wrapper">
      <?php if ($description): ?>
          <div class="fieldset-description"><?php print $description; ?></div>
      <?php endif; ?>

      <?php print render($element['#children']); ?>
    </div>
</fieldset>
