<?php

/**
 * @file
 * Contains template file.
 */
?>
<span<?php print $atomium['attributes']['wrapper']->append('class', 'form-required')->append('title', t('This field is required.')); ?>>
  <?php print render($title); ?>
</span>
