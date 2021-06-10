<?php
/**
 * Bluestone mesures page callbacks
 */

/**
 * hook menu page callback for "import-measure"
 * This is where measurement are created from remote API, when user
 * click on a map marker on drupal site.
 *
 * Create a measurement node from json datas returned by remote API.
 *
 * @param int $uuid : measure uuid
 * @return string html
 */
function bluestone_measure_create_page_callback($uuid) {

  // check if we already have imported this node.
  $existing_node = bluestone_get_measure_node_by_measure_uuid($uuid);

  // we have already created a node for this measurement in our Drupal,
  // redirect user to his existing measure.
  if ($existing_node) {
    drupal_goto("node/" . check_plain($existing_node->nid));
  }

  // we have not yet created a node for this measurement, let's do it.
  // get measure datas from remote API
  $api = openradiationApi::getInstance();
  $response = $api->get("/measurements/$uuid"); 
  /* BLOC TEST - for testing purposes only */
  /*
  $test = '{"data":{"apparatusId":"EA:74:F2:F9:A1:6F","apparatusVersion":"OG-KIT11.0000010","apparatusSensorType":"geiger","apparatusTubeType":"SBM-20","temperature":28,"value":0.086,"hitsNumber":34,"startTime":"2016-12-06T10:54:33.000Z","endTime":"2016-12-06T10:55:56.000Z","latitude":48.7939462,"longitude":2.2763155,"deviceUuid":"dde828465a82183f","devicePlatform":"Android","deviceVersion":"5.0.2","deviceModel":"RIDGE 4G","reportUuid":"e51640cc-c805-4c44-b920-45c15b8e5510","manualReporting":false,"description":"mesure de test","measurementHeight":0,"userId":"ghis2","measurementEnvironment":"city","dateAndTimeOfCreation":"2016-12-06T10:57:38.578Z","qualification":"mustbeverified","qualificationVotesNumber":0,"reliability":94,"atypical":false,"tags":["ghis","hello","world"]}}';
  $response = json_decode($test, true);
  $measure_datas = $response['data'];
  $created_node = bluestone_create_measurement_node_from_webservice_datas($measure_datas);
  return;
  */

  // is status code is different than 2**
  if (substr($response->getStatusCode(), 0, 1) != '2') {
    drupal_add_http_header("Status", $response->getStatusCode());
    watchdog('bluestone_mesures',  "Error returned by api server while fetching mesure, server responded: " . check_plain($response->getStatusCode() . ' ' . $response->getReasonPhrase()), array(), WATCHDOG_WARNING);
    return t("Measure data not found.");
  }

  if (empty(json_decode($response->getBody(), true)['data'])) {
    return t("Empty data returned from server");
  }

  $measure_datas = json_decode($response->getBody(), true)['data'];

  // get users datas from remote API for this measure
  // $user_datas    = bluestone_webservice_get_user($measure_datas['user_uuid']);
  // create user in Drupal
  // $created_user  = bluestone_create_user_from_webservice_datas($user_datas);

  // create a drupal node from measures datas returned by openradiation API
  $created_node = bluestone_create_measurement_node_from_webservice_datas($measure_datas);

  // redirect user to this newly created node.
  if (!empty($created_node->nid)) {
    watchdog("bluestone_mesures", "node " . check_plain($created_node->nid) . " created");
    drupal_goto('node/'. check_plain($created_node->nid));
  }
  // something bad happens... log it
  else {
    watchdog('bluestone_mesures', "Node measurement creation failed. Measurement data received: @datas", array(
      '@datas' => var_export($measure_datas, TRUE)
      ));
  }

}

/**
 * Administration config form for our module.
 *
 * @return mixed
 */
