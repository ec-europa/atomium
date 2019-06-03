<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!empty($primary)): ?>
  <h2 class="element-invisible"><?php print t('Primary tabs'); ?></h2>
  <?php print render($primary); ?>
<?php endif; ?>
<?php if (!empty($secondary)): ?>
  <h2 class="element-invisible"><?php print t('Secondary tabs'); ?></h2>
  <?php print render($secondary); ?>
<?php endif; ?>
