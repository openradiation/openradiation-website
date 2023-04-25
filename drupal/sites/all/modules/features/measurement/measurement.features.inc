<?php
/**
 * @file
 * measurement.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function measurement_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function measurement_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function measurement_node_info() {
  $items = array(
    'measurement' => array(
      'name' => t('Mesure'),
      'base' => 'node_content',
      'description' => t('Une mesure, effectuée à l\'aide d\'un appareil synchronisé avec la base de données, ou saisie manuellement par les utilisateurs.'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
