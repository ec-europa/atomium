<?php

/**
 * @file
 * Contains template file.
 */
?>
<div class="canvas-content">
  <p><?php print t('Drag and drop these blocks to the columns below. Changes are automatically saved. More options are available on the <a href="@dashboard-url">configuration page</a>.', array('@dashboard-url' => url('admin/dashboard/configure'))); ?></p>
  <div id="disabled-blocks">
    <div class="region disabled-blocks clearfix">
      <?php print render($disabled_blocks); ?>
      <div class="clearfix"></div>
      <p class="dashboard-add-other-blocks">
        <?php print l(t('Add other blocks'), 'admin/dashboard/configure'); ?>
      </p>
    </div>
  </div>
</div>
