<?php

/**
 * @file
 * Contains template file.
 */
?>
<fieldset<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if ($legend): ?>
    <?php print render($legend); ?>
  <?php endif; ?>
    <div class="fieldset-wrapper">
      <?php print render($description); ?>
      <?php print render($element['#children']); ?>
    </div>
</fieldset>
