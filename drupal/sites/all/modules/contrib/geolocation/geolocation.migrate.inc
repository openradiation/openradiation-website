<?php

/**
 * @file
 * Integration with Migrate module.
 */

/**
 * Implement hook_migrate_api().
 */
function geolocation_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array('MigrateGeolocationFieldHandler'),
  );
}
