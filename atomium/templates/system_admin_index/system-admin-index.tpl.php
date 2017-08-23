<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $attributes; ?>>
    <?php print render($variables['toggle_link']); ?>
    <?php foreach ($variables['container'] as $data): ?>
        <div<?php print $data['attributes']; ?>>
            <?php print render($data['content']); ?>
        </div>
    <?php endforeach; ?>
</div>
