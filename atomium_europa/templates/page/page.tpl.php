<?php

/**
 * @file
 * Contains template file.
 */
?>
<header role="banner"><?php print render($page['header']); ?></header>

<div class="ph3 ph5-ns pt4 pb5">
    <div class="cf ph2-ns">
      <?php if ($page['sidebar_first']): ?>
          <aside role="complementary" class="fl w-25 pa2"><?php print render($page['sidebar_first']); ?></aside>
      <?php endif; ?>

        <main role="main" class="fl <?php $page['sidebar_second'] ? print 'w-75' : print 'w-50' ?> pa2">
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
              <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
        </main>

      <?php if ($page['sidebar_second']): ?>
          <aside role="complementary" class="fl w-25 pa2"><?php print render($page['sidebar_second']); ?></aside>
      <?php endif; ?>
    </div>
</div>

<footer role="contentinfo" class="ph3 ph5-ns pt4 pb5"><?php print render($page['footer']); ?></footer>
