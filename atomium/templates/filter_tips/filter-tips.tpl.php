<?php

/**
 * @file
 * Contains template file.
 */
?>
<h2><?php print t('Text Formats');?></h2>
<div class="compose-tips">
  <?php foreach ($tips as $name => $tipList): ?>
      <div class="filter-type filter-'<?php print drupal_html_class($name); ?>'">
          <h3><?php print check_plain($name); ?></h3>
          <ul class="tips">
            <?php foreach ($tips[$name] as $tip): ?>
                <li<?php print ($long ? ' id="filter-' . str_replace("/", "-", $tip['id']) . '"' : '');?>><?php print $tip['tip'];?></li>
            <?php endforeach; ?>
          </ul>
      </div>
  <?php endforeach; ?>
</div>
