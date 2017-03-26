<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php foreach ($status_messages['status_messages'] as $type => $data): ?>
  <div class="messages alert <?php print $type; ?>">
    <?php print render($data); ?>
  </div>
<?php endforeach; ?>
