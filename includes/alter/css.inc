<?php

/**
 * @file
 * css.inc
 */

/**
 * Implements hook_css_alter().
 */
function atomium_css_alter(&$css) {
  $exclude = array(
    // 'misc/vertical-tabs.css' => FALSE,.
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/block/block.css' => FALSE,
    'modules/book/book.css' => FALSE,
    'modules/comment/comment.css' => FALSE,
    // 'modules/dblog/dblog.css' => FALSE,
    // 'modules/file/file.css' => FALSE,.
    'modules/filter/filter.css' => FALSE,
    // 'modules/forum/forum.css' => FALSE,
    // 'modules/help/help.css' => FALSE,.
    'modules/menu/menu.css' => FALSE,
    'modules/node/node.css' => FALSE,
    // 'modules/openid/openid.css' => FALSE,.
    'modules/poll/poll.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    'modules/search/search.css' => FALSE,
    // 'modules/statistics/statistics.css' => FALSE,
    // 'modules/syslog/syslog.css' => FALSE,
    // 'modules/system/admin.css' => FALSE,
    // 'modules/system/maintenance.css' => FALSE,
    // 'modules/system/system.css' => FALSE,
    // 'modules/system/system.admin.css' => FALSE,
    // 'modules/system/system.base.css' => FALSE,
    // 'modules/system/system.maintenance.css' => FALSE,.
    'modules/system/system.menus.css' => FALSE,
    'modules/system/system.messages.css' => FALSE,
    'modules/system/system.theme.css' => FALSE,
    'modules/taxonomy/taxonomy.css' => FALSE,
    'modules/tracker/tracker.css' => FALSE,
    // 'modules/update/update.css' => FALSE,.
    'modules/user/user.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}
