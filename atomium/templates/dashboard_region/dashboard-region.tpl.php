<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['dashboard_region']
  ->set('id', $element['#dashboard_region'])
  ->append('class', 'dashboard-region'); ?>>
  <?php print $element['#children']; ?>
</div>
