<?php

/**
 * @file
 * Contains template file.
 */
?>
<!DOCTYPE html>
<html<?php print $atomium['attributes']['html']; ?>>
<head>
  <?php print $head; ?>
    <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body<?php print $atomium['attributes']['body']; ?>>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>
</body>
</html>
