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
              <li><span class="atypical" ><?php if (isset($content['field_atypical_measurement']['#items'][0]['value']) && ("1" == $content['field_atypical_measurement']['#items'][0]['value'])) print t('Atypical measurement') ?></span></li>
              <li><span class="blabel"><?php print t('Beginning date') ?> : </span><?php print format_date($content["field_time"]['#items'][0]['value'], $type = 'custom', $format = 'l, j F, Y - H:i:s') ?></li>
              <li><span class="blabel"><?php print t('Latitude') ?> : </span><?php print check_plain($content['field_geolocalisation']['#items'][0]['lat']) ?></li>
              <li><span class="blabel"><?php print t('Longitude') ?> : </span><?php print check_plain($content['field_geolocalisation']['#items'][0]['lng']) ?></li>
              <li><span class="blabel"><?php print t('Altitude (m)') ?> : </span><?php print render($content['field_altitude']) ?></li>             
              <li><span class="blabel"><?php print t('Measurement duration : ') ?></span><?php
                  $date1 = $content["field_time"]['#items'][0]['value'];
                  $date2 = $content["field_time"]['#items'][0]['value2'];
                  if (empty($content["field_time"]['#items'][0]['value2']) || ($date1 == $date2) ) {
                    print t(' - ');   /*print t('NA');*/
                  } else {
                    $newdate1 = new DateObject($date1);
                    $newdate2 = new DateObject($date2); 
                    $interv = time_elapsed2($newdate1, $newdate2);
                    print render($interv);
                  }
                  ?>
              </li>             

              <li><span class="blabel"><?php print t('Distance travelled during measurement') ?> : </span>
              <?php if (!empty($content["field_geolocalisation2"]['#items'][0]['lat']) && !empty($content["field_geolocalisation2"]['#items'][0]['lng'])) {
 		$lat = (float) check_plain($content['field_geolocalisation']['#items'][0]['lat']) * pi()/180;
  		$lng = (float) check_plain($content['field_geolocalisation']['#items'][0]['lng']) * pi()/180;
                $latEnd = (float) check_plain($content['field_geolocalisation2']['#items'][0]['lat']) * pi()/180;
                $lngEnd = (float) check_plain($content['field_geolocalisation2']['#items'][0]['lng']) * pi()/180;
		$alt = 0;
		if (isset($content['field_altitude']['#items'][0]['value'])) {
			$alt = (float) check_plain($content['field_altitude']);
		}
      		$distance = round(acos(sin($lat)*sin($latEnd) + cos($lat)*cos($latEnd)*cos($lng-$lngEnd))  * (6366*1000 + $alt), 0);
		print $distance;
		print (' m');
		if (!empty($content["field_time"]['#items'][0]['value2']) && ($date1 != $date2) ) {
		   $duration = $newdate2->getTimestamp() - $newdate1->getTimestamp();
                   $speed = round(($distance/1000)/($duration/3600),0); 
                   print(' (');
                   print($speed);
		   print(' km/h)');
                } 
	      } ?>	
	      </li>
              <li><span class="blabel"><?php print t('Measurement environment') ?> : </span><?php print render($content["field_measurementenvironment"]) ?></li>
              <?php
              if ($content["field_measurementenvironment"][0]['#markup'] == 'Plane' || $content["field_measurementenvironment"][0]['#markup'] == 'Avion') {
		print ('<li><span class="blabel">');
    		print t('Flight number');
    		print (' : </span>');
    		print render($content['field_flight_number']);
    		print ('</li>');

    		print ('<li><span class="blabel">');
    		print t('Seat number');
    		print (' : </span>');
    		print render($content['field_seat_number']);
    		print ('</li>');

   		print('<li><span class="blabel" >');
    		print t('Weather');
    		print(' : </span>');
    		if (isset($content['field_storm']['#items'][0]['value'])) {
        		if ("1" == $content['field_storm']['#items'][0]['value']) {
               			print("<img src='/sites/all/themes/bootsass/assets/images/icon-plane-storm-on.png' width='20' height='20' style='vertical-align: top;' /> ");
                		print t('Storm crossing');
       			} else {
                		print("<img src='/sites/all/themes/bootsass/assets/images/env_plane.png' width='20' height='20' style='vertical-align: top;' /> ");
                		print t('No storm');
        		}
     		}
    		print ('</li>');

    		print('<li><span class="blabel" >');
    		print t('Seat position');
    		print(' : </span>');
    		if (isset($content['field_window_seat']['#items'][0]['value'])) {
        		if ("1" == $content['field_window_seat']['#items'][0]['value']) {
                		print("<img src='/sites/all/themes/bootsass/assets/images/icon-window-on.png' width='20' height='20' style='vertical-align: top;' /> ");
                		print t('Window');
        		} else {
                		print("<img src='/sites/all/themes/bootsass/assets/images/icon-aisle-on.png' width='20' height='20' style='vertical-align: top;' /> ");
                		print t('Aisle/Middle');
        		}
     		}
    		print ('</li>'); 		
              
	     } else {
		print('<li><span class="blabel" >');
    		print t('Weather');
    		print(' : </span>');
    		if (isset($content['field_rain']['#items'][0]['value'])) {
        		if ("1" == $content['field_rain']['#items'][0]['value']) {
                		print("<img src='/sites/all/themes/bootsass/assets/images/icon-rain-on.png' width='20' height='20' style='vertical-align: top;' /> ");
                		print t('Rain');
        		} else {
                		print("<img src='/sites/all/themes/bootsass/assets/images/icon-sun-on.png' width='20' height='20' style='vertical-align: top;' /> ");
                		print t('No rain');
        		}
     		}
    		print ('</li>');
              } ?>

              <li><span class="blabel"><?php print t('Tags') ?> : </span><?php print render($content['field_measure_tags']) ?></li>
              <li><span class="blabel"><?php print t('Description') ?> : </span><span class="description"><?php print render($content['field_description']) ?></span></li>
              <li style="text-align:center; display:block;"><?php print render($content['field_measurement_photo']) ?></li>
              <li style="text-align:center; color:black; display:block;" class="small"><?php if (isset($content['field_measurement_photo'])) print t('CC-BY-SA-NC 4.0 '. render($content["field_creator_name"]) . '/openradiation'); ?></li>

              <div style="display: none" id="js-measurement-all-metadatas-wrapper">
                <li><span class="blabel"><?php print t('Measurement height above the ground (m)') ?> : </span><?php print render($content['field_measurement_height']) ?></li>
                <li><span class="blabel"><?php print t('Temperature') ?> : </span><?php print render($content['field_temperature']) ?></li>
                <li><span class="blabel"><?php print t('Hits number') ?> : </span><?php print render($content['field_hits_number']) ?></li>
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
                <!--
                <li><span class="blabel"><?php print t('Environment') ?> : </span><?php print render($content['field_measurement_environment']) ?></li>
                <li><span class="blabel"><?php print t('Qualification votes number') ?> : </span><?php print render($content['field_qualification_votes_number']) ?></li>
                <li><span class="blabel"><?php print t('Reliability') ?> : </span><?php print render($content['field_reliability']) ?></li>
                -->
                
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



