<?php


/**
 * Display config form on "admin/config/people/userpoints/bluestone-points" page
 *
 * @return mixed
 */
function bluestone_userpoints_admin_page_calback() {

  $form = array();

  $form['bluestone_userpoints_on_subscribing_mission'] = array(
    '#type' => 'textfield',
    '#title' => t('Subscribing project'),
    '#default_value' => variable_get('bluestone_userpoints_on_subscribing_mission', 10)
  );

  $form['bluestone_userpoints_on_adding_comment'] = array(
    '#type' => 'textfield',
    '#title' => t('Adding comments'),
    '#default_value' => variable_get('bluestone_userpoints_on_adding_comment', 5)
  );

  $form['bluestone_userpoints_on_adding_measure_qualification'] = array(
    '#type' => 'textfield',
    '#title' => t('Adding a qualification on measure comment'),
    '#default_value' => variable_get('bluestone_userpoints_on_adding_measure_qualification', 10)
  );

  $form['bluestone_userpoints_on_adding_node_measurement'] = array(
    '#type' => 'textfield',
    '#title' => t('Adding a measurement'),
    '#default_value' => variable_get('bluestone_userpoints_on_adding_node_measurement', 1)
  );

  $form['bluestone_userpoints_on_adding_node_og_document'] = array(
    '#type' => 'textfield',
    '#title' => t('Adding a shared document'),
    '#default_value' => variable_get('bluestone_userpoints_on_adding_node_og_document', 20)
  );

  $form['bluestone_userpoints_on_adding_node_og_wiki'] = array(
    '#type' => 'textfield',
    '#title' => t('Adding a wiki page'),
    '#default_value' => variable_get('bluestone_userpoints_on_adding_node_og_wiki', 20)
  );

  $form['bluestone_userpoints_on_adding_node_mission'] = array(
    '#type' => 'textfield',
    '#title' => t('Adding a mission'),
    '#default_value' => variable_get('bluestone_userpoints_on_adding_node_mission', 20)
  );




  return system_settings_form($form);
}