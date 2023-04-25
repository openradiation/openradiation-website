<!-- ! Home Carte de France des mesures -->
<?php
/*print theme('image', array(
    'path' => drupal_get_path('theme', 'bootsass') . '/images/carte-homepage.jpg',
     'width' => '100%'
  ))
*/
global $language;
$url = variable_get('openradiation_server_rest_request_api_url', '');
print "<iframe id=\"openradiation-map-iframe\" frameborder=\"0\" style=\"overflow:hidden;height:100%;width:100%\" height=\"100%\" width=\"100%\" src=\"$url/$language->language/openradiation\"></iframe>";

?>

<!--<iframe id="openradiation-map-iframe" frameborder="0" style="overflow:hidden;height:100%;width:100%" height="100%" width="100%" src="https://request.open-radiation.net/openradiation"></iframe>
-->

