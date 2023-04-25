<?php
/**
 * Display a map with users location from their country
 * and postal code.
 *
 * @see bluestone_user.js in this module.
 */
?>
<link rel="stylesheet" href="/sites/all/libraries/leaflet/leaflet.css">
<script src="/sites/all/libraries/leaflet/leaflet.js"></script>
<style>
  #users-map-canvas {
    width: 100%;
    height: 400px;
  }
</style>

<div id="users-map-canvas"></div>
