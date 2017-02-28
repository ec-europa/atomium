<?php

/**
 * @file
 * html.tpl.php
 */
?>
<!DOCTYPE html>
<html<?php print $html_attributes . $rdf_namespaces; ?>>
<head>
<?php print $head; ?>
<title><?php print $head_title; ?></title>
<?php print $styles; ?>
<?php print $scripts; ?>
</head>
<body<?php print $attributes;?>>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>
</body>
</html>
