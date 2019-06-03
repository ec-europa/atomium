<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($wrapper): ?>
  <div<?php print $atomium['attributes']['wrapper']; ?>>
<?php endif; ?>
  <?php print render($title); ?>
  <?php if (!empty($variables['items'])): ?>
    <?php if ($type): ?>
        <<?php print $type; ?><?php print $atomium['attributes']['list']; ?>>
    <?php endif; ?>

    <?php print render($variables['items']); ?>

    <?php if ($type): ?>
      </<?php print $type; ?>>
    <?php endif; ?>
  <?php endif; ?>
<?php if ($wrapper): ?>
  </div>
<?php endif; ?>
