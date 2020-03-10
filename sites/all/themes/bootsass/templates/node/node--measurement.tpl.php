<?php //krumo($content) ?>
<?php //krumo(get_defined_vars()) ?>
<?php
hide($content['comments']);
hide($content['links']);
?>
<div class="row node-measurement-wrapper">
  <div class="node-measurement-<?php print $view_mode ?> col-md-12 nopadding">
    <!--
        <div class="row">
            <div class="col-md-12 title">
                <?php print check_plain($node->title) ?>
            </div>
        </div>
        -->
    <div class="row measurement-datas">

      <div class="col-md-7 map">
        <h2> <?php print t('Measured radiation') ?> </h2>
        <div class="map-inner-wrapper">
          <?php print render($content["field_value"]) ?>
          <div id="map-view-measurement"> </div>

          <link rel="stylesheet" href="/sites/all/libraries/leaflet/leaflet.css">
          <script src="/sites/all/libraries/leaflet/leaflet.js"></script>
          <style>
             #map-view-measurement {
               width: 100%;
               height: 300px;
              }
         </style>
          <script>
             map = L.map('map-view-measurement').setView([<?php print check_plain($content['field_geolocalisation']['#items'][0]['lat']) ?>, <?php print check_plain($content['field_geolocalisation']['#items'][0]['lng']) ?>], 7);

             L.tileLayer('https://a.tile.openstreetmap.fr/osmfr/{z}/{x}/{y}.png', {// see http://wiki.openstreetmap.org/wiki/FR:Serveurs/tile.openstreetmap.fr
                attribution: '&copy; <a href=\"\/\/osm.org\/copyright\">OpenStreetMap<\/a> - <a href=\"\/\/openstreetmap.fr\">OSM France<\/a> '
             }).addTo(map);
             L.marker(L.latLng(<?php print check_plain($content['field_geolocalisation']['#items'][0]['lat']) ?>, <?php print check_plain($content['field_geolocalisation']['#items'][0]['lng']) ?>)).addTo(map);

          </script>

        </div>
      </div>

      <div class="col-md-5 info">
        <?php if(isset($content["field_calculated_qualification"])): ?>
          <?php
          $tid = $node->field_calculated_qualification[LANGUAGE_NONE][0]['tid'];
          $term = taxonomy_term_load($tid);
          ?>
          <div id="ajax-recalculated-qualification-term-wrapper" style="background-color:<?php if (!empty($term->field_color[LANGUAGE_NONE][0]["rgb"])) print check_plain($term->field_color[LANGUAGE_NONE][0]["rgb"]) ?>;" class="field field-name-field-calculated-qualification field-type-taxonomy-term-reference field-label-hidden">
            <div class="field-items">
              <div id="ajax-recalculated-qualification-term" class="field-item even">
                <?php print t(check_plain($term->name)) ?>
              </div>
            </div>
          </div>
        <?php endif; ?>

        <div class="row margint15">
          <div class="col-md-6 username nopadding">
            <?php //$u = user_load($node->uid); print check_plain($u->name);?>
              <?php print render($content["field_creator_name"]) ?>
          </div>
          <div class="col-md-6 subscribe nopadding">
            <?php print render($content["flag_subscribe_node"]) ?>
          </div>
          <div class="col-md-12 nopadding">
            <ul class="list-unstyled details">
              <li></li>
              <li><span class="atypical"><?php if (isset($content['field_atypical_measurement']['#items'][0]['value']) && ("1" == $content['field_atypical_measurement']['#items'][0]['value'])) print t('Atypical measurement') ?></span></li>
              <li><span class="blabel"><?php print t('Beginning date') ?> : </span><?php print format_date($content["field_time"]['#items'][0]['value'], $type = 'custom', $format = 'l, j F, Y - H:i:s') ?></li>
              <li><span class="blabel"><?php print t('Measurement duration : ') ?></span><?php
                  $date1 = $content["field_time"]['#items'][0]['value'];
                  $date2 = $content["field_time"]['#items'][0]['value2'];
                  if (empty($content["field_time"]['#items'][0]['value2']) || ($date1 == $date2) ) {
                    print t(' - ');
                  } else {
                    $newdate1 = new DateObject($date1);
                    $newdate2 = new DateObject($date2);
                    $interv = time_elapsed2($newdate1, $newdate2);
                    print render($interv);
                  }
                  ?>
                  </li>
              <li><span class="blabel"><?php print t('Measurement environment') ?> : </span><?php print render($content["field_measurementenvironment"]) ?></li>
              <li>
                <span class="blabel"><?php
                  if (empty(check_plain($content['field_geolocalisation']['#items'][0]['refinedLat']))) {
                  print t('Latitude')?> :</span>
                <?php print check_plain($content['field_geolocalisation']['#items'][0]['lat']); }
                else {  ?>
                  <span class="blabel"><?php print t('Latitude Refined') ?> :</span><?php showIfExist(check_plain($content['field_geolocalisation']['#items'][0]['refinedLat']));
                }?>
              </li>
              <li>
                <span class="blabel"><?php
                  if (empty(check_plain($content['field_geolocalisation']['#items'][0]['refinedLng']))) {
                  print t('Longitude')?> :</span>
                <?php print check_plain($content['field_geolocalisation']['#items'][0]['lng']); }
                else {  ?>
                  <span class="blabel"><?php print t('Longitude Refined') ?> :</span><?php showIfExist(check_plain($content['field_geolocalisation']['#items'][0]['refinedLng']));
                }?>
              </li>
              <li>
                <span class="blabel"><?php print t('Distance travel during measure') ?> :</span> <?php
                  $duration = time_getDiffInSecond($content["field_time"]['#items'][0]['value2'],$content["field_time"]['#items'][0]['value']);
                  $distance = getDistance($content);
                  if($distance != null){
                    print $distance?>m (<?php
                    print getSpeed($distance, $duration);
                  ?> km/h)
                  <?php } else {
                    print ' - ';
                  } ?>
              </li>

              <?php
              if ($content["field_measurementenvironment"][0]['#markup'] == 'Plane' || $content["field_measurementenvironment"][0]['#markup'] == 'Avion') {
                showItemsPlane($content);
              } else {
                showRain($content);
              } ?>

              <li><span class="blabel"><?php print t('Tags') ?> : </span><?php print render($content['field_measure_tags']) ?></li>
              <li><span class="blabel"><?php print t('Description') ?> : </span><span class="description"><?php print render($content['field_description']) ?></span></li>
              <li style="text-align:center; display:block;"><?php print render($content['field_measurement_photo']) ?></li>
              <li style="text-align:center; color:black; display:block;" class="small"><?php if (isset($content['field_measurement_photo'])) print t('CC-BY-SA-NC 4.0 '. render($content["field_creator_name"]) . '/openradiation'); ?></li>

              <div style="display: none" id="js-measurement-all-metadatas-wrapper">
                <li><span class="blabel"><?php print t('Measurement height above the ground (m)') ?> : </span><?php print render($content['field_measurement_height']) ?></li>
                <li><span class="blabel"><?php print t('Temperature') ?> : </span><?php print render($content['field_temperature']) ?></li>
                <li><span class="blabel"><?php print t('Hits number') ?> : </span><?php print render($content['field_hits_number']) ?></li>
                <li><span class="blabel"><?php print t('Altitude (m)') ?> : </span><?php print render($content['field_altitude']) ?></li>
                <li><span class="blabel"><?php print t('Measurement UUID') ?> : </span><?php print $node->uuid; ?></li>
                <li><span class="blabel"><?php print t('Manual Reporting') ?> : </span><?php if ("1"==$content['field_manual_reporting']['#items'][0]['value']) print t('Yes'); else print t('No'); ?></li>

                <li><span class="blabel"><?php print t('Sensor / ID') ?> : </span><?php print render($content['field_apparatus_id']) ?></li>
                <li><span class="blabel"><?php print t('Sensor / Version') ?> : </span><?php print render($content['field_apparatus_version']) ?></li>
                <li><span class="blabel"><?php print t('Sensor / Type') ?> : </span><?php print render($content['field_apparatus_sensor_type']) ?></li>
                <li><span class="blabel"><?php print t('Sensor / Tube Type') ?> : </span><?php print render($content['field_apparatus_tube_type']) ?></li>

                <li><span class="blabel"><?php print t('Smartphone / UUID') ?> : </span><?php print render($content['field_device_uuid']) ?></li>
                <li><span class="blabel"><?php print t('Smartphone / Platform') ?> : </span><?php print render($content['field_device_platform']) ?></li>
                <li><span class="blabel"><?php print t('Smartphone / Model') ?> : </span><?php print render($content['field_device_model']) ?></li>
                <li><span class="blabel"><?php print t('Smartphone / Version') ?> : </span><?php print render($content['field_device_version']) ?></li>
                <li><span class="blabel"><?php print t('Software') ?> : </span><?php print render($content['field_organisation_reporting']) ?></li>
              </div>


              <span class="btn btn-primary" id="js-measurement-see-all-metadatas-show-button" href="#"><?php print t('More'); ?></span>
              <span class="btn btn-primary" style="display: none;" id="js-measurement-see-all-metadatas-hide-button" href="#"><?php print t('Less'); ?></span>

            </ul>
          </div>
        </div>
      </div>
    </div>


    <div class="node-measurement-comments">
      <div class="row">
        <div class="col-md-12 nopadding">
          <?php print render($content['comments']); ?>
        </div>
      </div>
    </div>


  </div>

