<?php
/**
 * @file
 * mission.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mission_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mission_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mission_node_info() {
  $items = array(
    'mission' => array(
      'name' => t('Mission'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre de la mission'),
      'help' => '',
    ),
    'og_blog_post' => array(
      'name' => t('Blog post de groupe'),
      'base' => 'node_content',
      'description' => t('Billet de blog pour les missions'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'og_discussion' => array(
      'name' => t('Discussion de groupe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'og_document' => array(
      'name' => t('Document partagé'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre du document'),
      'help' => '',
    ),
    'og_news' => array(
      'name' => t('Actualité de groupe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre de l\'actualité'),
      'help' => '',
    ),
    'og_wiki' => array(
      'name' => t('Wiki de groupe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
