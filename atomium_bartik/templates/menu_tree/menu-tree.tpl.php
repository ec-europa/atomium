<?php

/**
 * @file
 * Contains template file.
 */
?>
<ul<?php print $atomium['attributes']['wrapper']->append('class', array('menu', 'clearfix')); ?>>
  <?php print render($tree); ?>
</ul>
