<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if (!$label_hidden) : ?>
      <label<?php print $atomium['attributes']['title']; ?>><?php print $label ?></label>
  <?php endif; ?>
    <div<?php print $atomium['attributes']['content']->append('class', 'field-items'); ?>>
      <?php foreach ($items as $delta => $item): ?>
          <div<?php print $atomium['attributes'][$delta]->append('class', array('field-item', ($delta % 2 ? 'odd' : 'even'))); ?>>
            <?php print render($item); ?>
          </div>
      <?php endforeach; ?>
    </div>
</div>
