<?php

/**
 * @file
 * Contains template file.
 */
?>
<table<?php print $atomium['attributes']['table']; ?>>
  <tr>
    <td class="version-title"><?php print $tag; ?></td>
    <td class="version-details">
      <?php print render($version_details); ?>
      <span class="version-date">(<?php print $version_date; ?>)</span>
    </td>
    <td class="version-links">
      <?php print render($links); ?>
    </td>
  </tr>
</table>
