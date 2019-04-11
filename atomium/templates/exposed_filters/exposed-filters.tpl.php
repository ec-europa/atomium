<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="exposed-filters">
  <?php print render($exposed_filters); ?>
  <?php print drupal_render_children($form); ?>
</div>
