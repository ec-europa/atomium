<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!empty($content)): ?>
  <aside<?php print $atomium['attributes']['region']; ?>><?php print $content; ?></aside>
<?php endif; ?>
