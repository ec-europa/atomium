<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php if (!empty($page['header'])): ?>
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <header role="banner"><?php print render($page['header']); ?></header>
            </div>
        </div>
    </div>
<?php endif; ?>

<?php if (!empty($breadcrumb)): ?>
<div class="container">
    <div class="row">
        <div class="col-md-12">
          <?php print render($breadcrumb); ?>
        </div>
    </div>
</div>
<?php endif; ?>

<div class="container">
    <div class="row">
      <?php if ($page['sidebar_first']): ?>
          <?php print render($page['sidebar_first']); ?>
      <?php endif; ?>

        <main class="col-md-9" role="main">
          <?php print render($page['highlighted']); ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?><h1><?php print $title; ?></h1><?php
          endif; ?>
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
    </div>
</div>

<?php if (!empty($page['footer'])): ?>
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <footer role="contentinfo"><?php print render($page['footer']); ?></footer>
            </div>
        </div>
    </div>
<?php endif; ?>
