<?php

use Drupal\Tests\atomium\Unit\AttributesXRayTest;

if (PHP_SAPI !== 'cli') {
  print 'Nope';
  return;
}

require_once __DIR__ . '/bootstrap.php';

try {
  AttributesXRayTest::generateFixturesStatic();
}
catch (Exception $e) {
  print $e;
  print $e->getTraceAsString();
  print "\n";
}
