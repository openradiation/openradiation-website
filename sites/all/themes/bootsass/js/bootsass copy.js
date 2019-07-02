(function($) {
	
	// Basic stuff
	Drupal.behaviors.bootsassStuff = {
		attach: function(context, settings) {
			
			// prevent the # links to scroll to the top of the page
			$("[href=#]").click(function(e) {
				e.preventDefault();
			});
			
			
			// Ouverture des liens externes dans une nouvelle fenêtre
			$('a').filter(function() {
				return this.hostname && this.hostname !== location.hostname;
			}).attr('target', '_blank');
			
			
			// animation, via module animate_css
			// demo http://jackilyn.github.io/animate.scss/
			// home #1
			$('.mod').addClass('animated fadeInRight');
			// home #2
			$('.cta').addClass('animated bounceInLeft');
			// agenda
			$('.listing_agenda-block_1 .views-row').addClass('animated bounce');
			// images photo galerie
			$('.photoswipe-gallery .field__item').addClass('animated bounceIn');
			
			
			// animation au scroll/viewport via module Gazwal Dev7 WOW
			// home #1 #2
			$('.listing_news-block_2 .views-row').addClass('wow fadeInUp');
			// actualités
			$('.listing_news-block_1 .views-row').addClass('wow fadeInUpBig');
			
			
			// Table des matières pour les CT page_structu
			// ../preprocess/page.preprocess.inc
			// http://stackoverflow.com/questions/7717527/jquery-smooth-scrolling-when-clicking-an-anchor-link
			var $root = $('html, body');
			$('.toc-link').click(function() {
				$root.animate({
					
					// version normal sans #header en Stiky + table des matières sticky
					// scrollTop: $( $.attr(this, 'href') ).offset().top - $('.page-toc').outerHeight()
					
					// version avec uniquement #header en Stiky
					//scrollTop: $($.attr(this, 'href')).offset().top - $('#header').outerHeight()}, 800);
					
					// version avec navigation sticky #header + table des matières sticky
					scrollTop: $($.attr(this, 'href')).offset().top - $('#header').outerHeight() - $('.page-toc').outerHeight()
					
					// l'effet de easing ci-dessous fonctionne que si le module UiToTop est activé, car il charge le easing.js
				//}, 1000, 'easeOutQuart');
				}, 800);
				return false;
			});
		} // end 
	}; // Basic stuff



})(jQuery);


    function init() {
        window.addEventListener('scroll', function(e){
            var distanceY = window.pageYOffset || document.documentElement.scrollTop,
                shrinkOn = 200,
                header = document.querySelector("header");
            if (distanceY > shrinkOn) {
                classie.add(header,"smaller");
            } else {
                if (classie.has(header,"smaller")) {
                    classie.remove(header,"smaller");
                }
            }
        });
    }
    window.onload = init();


// Google maps
jQuery(window).load(function() {
	"use strict";
	if (document.getElementById('map_canvas')) {
		var gLatitude = Drupal.settings['settings']['google_latitude'];
		var gLongitude = Drupal.settings['settings']['google_longitude'];
		var gZoom = Drupal.settings['settings']['google_zoom'];
		var gTitle = Drupal.settings['settings']['google_title'];
		var gDescription = Drupal.settings['settings']['google_description'];
		var apex_base_url = Drupal.settings['settings']['apex_base_url'];
		var latlng = new google.maps.LatLng(gLatitude, gLongitude);
		var settings = {
			zoom: parseInt(gZoom),
			center: latlng,
			scrollwheel: false,
			// draggable : important sous mobile
			// http://stackoverflow.com/questions/12538125/disable-movable-gmap
			draggable: false,
			mapTypeControl: true,
			mapTypeControlOptions: {
				style: google.maps.MapTypeControlStyle.DROPDOWN_MENU
			},
			navigationControl: true,
			navigationControlOptions: {
				style: google.maps.NavigationControlStyle.SMALL
			},
			mapTypeId: google.maps.MapTypeId.ROADMAP
		};
		var map = new google.maps.Map(document.getElementById("map_canvas"), settings);
		var companyLogo = new google.maps.MarkerImage(apex_base_url + '/sites/all/themes/apex/images/google-maps/map-marker.png', new google.maps.Size(20, 30), new google.maps.Point(0, 0), new google.maps.Point(10, 30));
		var companyMarker = new google.maps.Marker({
			position: latlng,
			map: map,
			icon: companyLogo,
			title: gTitle
		});
		var contentString = '<div id="content-map">' + '<h3 style="margin-top: 0px;">' + gTitle + '</h3>' + '<p>' + gDescription + '</p>' + '</div>';
		var infowindow = new google.maps.InfoWindow({
			content: contentString
		});
		google.maps.event.addListener(companyMarker, 'click', function() {
			infowindow.open(map, companyMarker);
		});
	}
});