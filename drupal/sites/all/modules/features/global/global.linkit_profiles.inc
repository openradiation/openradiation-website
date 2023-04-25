<?php
/**
 * @file
 * global.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function global_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'openradiation';
  $linkit_profile->admin_title = 'openradiation';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'filtered_html' => 'filtered_html',
      'full_html' => 'full_html',
      'plain_text' => 0,
    ),
    'search_plugins' => array(
      'entity:taxonomy_term' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_news' => 0,
        'comment_node_og_news' => 0,
        'comment_node_article' => 0,
        'comment_node_og_blog_post' => 0,
        'comment_node_press_release' => 0,
        'comment_node_press_content' => 0,
        'comment_node_book' => 0,
        'comment_node_og_discussion' => 0,
        'comment_node_og_document' => 0,
        'comment_node_measurement' => 0,
        'comment_node_mission' => 0,
        'comment_node_page' => 0,
        'comment_node_forum' => 0,
        'comment_node_og_wiki' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'news' => 0,
        'og_news' => 0,
        'article' => 0,
        'og_blog_post' => 0,
        'press_release' => 0,
        'press_content' => 0,
        'book' => 0,
        'og_discussion' => 0,
        'og_document' => 0,
        'measurement' => 0,
        'mission' => 0,
        'page' => 0,
        'forum' => 0,
        'og_wiki' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'direct',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'forums' => 0,
        'userpoints' => 0,
        'apparatus_type' => 0,
        'measure_environmment' => 0,
        'measure_qualification_type' => 0,
        'measure_tags' => 0,
        'tags' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['openradiation'] = $linkit_profile;

  return $export;
}
