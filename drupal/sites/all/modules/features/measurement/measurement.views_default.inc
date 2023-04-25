<?php
/**
 * @file
 * measurement.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function measurement_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'measurement_most_commented';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mesure - Mesures les plus commentées';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mesures les plus commentées';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_geolocalisation' => 'field_geolocalisation',
    'view_node' => 'view_node',
    'field_value' => 'field_value',
    'created' => 'created',
    'last_updated' => 'last_updated',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_geolocalisation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'hover' => 'hover',
    'striped' => 0,
    'bordered' => 0,
    'condensed' => 0,
  );
  /* Relation: Content: Last comment author */
  $handler->display->display_options['relationships']['last_comment_uid']['id'] = 'last_comment_uid';
  $handler->display->display_options['relationships']['last_comment_uid']['table'] = 'node_comment_statistics';
  $handler->display->display_options['relationships']['last_comment_uid']['field'] = 'last_comment_uid';
  $handler->display->display_options['relationships']['last_comment_uid']['label'] = 'Auteur du dernier commentaire';
  /* Relation: Content: Qualification moyenne (field_calculated_qualification) */
  $handler->display->display_options['relationships']['field_calculated_qualification_tid']['id'] = 'field_calculated_qualification_tid';
  $handler->display->display_options['relationships']['field_calculated_qualification_tid']['table'] = 'field_data_field_calculated_qualification';
  $handler->display->display_options['relationships']['field_calculated_qualification_tid']['field'] = 'field_calculated_qualification_tid';
  $handler->display->display_options['relationships']['field_calculated_qualification_tid']['label'] = 'terme à partir de field_calculated_qualification';
  /* Champ: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Champ: Content: Geolocalisation */
  $handler->display->display_options['fields']['field_geolocalisation']['id'] = 'field_geolocalisation';
  $handler->display->display_options['fields']['field_geolocalisation']['table'] = 'field_data_field_geolocalisation';
  $handler->display->display_options['fields']['field_geolocalisation']['field'] = 'field_geolocalisation';
  $handler->display->display_options['fields']['field_geolocalisation']['label'] = 'Map';
  $handler->display->display_options['fields']['field_geolocalisation']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_geolocalisation']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_geolocalisation']['click_sort_column'] = 'lat';
  $handler->display->display_options['fields']['field_geolocalisation']['type'] = 'geolocation_googlemaps_static';
  $handler->display->display_options['fields']['field_geolocalisation']['settings'] = array(
    'map_width' => '200px',
    'map_height' => '150px',
    'marker_icon' => '',
    'map_imageformat' => 'png32',
    'map_link' => 0,
    'map_maptype' => 'roadmap',
    'map_zoomlevel' => '4',
  );
  /* Champ: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Champ: Content: Radiation mesurée */
  $handler->display->display_options['fields']['field_value']['id'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['table'] = 'field_data_field_value';
  $handler->display->display_options['fields']['field_value']['field'] = 'field_value';
  $handler->display->display_options['fields']['field_value']['label'] = 'Value';
  $handler->display->display_options['fields']['field_value']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Champ: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Champ: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last activity';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'short';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'privatemsg_current_day';
  /* Champ: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'comments';
  /* Critère de tri: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  /* Critère de filtrage: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'measurement' => 'measurement',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'measurement/most-commented';
  $export['measurement_most_commented'] = $view;

  return $export;
}
