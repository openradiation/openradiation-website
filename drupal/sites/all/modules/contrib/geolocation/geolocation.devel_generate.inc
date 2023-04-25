<?php

/**
 * @file
 * Devel Generate support for Geolocation module.
 */

/**
 * Implements hook_devel_generate().
 */
function geolocation_devel_generate($object, $field, $instance, $bundle) {
  if (field_behaviors_widget('multiple values', $instance) == FIELD_BEHAVIOR_CUSTOM) {
    return devel_generate_multiple('_geolocation_devel_generate', $object, $field, $instance, $bundle);
  }
  else {
    return _geolocation_devel_generate($object, $field, $instance, $bundle);
  }
}

/**
 * Callback for hook_devel_generate().
 */
function _geolocation_devel_generate($object, $field, $instance, $bundle) {
  $geolocation = array(
    'lat' => rand(-90, 90) - rand(0, 999999) / 1000000,
    'lng' => rand(-180, 180) - rand(0, 999999) / 1000000,
  );

  return _geolocation_field_precalculate_values($geolocation);
}
