<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (count($links)): ?>
  <?php if (!empty($heading)): ?>
        <<?php print $heading['level']; ?><?php print $heading_attributes; ?>><?php print $heading['text']; ?></<?php print $heading['level']; ?>>
  <?php endif; ?>

    <ul<?php print $attributes;?>>
        <?php foreach($links as $key => $link): ?>
            <li<?php print $link['attributes']; ?>>
                <span<?php print $link['span_attributes']; ?>><?php print render($link['text']); ?></span>
            </li>
        <?php endforeach; ?>
    </ul>
<?php endif; ?>
