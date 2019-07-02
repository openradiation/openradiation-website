(function($) {

  // Basic stuff
  Drupal.behaviors.bootsass = {


    /**
     * Header template contains following html, allowing us
     * to detect with this function the current breakpoint of bootstrap:
     * <div class="device-xs visible-xs"></div>
     * <div class="device-sm visible-sm"></div>
     * <div class="device-md visible-md"></div>
     * <div class="device-lg visible-lg"></div>
     *
     * @param xs, sm, md or lg
     * @returns {*|Boolean|boolean}
     */
    isBreakpoint: function(alias) {
      return $('.device-' + alias).is(':visible');
    },

    footerEqualizer: function() {

      function equalizer() {
        if (Drupal.behaviors.bootsass.isBreakpoint('lg') || Drupal.behaviors.bootsass.isBreakpoint('md')) {
          $('.footer-inner > .row').equalize();
        }
        else {
          // remove height set by equalize() jquery plugin
          $('.footer-inner > .row > div').height('auto');
        }
      }

      // equalize only on the breakpoints we want.
      // when window is rezised, remove equalization if needed.
      equalizer();
      $(window).resize(function () {
        equalizer();
      });


    },

    attach: function(context, settings) {

      // prevent the # links to scroll to the top of the page
      $("[href=#]").click(function(e) {
        e.preventDefault();
      });


      // Ouverture des liens externes dans une nouvelle fenêtre
      $('a').filter(function() {
        return this.hostname && this.hostname !== location.hostname;
      }).attr('target', '_blank');


      this.footerEqualizer();


    } // end
  }; // Basic stuff
})(jQuery);