function bluestone_mesures_services_config_form() {
  $form = array();

  $form['#validate'] = array('bluestone_mesures_services_config_form_validate');

  $form['help'] = array(
    '#type' => 'item',
    '#markup' => 'voir la documentation : <a target="_blank" href="https://github.com/openradiation/openradiation">https://github.com/openradiation/openradiation</a>'
    );

  $form['openradiation_server_rest_report_context'] = array(
    '#type' => 'select',
    '#title' => t('Report context'),
    '#options' => array('routine' => 'Routine', 'test' => 'Test'),
    '#default_value' => 'routine',
    '#description' => "<strong>Test</strong>: Only for tests: http requests will reach the remote API but reports won't be written to remote API database. <br/><strong>Routine</strong>: production mode, writes to remote API database"
    );

  $form['openradiation_server_rest_request_api_url'] = array(
    '#title' => "Base url for the request API rest server",
    //'#required' => TRUE,
    '#description' => 'for example : http://requestapi.openradiation.net or http://requestapi.openradiation.net/api etc ... <br/> For mocked webservices, use ' . $GLOBALS['base_url'] . '/mock-api',
    '#type' => 'textfield',
    '#default_value' => variable_get('openradiation_server_rest_request_api_url', $GLOBALS['base_url'] . '/mock-api')
    );
  $form['openradiation_server_rest_submit_api_url'] = array(
    '#title' => "Base url for the submit API rest server",
    //'#required' => TRUE,
    '#type' => 'textfield',
    '#description' => 'for example : http://submitapi.openradiation.net <br/> For mocked webservices, use For mocked webservices, use ' . $GLOBALS['base_url'] . '/mock-api',
    '#default_value' => variable_get('openradiation_server_rest_submit_api_url', $GLOBALS['base_url']. '/mock-api')
    );
  $form['openradiation_server_rest_api_key'] = array(
    '#title' => "Server api key.",
    '#type' => 'textfield',
    '#description' => 'You need an API key to call remote API webservices.',
    //'#required' => TRUE,
    '#default_value' => variable_get('openradiation_server_rest_api_key', 'LucyInTheSkyWithDiamonds')
    );
  $form['openradiation_server_rest_ping'] = array(
    '#title' => 'Test connection to server rest API',
    '#type' => 'submit',
    '#value' => "Test connection to server",
    '#submit' => ['openradiation_server_ping'],
    '#weight' => 99999
    );

  /*
  // This code is not needed anymore since now the real API is available;
  // Keep it for now, just in case ...
  if (module_exists('bluestone_mock_remote_api')) {
    if (!function_exists('kpr')) {
      drupal_set_message("You need to have devel module enabled to see the mock store");
    }
    $store = openradiationMockApiMeasureStorage::getInstance();
    $form['mock_store_reset'] = array(
      '#weight' => 998,
      '#value' => 'Reset mock store datas ',
      '#type' => 'submit',
      '#submit' => array('openradiation_api_mock_reset_datas')
    );

    // allow us to see what's in our mock openradiation api database.
    $store_view = '';
    if (function_exists('kpr')) {
      $store_view .= kpr($store->getAll(), TRUE);
    }
    $form['mock_store'] = array(
      '#weight' => 999,
      '#title' => 'open radiation API measurements mock storage : ',
      '#type' => 'item',
      '#markup' => $store_view,
    );

    $store = openradiationMockApiUserStorage::getInstance();
    $users_view = '';
    if (function_exists('kpr')) {
      $users_view .= kpr($store->getAll(), TRUE);
    }
    $form['mock_store_users'] = array(
      '#weight' => 1000,
      '#title' => 'open radiation API users mock storage : ',
      '#type' => 'item',
      '#markup' => $users_view,
    );
  }
  */

  return system_settings_form($form);
}

/**
 * Ping server api.
 */
function openradiation_server_ping() {
  drupal_set_message(" ... contacting " . variable_get('openradiation_server_rest_request_api_url' ) . "/measurements ...");
  $api = openradiationApi::getInstance();
  try {
    $response = $api->get("/measurements");
    drupal_set_message('Status code ' . $response->getStatusCode());
    //drupal_set_message(var_export($response, true));
  }
  catch (Exception $e) {
    drupal_set_message('Exception reçue : ' .  $e->getMessage(), 'warning');
  }
}

function bluestone_mesures_services_config_form_validate($form, &$form_state) {
  // remove trainling slashes, if any, at the end of urls before saving.
  $form_state['values']['openradiation_server_rest_request_api_url'] = trim($form_state['values']['openradiation_server_rest_request_api_url'], '/');
  $form_state['values']['openradiation_server_rest_submit_api_url'] = trim($form_state['values']['openradiation_server_rest_submit_api_url'], '/');
}
