<?php

/**
 * @file
 * Contains template file.
 */
?>
<div>
  <a name="<?php print $name; ?>-preview"></a>
  <h4><?php print $name; ?></h4>
  <details>
    <summary><?php print t('Preview'); ?></summary>
    <div>
      <?php if (isset($component['description'])): ?>
        <p><?php print $component['description']; ?></p>
      <?php endif; ?>
      <?php if (isset($component['preview'])): ?>
        <?php $html = trim(render($component['preview'])); ?>
        <details>
          <summary><?php print t('Preview'); ?></summary>
          <?php print $html; ?>
        </details>

      <details>
        <summary><?php print t('HTML source'); ?></summary>
          <pre><code>
            <?php print check_plain($html); ?>
          </code></pre>
      </details>
      <?php endif; ?>
      <?php if (isset($component['form'])): ?>
        <details>
          <summary><?php print t('Preview'); ?></summary>
          <?php $html = trim(render($component['form'])); ?>
          <?php print $html; ?>
        </details>
        <details>
          <summary><?php print t('HTML source'); ?></summary>
          <pre><code>
            <?php print check_plain($html); ?>
          </code></pre>
        </details>
      <?php endif; ?>
    </div>
  </details>
</div>
