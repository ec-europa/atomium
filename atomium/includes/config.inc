<?php

/**
 * @file
 * config.inc
 */

if (array_key_exists('theme_debug', $GLOBALS['conf'])) $GLOBALS['conf']['theme_debug'] = $GLOBALS['conf']['theme_debug'] || theme_get_setting('theme_debug');
if (array_key_exists('allow_css_double_underscores', $GLOBALS['conf'])) $GLOBALS['conf']['allow_css_double_underscores'] = $GLOBALS['conf']['allow_css_double_underscores'] || theme_get_setting('allow_css_double_underscores');