</div>

<?php
  function showIfExist($thingsToShow) {
    empty($thingsToShow) ? print t(' - ') : print t($thingsToShow);
  }

function getDistance($data){
  $lat1C = (float) check_plain($data['field_geolocalisation']['#items'][0]['refinedLat']) * pi()/180;
  $lon1C = (float) check_plain($data['field_geolocalisation']['#items'][0]['refinedLng']) * pi()/180;
  $lat1 = (float) check_plain($data['field_geolocalisation']['#items'][0]['lat']) * pi()/180;
  $lon1 = (float) check_plain($data['field_geolocalisation']['#items'][0]['lng']) * pi()/180;

  $lat2C = (float) check_plain($data['field_geolocalisation']['#items'][0]['refinedLatEnd']) * pi()/180;
  $lon2C = (float) check_plain($data['field_geolocalisation']['#items'][0]['refinedLngEnd']) * pi()/180;
  $lat2 = (float) check_plain($data['field_geolocalisation']['#items'][0]['latEnd']) * pi()/180;
  $lon2 = (float) check_plain($data['field_geolocalisation']['#items'][0]['lngEnd']) * pi()/180;

      $latStart = $lat1C > 0 ? $lat1C : $lat1;
      $latEnd = $lat2C > 0 ? $lat2C : $lat2;
      $lonStart = $lat1C > 0 ? $lon1C : $lon1;
      $lonEnd = $lat2C > 0 ? $lon2C : $lon2;

      $result = acos(sin($latStart)*sin($latEnd) + cos($latStart)*cos($latEnd)*cos($lonStart-$lonEnd));

      if($latEnd < 0) {
        $alt = (float) check_plain($data['field_altitude']);
        if ($alt > 0) {
          $result = $result * (6366*1000 + $alt);
        } else {
          $result = $result * (6366*1000);
        }
        return round($result, 0);
      } else {
        return null;
      }
  }

  /**
   * @param $d distance (meters)
   * @param $s duration (seconds)
   *
   * return speed (km/h)
   */
  function getSpeed($d, $s) {
    return round((($d*3600)/($s*1000)),0);
  }

    // show if measurement environment is not plane
  function showRain($content) {
    echo '<li><span class="blabel">';
    print t('Weather');
    echo " : </span><img src='/sites/all/themes/bootsass/assets/images/icon-rain-on.png' width='20' height='20' style='vertical-align: top;' > ";
    print t($content["field_rain"][0]['#markup']);
    print '</li>';
  }

  // show if measurement environment is plane
  function showItemsPlane($content) {
    echo '<li><span class="blabel">';
    print t('Weather');
    echo " : </span><img src='/sites/all/themes/bootsass/assets/images/icon-plane-storm-on.png' width='20' height='20' style='vertical-align: top;' > ";
    print render($content['field_storm'][0]['#markup']);
    print '</li>';

    echo '<li><span class="blabel">';
    print t('Seat position');
    echo ": </span><img src='/sites/all/themes/bootsass/assets/images/icon-window-on.png' width='20' height='20' style='vertical-align: top;' > ";
    print render($content["field_window_seat"][0]['#markup']);
    print '</li>';

    echo '<li><span class="blabel">';
    print t('Flight number');
    echo ' : </span>';
    print render($content['field_flight_number'][0]['#markup']);
    print '</li>';

    echo '<li><span class="blabel">';
    print t('Seat number');
    echo ' : </span>';
    print render($content['field_seat_number'][0]['#markup']);
    print '</li>';
  }
?>
