<?php

/**
 * @file
 * Contains template file.
 */
?>
<?php foreach ($status_messages['status_messages'] as $type => $data): ?>
    <div class="messages alert <?php print $type; ?>">
        <a href="#" class="close" data-dismiss="alert">&times;</a>
        <h3>
            <span class="sr-only"><?php print render($data['#title']); ?></span>
        </h3>
        <p>
          <?php print render($data); ?>
        </p>
    </div>
<?php endforeach; ?>
