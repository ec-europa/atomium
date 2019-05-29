<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if ($element['#title_display'] === 'before' || $element['#title_display'] === 'invisible'): ?>
    <?php print render($label); ?>
    <?php if (strlen($element['#field_prefix']) !== 0): ?>
          <span class="field-prefix"><?php print $element['#field_prefix']; ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if (strlen($element['#field_suffix']) !== 0): ?>
          <span class="field-suffix"><?php print $element['#field_suffix']; ?></span>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($element['#title_display'] === 'after'): ?>
    <?php if (strlen($element['#field_prefix']) !== 0): ?>
      <span class="field-prefix"><?php print $element['#field_prefix']; ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if (strlen($element['#field_suffix']) !== 0): ?>
      <span class="field-suffix"><?php print $element['#field_suffix']; ?></span>
    <?php endif; ?>
    <?php print render($label); ?>
  <?php endif; ?>

  <?php if ($element['#title_display'] === 'none' || $element['#title_display'] === 'attribute'): ?>
    <?php if (strlen($element['#field_prefix']) !== 0): ?>
      <span class="field-prefix"><?php print $element['#field_prefix']; ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if (strlen($element['#field_suffix']) !== 0): ?>
      <span class="field-suffix"><?php print $element['#field_suffix']; ?></span>
    <?php endif; ?>
  <?php endif; ?>

  <?php if (!empty($description)): ?>
      <div class="description"><?php print render($description); ?></div>
  <?php endif; ?>
</div>
