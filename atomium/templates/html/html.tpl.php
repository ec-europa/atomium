<?php

/**
 * @file
 * Contains template file.
 */
?>
<!DOCTYPE html>
<html<?php print $atomium['attributes']['html']; ?>>
<head>
  <?php print render($head); ?>
    <title><?php print render($head_title); ?></title>
  <?php print render($styles); ?>
  <?php print render($scripts); ?>
</head>
<body<?php print $atomium['attributes']['body']; ?>>
<?php print render($page_top); ?>
<?php print render($page); ?>
<?php print render($page_bottom); ?>
</body>
</html>
