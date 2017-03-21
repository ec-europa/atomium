<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="field">
    <div class="field__label"><?php print $label ?></div>
    <div class="field__items">
      <?php foreach ($items as $delta => $item) : ?>
          <div><?php print render($item); ?></div>
      <?php endforeach; ?>
    </div>
</div>
