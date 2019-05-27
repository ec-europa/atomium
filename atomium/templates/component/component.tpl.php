<?php

/**
 * @file
 * Contains template file.
 */
?>
<div>
  <a name="<?php print $name; ?>-preview"></a>
  <h4><?php print $name; ?></h4>
  <details open>
    <summary><?php print t('Preview'); ?></summary>
    <div>
      <?php if (isset($component['description'])): ?>
        <p><?php print $component['description'] ?></p>
      <?php endif; ?>
      <?php if (isset($component['preview'])): ?>
        <?php $html = trim(render($component['preview'])); ?>
        <details>
          <summary><?php print t('Preview'); ?></summary>
          <?php print $html; ?>
        </details>

      <details>
        <summary><?php print t('HTML source'); ?></summary>
          <textarea>
            <?php print $html; ?>
          </textarea>
      </details>
      <?php endif; ?>
      <?php if (isset($component['form'])): ?>
        <div class="clearfix">
          <?php $form = render($component['form']); ?>
          <?php print $form; ?>
          <div class="textwrapper"><textarea cols="2" rows="10"><?php print $form; ?></textarea></div>
        </div>
      <?php endif; ?>
    </div>
  </details>
</div>
