<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
<?php if (!$label_hidden) : ?>
<label<?php print $title_attributes; ?>><?php print $label ?></label>
<?php endif; ?>
<div<?php print $content_attributes; ?>>
<?php foreach ($items as $delta => $item) : ?>
<div<?php print $attributes_item[$delta]; ?>><?php print render($item); ?></div>
<?php endforeach; ?>
</div>
</div>
