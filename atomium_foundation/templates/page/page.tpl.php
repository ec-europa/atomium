<?php

/**
 * @file
 * page.tpl.php
 */
?>
<div class="expanded row">
    <header role="banner"><?php print render($page['header']); ?></header>
</div>

<?php if (!empty($breadcrumb)): ?>
    <div class="row">
        <div class="larger-12 columns">
          <?php print render($breadcrumb); ?>
        </div>
    </div>
<?php endif; ?>

<div class="row">
    <?php print render($page['sidebar_first']); ?>

    <main class="large-9 columns" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
          <h1><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print render($messages); ?>
      <?php print render($tabs); ?>
      <?php if ($action_links): ?>
          <div class="menu expanded button-group item-list"><?php print render($action_links); ?></div>
      <?php endif; ?>
      <?php print render($page['help']); ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </main>

    <?php print render($page['sidebar_second']); ?>
</div>

<div class="expanded row">
    <footer role="contentinfo"><?php print render($page['footer']); ?></footer>
</div>
