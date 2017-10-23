<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']->append('class', array(
  'filter-guidelines-item', 'filter-guidelines-' . $variables['format']->format,
)); ?>>
    <h3><?php print $name; ?></h3>
  <?php print render($tips); ?>
</div>
