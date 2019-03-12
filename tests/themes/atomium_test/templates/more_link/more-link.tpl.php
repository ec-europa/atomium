<?php

/**
 * @file
 * Template file.
 */
$callbacks[] = preg_replace('@^.*/tests/@', 'tests/', __FILE__);
?>
<?php print implode(',', $callbacks); ?>
