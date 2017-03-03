<?php

/**
 * @file
 * File system-admin-index.tpl.php.
 */
?>
<div<?php print $attributes; ?>>
    <?php print render($variables['toggle_link']); ?>
    <?php foreach ($variables['container'] as $id => $data): ?>
        <div<?php print $data['attributes']; ?>>
            <?php print render($data['content']); ?>
        </div>
    <?php endforeach; ?>
</div>
