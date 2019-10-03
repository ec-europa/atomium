<?php

/**
 * @file
 * Contains template file.
 */
?>
<div<?php print $atomium['attributes']['wrapper']; ?>>
    <textarea<?php print $atomium['attributes']['element']; ?>><?php print check_plain(render($element['#value'])); ?></textarea>
</div>
