<?php

/**
 * @file
 * Contains template file.
 */
?>
<article<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if ($title_prefix || $title_suffix || $unpublished || $preview || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a
            href="<?php print $node_url; ?>"><?php print $title; ?></a>
        </h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($unpublished): ?>
        <mark class="watermark"><?php print t('Unpublished'); ?></mark>
      <?php elseif ($preview): ?>
        <mark class="watermark"><?php print t('Preview'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  ?>
  <div class="content">
    <?php print render($content); ?>
  </div>

  <?php if ($display_submitted): ?>
    <footer>
      <?php print $user_picture; ?>
      <span class="author"><?php print t('Written by !name', array('!name' => render($name))); ?></span>
      <span class="date">
            <?php print t('On the'); ?>
        <time datetime="<?php print format_date($created,
          $type = 'custom',
          $format = 'Y-m-d\TH:i:sP') ?>"><?php print $date; ?></time>
          </span>
    </footer>
  <?php endif; ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
