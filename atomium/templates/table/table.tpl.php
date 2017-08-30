<?php

/**
 * @file
 * Contains template file.
 */
?>

<table<?php print $attributes;?>>
  <?php if (!empty($caption)) : ?>
    <caption><?php print render($caption); ?></caption>
  <?php endif; ?>

  <?php if (!empty($colgroups)) : ?>
    <?php foreach ($colgroups as $row): ?>
      <colgroup<?php print $row['attributes']; ?>>
        <?php foreach ($row['cells'] as $cell): ?>
          <col<?php print $cell['attributes']; ?>/>
        <?php endforeach; ?>
      </colgroup>
    <?php endforeach; ?>
  <?php endif; ?>

  <?php if (!empty($header)) : ?>
    <thead>
    <?php foreach ($header as $row): ?>
      <tr<?php print $row['attributes']; ?>>
        <?php foreach ($row['cells'] as $cell): ?>
          <th<?php print $cell['attributes']; ?>>
            <?php print render($cell['cell']); ?>
          </th>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
    </thead>
  <?php endif; ?>

  <tbody>
  <?php foreach ($rows as $row): ?>
    <tr<?php print $row['attributes']; ?>>
      <?php foreach ($row['cells'] as $cell): ?>
        <td<?php print $cell['attributes']; ?>>
          <?php print render($cell['cell']); ?>
        </td>
      <?php endforeach; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>

  <?php if (!empty($footer)) : ?>
    <tfoot>
    <?php foreach ($footer as $row): ?>
      <tr<?php print $row['attributes']; ?>>
        <?php foreach ($row['cells'] as $cell): ?>
          <td<?php print $cell['attributes']; ?>>
            <?php print render($cell['cell']); ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
    </tfoot>
  <?php endif; ?>
</table>
