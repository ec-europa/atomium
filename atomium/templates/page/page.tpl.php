<?php

/**
 * @file
 * Contains template file.
 */
?>
<header role="banner"><?php print render($page['header']); ?></header>

<?php if ($page['sidebar_first']): ?>
  <?php print render($page['sidebar_first']); ?>
<?php endif; ?>

<main role="main">
  <?php print render($page['highlighted']); ?>
  <?php print render($breadcrumb); ?>
  <?php print render($title_prefix); ?>

  <?php if ($title): ?>
      <h1><?php print $title; ?></h1>
  <?php endif; ?>

  <?php print render($title_suffix); ?>
  <?php print render($messages); ?>
  <?php print render($tabs); ?>
  <?php print render($page['help']); ?>

  <?php if ($action_links): ?>
    <?php print render($action_links); ?>
  <?php endif; ?>

  <?php print render($page['content']); ?>
</main>

<?php if ($page['sidebar_second']): ?>
  <?php print render($page['sidebar_second']); ?>
<?php endif; ?>

<footer role="contentinfo"><?php print render($page['footer']); ?></footer>
