<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if ($wrapper): ?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
<?php endif; ?>

  <?php if ($title): ?>
    <div class="field-label">
      <?php print render($title); ?>:
    </div>
  <?php endif; ?>

  <?php if (!empty($variables['items'])): ?>
    <?php if ($type): ?>
      <<?php print $type; ?><?php print $atomium['attributes']['list']->append('class', 'field-items'); ?>>
    <?php endif; ?>

    <?php foreach ($variables['items'] as $delta => $item): ?>
      <div<?php print $atomium['attributes'][$delta]->append('class', 'field-item'); ?>>
        <?php print render($item); ?>
      </div>
    <?php endforeach; ?>

    <?php if ($type): ?>
      </<?php print $type; ?>>
    <?php endif; ?>
  <?php endif; ?>

<?php if ($wrapper): ?>
  </div>
<?php endif; ?>
