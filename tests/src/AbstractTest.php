<?php

namespace Drupal\Tests\atomium;

use PHPUnit\Framework\TestCase;
use Symfony\Component\Finder\Finder;
use Symfony\Component\Yaml\Yaml;

/**
 * Class AbstractTest.
 *
 * @package Drupal\Tests\atomium
 */
abstract class AbstractTest extends TestCase {

  /**
   * Return component fixtures.
   *
   * @return array
   *   List of component fixtures.
   */
  public function componentsProvider() {
    $data = [];

    $finder = new Finder();
    $finder->files()->in(realpath(__DIR__ . '/../fixtures/components'));
    foreach ($finder as $file) {
      $data[] = [
        'hook' => drupal_basename($file->getRelativePathname(), '.yml'),
        'content' => Yaml::parse($file->getContents()),
      ];
    }
    return $data;
  }

  /**
   * Return attribute fixtures.
   *
   * @return array
   *   List of attributes fixtures.
   */
  public function attributesProvider() {
    $data = [];

    $finder = new Finder();
    $finder->files()->in(realpath(__DIR__ . '/../fixtures/attributes'));
    foreach ($finder as $file) {
      $data[] = [
        'attribute_fixture' => Yaml::parse($file->getContents()),
      ];
    }
    return $data;
  }

  /**
   * Return preprocess fixtures.
   *
   * @return array
   *   List of variables fixtures.
   */
  public function variablesPreprocessProvider() {
    $data = [];

    $finder = new Finder();
    $finder->files()->in(drupal_realpath(__DIR__ . '/../fixtures/preprocess'));
    foreach ($finder as $file) {
      $data[] = [
        'variable_fixture' => Yaml::parse($file->getContents()),
      ];
    }
    return $data;
  }

  /**
   * Return process fixtures.
   *
   * @return array
   *   List of variables fixtures.
   */
  public function variablesProcessProvider() {
    $data = [];

    $finder = new Finder();
    $finder->files()->in(drupal_realpath(__DIR__ . '/../fixtures/process'));
    foreach ($finder as $file) {
      $data[] = [
        'variable_fixture' => Yaml::parse($file->getContents()),
      ];
    }
    return $data;
  }

}
