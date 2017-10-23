<?php

/**
 * @file
 * Contains template file.
 */
?>
<table<?php print $atomium['attributes']['wrapper']; ?>>
  <?php if (!empty($caption)) : ?>
      <caption><?php print render($caption); ?></caption>
  <?php endif; ?>

  <?php if (!empty($colgroups)) : ?>
    <?php $row_num_index = 0; ?>
    <?php foreach ($colgroups as $row_index => $row): ?>
          <colgroup<?php print $atomium['attributes']['colgroup-row-' . $row_num_index]->append('class',
            $row_index); ?>>
            <?php $cell_num_index = 0; ?>
            <?php foreach ($row['cells'] as $cell_index => $cell): ?>
                <col<?php print $atomium['attributes']['colgroup-cell-' . $row_num_index . '-' . $cell_num_index]; ?>/>
              <?php $cell_num_index++; ?>
            <?php endforeach; ?>
          </colgroup>
    <?php endforeach; ?>
  <?php endif; ?>

  <?php if (!empty($header)) : ?>
      <thead>
      <?php $row_num_index = 0; ?>
      <?php foreach ($header as $row_index => $row): ?>
          <tr<?php print $atomium['attributes']['header-row-' . $row_num_index]->append('class',
            $row_index); ?>>
            <?php $cell_num_index = 0; ?>
            <?php foreach ($row['cells'] as $cell_index => $cell): ?>
                <th<?php print $atomium['attributes']['header-cell-' . $row_num_index . '-' . $cell_num_index]->append('scope', 'col')->append('class', $cell_index)->append('class', 'cell-index-' . $cell_num_index); ?>>
                  <?php print render($cell); ?>
                </th>
              <?php $cell_num_index++; ?>
            <?php endforeach; ?>
          </tr>
        <?php $row_num_index++; ?>
      <?php endforeach; ?>
      </thead>
  <?php endif; ?>

    <tbody>
    <?php $row_num_index = 0; ?>
    <?php foreach ($rows as $row_index => $row): ?>
        <tr<?php print $atomium['attributes']['body-row-' . $row_num_index]->append('class',
          $row_index); ?>>
          <?php $cell_num_index = 0; ?>
          <?php foreach ($row['cells'] as $cell_index => $cell): ?>
              <td<?php print $atomium['attributes']['body-cell-' . $row_num_index . '-' . $cell_num_index]->append('class', 'cell-index-' . $cell_num_index)->append('class', $cell_index); ?>>
                <?php print render($cell); ?>
              </td>
            <?php $cell_num_index++; ?>
          <?php endforeach; ?>
        </tr>
      <?php $row_num_index++; ?>
    <?php endforeach; ?>
    </tbody>

  <?php if (!empty($footer)) : ?>
      <tfoot>
      <?php $row_num_index = 0; ?>
      <?php foreach ($footer as $row_index => $row): ?>
          <tr<?php print $atomium['attributes']['footer-row-' . $row_num_index]->append('class',
            $row_index); ?>>
            <?php $cell_num_index = 0; ?>
            <?php foreach ($row['cells'] as $cell_index => $cell): ?>
                <td<?php print $atomium['attributes']['footer-cell-' . $row_num_index . '-' . $cell_num_index]->append('class', $cell_index)->append('class', 'cell-index-' . $cell_num_index); ?>>
                  <?php print render($cell); ?>
                </td>
              <?php $cell_num_index++; ?>
            <?php endforeach; ?>
          </tr>
        <?php $row_num_index++; ?>
      <?php endforeach; ?>
      </tfoot>
  <?php endif; ?>
</table>
