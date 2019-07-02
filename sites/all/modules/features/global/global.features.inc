<?php
/**
 * @file
 * global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function global_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function global_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function global_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page (contenu modifiable)'),
      'base' => 'node_content',
      'description' => t('Utiliser les <em>pages</em> pour votre contenu statique, comme la page "Qui sommes-nous" par exemple.'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
