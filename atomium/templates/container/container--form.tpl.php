<?php

/**
 * @file
 * Contains template file.
 *
 * If this is not added, it will cause issue with the #states mechanisms.
 * Especially in the theme settings form.
 */
?>
<div<?php print $atomium['attributes']['wrapper']->append('class', 'form-wrapper'); ?>>
  <?php print render($container); ?>
</div>
