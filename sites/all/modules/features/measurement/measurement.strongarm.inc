<?php
/**
 * @file
 * measurement.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function measurement_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_measurement';
  $strongarm->value = 1;
  $export['i18n_node_extended_measurement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_measurement';
  $strongarm->value = array();
  $export['i18n_node_options_measurement'] = $strongarm;

  return $export;
}
