<?php
/**
 * @file
 * Default microdata theme implementation for a geolocation with latitude, longitude.
 *
 * Available variables:
 * - $lat: The latitude value.
 * - $lng: The longitude value.
 *
 */
?>
<span itemscope itemtype="http://schema.org/GeoCoordinates">
  <meta itemprop="latitude" content="<?php print $lat; ?>">
  <meta itemprop="longitude" content="<?php print $lng; ?>">
  <span class="geolocation-latlng"><?php print $lat; ?>, <?php print $lng; ?></span>
</span>
