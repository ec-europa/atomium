<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="canvas-content">
  <p><?php print render($help_text); ?></p>
  <div id="disabled-blocks">
    <div class="region disabled-blocks clearfix">
      <?php print render($disabled_blocks); ?>
      <div class="clearfix"></div>
      <p class="dashboard-add-other-blocks">
        <?php print render($add_other_blocks); ?>
      </p>
    </div>
  </div>
</div>
