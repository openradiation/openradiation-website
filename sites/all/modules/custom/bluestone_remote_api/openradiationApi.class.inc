<?php

/**
 * Class openradiationApi
 *
 * Use this class to request openradiation remote API.
 * It uses config from : admin/config/services/measurements
 *
 * This is build upon guzzle library (installed into "vendor" directory using composer)
 *
 * Example :
 * @code
 *
 *   // get json datas about measurements with reportUuid 28
 *   $api = openradiationApi::getInstance();
 *   $response = $api->get("/measurements/28");
 *
 *   // create a new measurement on remote API
 *   $api = openradiationApi::getInstance();
 *   $datas = array(
 *     'reportUuid' => '78fzgreg48',
 *     'Latitude' => '45.5359656',
 *     'Longitude' => '2.1500042999999778',
 *     'Value' => 0.124,
 *     'StartTime' => 1429697053
 *   )
 *   $response = $api->post("/measurements", $datas);
 *
 * @encode
 */
class openradiationApi {

  // url to get datas from remote API
  protected $request_server_url = '';

  protected $debug = true;

  // url to POST / PUT datas to remote API
  protected $submit_server_url = '';

  // api KEY to request openradiation webservices
  protected $api_key = '';

  // an http client to communicate with openradiation webservices, we use GUZZLE.
  protected $client = null;

  // our class is a singleton ...
  private static $_instance = NULL;

  /**
   * emergency, routine, exercise, test (default:test) :
   * - test:data are not registrated but you can test api use,
   * - emergency and exercise:not used,
   * - routine : you should use this one !
   */
  private $reportContext = 'routine';

  /**
   * Get settings from drupal configuration, create http client
   */
  private function __construct($reportContext = '') {

    if ($reportContext) {
      $this->reportContext = $reportContext;
    }
    else {
      $this->reportContext = trim(variable_get('openradiation_server_rest_report_context', $this->reportContext));
    }

    $this->request_server_url = trim(variable_get('openradiation_server_rest_request_api_url', ''));
    $this->submit_server_url = trim(variable_get('openradiation_server_rest_submit_api_url', ''));
    $this->api_key = trim(variable_get('openradiation_server_rest_api_key', ''));

    // Global configuration of our http client for openradiation webservices
    // base_url is not defined here because it is not the same base url
    // for POST and GET requests
    $this->client = new GuzzleHttp\Client([
      'defaults' => [
        'exceptions' => false, // remove exceptions causing fatal errors
        // by default, it is 0 ( = infinite )
        'timeout'    => 30,
        'verify' => false
      ]
    ]);
  }

  /**
   * Call the singleton
   */
  static function getInstance() {
    $class = __CLASS__;
    return self::$_instance ? self::$_instance : new $class();
  }

  /**
   * Perform a GET http request on openradiation remote API.
   *
   * @param string $path . example : "measurements/78945"
   * @return GuzzleHttp\Message\ResponseInterface
   */
  function get($path) {

    // get base url for remote api for http GET requests
    $url = $this->request_server_url . trim($path);

    // add api key
    $datas = [
      'apiKey' => $this->api_key,
      'response' => 'complete'
    ];

    // build url
    $url = url($url, ['query' => $datas, 'absolute' => TRUE]);

    // send request
    $response = $this->client->get($url);

    // log response
    if ($this->debug) {
      $log_flag = substr($response->getStatusCode(), 0, 1) == '2' ? WATCHDOG_NOTICE : WATCHDOG_ERROR;
      watchdog(
        __CLASS__,
        "API Http response @status from @url : @response =================> from HTTP GET REQUEST to @url with query params: @datas",
        [
          '@url' => $url,
          '@datas' => json_encode($datas, TRUE),
          '@status' => $response->getStatusCode(),
          '@response' => json_encode($response->json()),
        ],
        $log_flag
      );
    }
    return $response;
  }

  /**
   * Perform a post request on openradiation remote API
   *
   * @param string $path . example : "measurements" (to create a new measurement)
   * @param array $datas : array of datas that will be encoded to json in the body of http request
   * @return GuzzleHttp\Message\ResponseInterface
   */
  function post($path, $datas = []) {

    // get base url for remote API for http POST requests
    $url = $this->submit_server_url  . trim($path);


    $request_datas = [];
    // add api key
    $request_datas['apiKey'] = $this->api_key;

    // put datas in a "data" subkey
    $request_datas['data'] = $datas;
    $request_datas['data']['reportContext'] = $this->reportContext;

    // post http request
    $response = $this->client->post($url, ['json' => $request_datas]);

    if ($this->debug) {
    // $log_flag = $response->isSuccessful() ? WATCHDOG_NOTICE : WATCHDOG_ERROR;
      $log_flag = substr($response->getStatusCode(), 0, 1) == '2' ? WATCHDOG_NOTICE : WATCHDOG_ERROR;
      watchdog(
        __CLASS__,
        "API Http response @status from @url : @response =================> from HTTP POST REQUEST to @url with body: @posted_datas",
        [
          '@url' => $url,
          '@posted_datas' => json_encode($request_datas, TRUE),
          '@status' => $response->getStatusCode(),
          '@response' => json_encode($response->json()),
        ],
        $log_flag
      );
    }
    return $response;
  }

  /**
   * Perform a PUT http request
   *
   * @param $path
   * @param array $datas
   * @return \GuzzleHttp\Message\FutureResponse|\GuzzleHttp\Message\ResponseInterface|\GuzzleHttp\Ring\Future\FutureInterface|null
   */
  function put($path, $datas = []) {

    // get base url for remote API for http POST requests
    $url = $this->submit_server_url  . trim($path);

    $request_datas = [];
    // add api key
    $request_datas['apiKey'] = $this->api_key;

    // put datas in a "data" subkey
    $request_datas['data'] = $datas;
    $request_datas['reportContext'] = $this->reportContext;

    // post http request
    $response = $this->client->put($url, ['json' => $request_datas]);

    if ($this->debug) {
    //$log_flag = $response->isSuccessful() ? WATCHDOG_NOTICE : WATCHDOG_ERROR;
      $log_flag = substr($response->getStatusCode(), 0, 1) == '2' ? WATCHDOG_NOTICE : WATCHDOG_ERROR;
      watchdog(
        __CLASS__,
        "API Http response @status <br />from @url : <br />@response <br />=================> from HTTP PUT REQUEST to @url <br />with body: <br />@posted_datas",
        [
          '@url' => $url,
          '@posted_datas' => json_encode($request_datas, TRUE),
          '@status' => $response->getStatusCode(),
          '@response' => json_encode($response->json()),
        ],
        $log_flag
      );
    }
    return $response;

  }

}