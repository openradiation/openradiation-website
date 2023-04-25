<?php
/**
 * Simulate openradiation API remote server.
 *
 * Services are mocked until real remote API is available.
 *
 * We simulate also api key check ( @see OPENRADIATION_API_KEY constant )
 */

define("OPENRADIATION_API_KEY", "LucyInTheSkyWithDiamonds");

/**
 * Helper function to simulate control of api key
 * @param $api_key
 */
function webservices_mock_check_api_key($api_key) {
  if ($api_key != OPENRADIATION_API_KEY) {
    drupal_add_http_header('Status', 403);
    print json_encode(array('error' => array('code' => 'invalid_api_key', 'title' => 'Invalid api key')));
    exit;
  }
}

/**
 * Menu callback for api/measurements/%
 * Get one measure from server API
 *
 * @param $uuid
 */
function openradiation_mock_api_get_measurement_page_callback($uuid) {

  if (isset($_GET['apiKey'])) {}
  webservices_mock_check_api_key($_GET['apiKey']);

  $store = openradiationMockApiMeasureStorage::getInstance();
  $datas = $store->get($uuid);

  if (!$datas) {
    drupal_add_http_header('Status', 404);
    print json_encode(array('error' => array('code' => 404, 'title' => 'measurement not found')));
    exit;
  }

  $result = array('data' => $datas);
  bluestone_send_json_response($result);

}

/**
 * Menu page callback for api/measurements
 *
 * for GET method : get all measurements from openradiation API
 * for POST method : create a new measurement to openradiation database.
 */
function openradiation_mock_api_measurements_page_callback() {

  if ($_SERVER['REQUEST_METHOD'] == 'GET') {
    webservices_mock_check_api_key($_GET['apiKey']);
    $store = openradiationMockApiMeasureStorage::getInstance();
    drupal_add_http_header('Content-type', 'application/json; charset=utf-8');
    print json_encode(array('data' =>  $store->getAll()));
    exit;
  }

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $datas = json_decode(file_get_contents('php://input'));
    webservices_mock_check_api_key($datas->apiKey);

    $store = openradiationMockApiMeasureStorage::getInstance();
    $existing = $store->get($datas->data->reportUuid);

    if ($existing) {
      $store->update($datas->data);
      $notification = 'updated';
    }
    else {
      $store->create($datas->data);
      $notification = 'created';
    }
    
    //mettre à true pour générer fictivement une erreur
    if ($generate_error = false) {
        drupal_add_http_header('Status', 404);
        print json_encode(array('error' => array('code' => 404, 'title' => 'erreur générée exprès dans API')));
        exit;
    }

    $result = array(
      'notification' => $notification,
      'data' =>  $datas
    );
    bluestone_send_json_response($result);

  }

}

function openradiation_mock_api_users_page_callback() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $datas = json_decode(file_get_contents('php://input'));
    webservices_mock_check_api_key($datas->apiKey);
    $store = openradiationMockApiUserStorage::getInstance();
    $store->saveAll($datas->data);
    $stored_datas = $store->getAll();
    $result = array(
      'notification' => 'users received',
      'data' =>  $stored_datas
    );
    bluestone_send_json_response($result);

  }
}
