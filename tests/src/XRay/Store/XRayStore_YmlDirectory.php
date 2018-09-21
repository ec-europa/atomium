<?php

namespace Drupal\Tests\atomium\XRay\Store;

use Symfony\Component\Yaml\Yaml;

class XRayStore_YmlDirectory implements XRayStoreInterface {

  /**
   * @var string
   */
  private $directory;

  /**
   * @param string $directory
   */
  public function __construct($directory) {
    $this->directory = $directory;
  }

  /**
   * @return mixed
   */
  public function load() {
    return $this->loadInPath($this->directory);
  }

  /**
   * @param string $path
   *
   * @return mixed[]
   *   Format: $[$path] = $value
   */
  private function loadInPath($path) {

    $values = [];
    foreach (scandir($path, SCANDIR_SORT_NONE) as $candidate) {
      if ('.' === $candidate || '..' === $candidate) {
        continue;
      }
      $childpath = $path . '/' . $candidate;
      if (is_dir($childpath)) {
        foreach ($this->loadInPath($childpath) as $k => $value) {
          $values[$candidate . '/' . $k] = $value;
        }
      }
      elseif ('.yml' === substr($candidate, -4)) {
        $name = substr($candidate, 0, -4);
        $values[$name] = Yaml::parseFile($childpath);
      }
    }

    return $values;
  }

  /**
   * @param array $values
   *
   * @throws \Exception
   */
  public function save(array $values) {

    $this->clearDirectoryTPath($this->directory . '/');

    foreach ($values as $key => $value) {
      $yml = Yaml::dump($value, 8);
      $this->writeFile($this->directory . '/' . $key . '.yml', $yml);
    }
  }

  /**
   * @param string $path
   * @param mixed $contents
   *
   * @throws \Exception
   */
  private function writeFile($path, $contents) {

    $this->createParentDir($path);

    if (FALSE === file_put_contents($path, $contents)) {
      throw new \Exception("Failed to save yml at '$path'.");
    }
  }

  /**
   * @param string $path
   *
   * @throws \Exception
   */
  private function createParentDir($path) {
    if (FALSE === $pos = strrpos($path, '/')) {
      return;
    }
    $dir = substr($path, 0, $pos);
    if (is_dir($dir)) {
      if (!is_writable($dir)) {
        throw new \Exception("Directory '$dir' is not writable.");
      }
      return;
    }
    $this->createParentDir($dir);
    if (!mkdir($dir)) {
      throw new \Exception("Failed to create directory '$dir'.");
    }
  }

  /**
   * @param string $tpath
   *   Directory path ending with '/'.
   */
  private function clearDirectoryTPath($tpath) {

    if ('/' !== substr($tpath, -1)) {
      throw new \InvalidArgumentException(
        '$tpath must be terminated by a slash.');
    }

    foreach (glob($tpath . '*', GLOB_MARK) as $childpath) {
      if ('/' === substr($childpath, -1)) {
        $this->clearDirectoryTPath($tpath);
        rmdir($childpath);
      }
      else {
        unlink($childpath);
      }
    }
  }
}
