(function ($) {

  "use strict";

  /**
   * Display user informations when hovering a user name.
   *
   * @type {{attach: attach}}
   */
  Drupal.behaviors.bluestoneUserModal = {

    attach: function(context, settings) {

    }

  };

  /**
   * Display a map of openradiation users, geolocalized by their postal code and country.
   */
  Drupal.behaviors.bluestoneUsersMap = {

    users: null,
    nextUser: null,
    delay: null,
    infowindow: null,
    map: null,

    /**
     * this function is called automatically by Drupal.
     */
    attach: function (context, settings) {
      var that = this;

      that.users = [];
      that.getAllUsers()
          .done(function(users) {
            users.forEach(function(user) {
              if(user) {
                var address = user.postalCode
                if (address) {
                  that.users.push(user);
                };
              }

            });

            that.map = L.map('users-map-canvas').setView([46.227638, 2.213749], 5);

            L.tileLayer('https://a.tile.openstreetmap.fr/osmfr/{z}/{x}/{y}.png', {// see http://wiki.openstreetmap.org/wiki/FR:Serveurs/tile.openstreetmap.fr
               attribution: '&copy; <a href=\"\/\/osm.org\/copyright\">OpenStreetMap<\/a> - <a href=\"\/\/openstreetmap.fr\">OSM France<\/a> '
            }).addTo(that.map);

            that.nextUser = 0;
            that.delay = 100;
            that.theNext();

          })

          .fail(function(response) {
            alert("getting users : error " + response.status);
          });

    },

    geocodeAddress: function (user) {
      var that = this;
      var address = '';
      if(user && user.postalCode) {
         address = encodeURIComponent(user.postalCode); // + ' ' + user.country;

         var xmlHttp = new XMLHttpRequest();
         xmlHttp.onreadystatechange = function() { 
             if (xmlHttp.readyState == 4 && xmlHttp.status == 200) {
                var theResponse = JSON.parse(xmlHttp.responseText);
                if (theResponse.length > 0 && theResponse[0].centre) {
                   var lon = theResponse[0].centre.coordinates[0] + (Math.random()-0.5) / 100;
                   var lat = theResponse[0].centre.coordinates[1] + (Math.random()-0.5) / 100;
              
                   var contentString = '<div style="text-align: center;">'
                    + user.picture + '</div><div style="padding: 10px;text-align: center;">'
                    + '<a href="' + user.link + '">'
                    + user.name + '</a></div>';
          
                   L.marker(L.latLng(lat, lon)).addTo(that.map)
                      .bindPopup(contentString);
                }

                that.theNext();
             }
         }
         xmlHttp.open("GET", "https://geo.api.gouv.fr/communes?codePostal=" + address + "&fields=centre", true); // true for asynchronous 
         xmlHttp.send(null);
      } else {
         that.theNext();
      }
   },


    theNext: function () {
      var that = this;
      if (that.nextUser < that.users.length) {
        setTimeout(function() {
          that.geocodeAddress(that.users[that.nextUser]);
        }, that.delay);
        that.nextUser++;
      }  
    },

    getAllUsers: function() {
      return $.get("/api/users");
    }

  }


})(jQuery);
