<?php

/**
 * @file
 * Status_messages.preprocess.inc.
 */

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_europa_atomium_definition_status_messages() {
  return array(
    'label' => 'Status messages',
    'description' => 'Status messages.',
    'preview' => array(
      'messages' => array(
        array(
          'messages' => 'A simple info message',
        ),
        'error' => array(
          'messages' => 'A simple error message',
        ),
        'status' => array(
          'messages' => 'A simple status message',
        ),
        'warning' => array(
          'messages' => 'A simple warning message',
        ),
        'live' => array(
          'messages' => 'A simple live message',
        ),
      ),
    ),
  );
}
