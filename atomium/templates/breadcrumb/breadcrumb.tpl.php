<?php

/**
 * @file
 * Contains template file.
 */
?>
<nav<?php print $atomium['attributes']['wrapper']; ?>>
  <h2 class="element-invisible"><?php print t('You are here'); ?></h2>
  <?php print render($breadcrumb); ?>
</nav>
