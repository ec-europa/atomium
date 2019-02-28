<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if ($element['#title_display'] === 'before' || $element['#title_display'] === 'invisible'): ?>
    <?php print render($label); ?>
    <?php if ($element['#field_prefix']): ?>
          <span class="field-prefix"><?php print render($element['#field_prefix']); ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
          <span class="field-suffix"><?php print render($element['#field_suffix']); ?></span>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($element['#title_display'] === 'after'): ?>
    <?php if ($element['#field_prefix']): ?>
          <span class="field-prefix"><?php print render($element['#field_prefix']); ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
          <span class="field-suffix"><?php print render($element['#field_suffix']); ?></span>
    <?php endif; ?>
    <?php print render($label); ?>
  <?php endif; ?>

  <?php if ($element['#title_display'] === 'none' || $element['#title_display'] === 'attribute'): ?>
    <?php if ($element['#field_prefix']): ?>
          <span class="field-prefix"><?php print render($element['#field_prefix']); ?></span>
    <?php endif; ?>
    <?php print $element['#children']; ?>
    <?php if ($element['#field_suffix']): ?>
          <span class="field-suffix"><?php print render($element['#field_suffix']); ?></span>
    <?php endif; ?>
  <?php endif; ?>

  <?php if (!empty($description)): ?>
      <div class="description"><?php print render($description); ?></div>
  <?php endif; ?>
</div>
