<?php
/**
 * Rename this file to settings.local.php and edit to use.
 *
 * All variables defined here are overriding those defined
 * in settings.php file.
 */

# database connection
$databases['default']['default'] = array(
  'driver' => 'pgsql',
  'database' => 'mydatabase',
  'username' => 'myuser',
  'password' => 'mypassword',
  'host' => 'localhost',
  'prefix' => '',
);

#disable cache
$conf['cache'] = 0;

// Turn off css and js consolidation for local development.
$conf['preprocess_css'] = 0;
$conf['preprocess_js'] = 0;

// Turn on all error reporting for local development.
error_reporting(-1);
$conf['error_level'] = 2;
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
