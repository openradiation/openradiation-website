(function ($) {


  Drupal.behaviors.bluestonePopup = {

    attach: function(context, settings) {

      $('.bluestone-popup').click(function(event) {
        var width  = 575,
          height = 400,
          left   = ($(window).width()  - width)  / 2,
          top    = ($(window).height() - height) / 2,
          url    = this.href,
          opts   = 'status=1' +
            ',width='  + width  +
            ',height=' + height +
            ',top='    + top    +
            ',left='   + left;

        window.open(url, 'twitter', opts);

        return false;
      });

    }


  };

  Drupal.behaviors.bluestoneTooltips = {

    attach: function(context, settings) {
        // bootstrap tooltips
        $(".infobulle").tooltip();
    }

  };

  /**
   * Fix iframe displaying openradiation map, so that it always
   * has a 100% height
   * @type {{attach: attach}}
   */
  /*Drupal.behaviors.bluestoneOpenradiationMapAutoHeight = {

    attach: function(context, settings) {

      // try to adjust dynamically map height

        sizeOpenRadiationMap();


    }

  };

   */


  /**
   * Display title of the previous or next article on mouseover (arrows in headers)
   */
  Drupal.behaviors.bluestonePreviousNextArticle = {

    attach : function(context, settings) {

      $(".js-to-article").hover(
        // on mouse enter
        function() {
          var title_container = $(this).children('.js-title').first();
          title_container.show();
        },
        // on mouse hover
        function() {
          var title_container = $(this).children('.js-title').first();
          title_container.hide();
        }
      );

    }

  };


  /**
   * On measurements node type, display all metadatas about a measure
   * when wich click on a button to view all informations.
   * @type {{attach: attach}}
   */
  Drupal.behaviors.bluestoneMeasurementsSeeAllMetadatas = {

    attach : function(context, settings) {

      jQuery('#js-measurement-see-all-metadatas-show-button').click(function() {
        jQuery('#js-measurement-see-all-metadatas-show-button').hide();
        jQuery('#js-measurement-see-all-metadatas-hide-button').show();
        jQuery('#js-measurement-all-metadatas-wrapper').show();
      });

      jQuery('#js-measurement-see-all-metadatas-hide-button').click(function() {
        jQuery('#js-measurement-see-all-metadatas-hide-button').hide();
        jQuery('#js-measurement-see-all-metadatas-show-button').show();
        jQuery('#js-measurement-all-metadatas-wrapper').hide();
      });

    }

  };

  /**
   * Handle main menu slidedown / slideup
   *
   * @type {{attach: attach, getMaxHeight: getMaxHeight}}
   */
  Drupal.behaviors.bluestoneMainMenuSlideDown = {


    attach: function (context, settings) {

      var slideDuration = 200;

      var maxHeight = this.getMaxHeight();

      // @see js/jquery.hoverIntent.minified.js
      // fire dropdown if this is an "intentionnal hover" for opening menu
      // in other words : to not fire dropdown juste because user is hovering
      // the menu by accident, to access its browser bookmarks for example.
      $('#bluestone_main_menu').hoverIntent(

        // *** entering hover *** :
        function() {
          // do nothing if menu is already expanded by slidedown
          var state = $('#bluestone_main_menu').attr('state');
          if (state === 'open') {
            return;
          }
          // else, open children menu items with a slidedown effect :
          // mark the menu as open
          $('#bluestone_main_menu').attr('state', 'open');
          // set the same height for all columns
          $('.bluestone_menu_column .bluestone_sublinks').height(maxHeight);
          // make children menu items appears
          $('#bluestone_main_menu .bluestone_sublinks').slideDown(slideDuration);
        },

        // *** end of hovering *** :
        function() {
          $('#bluestone_main_menu .bluestone_sublinks').slideUp(slideDuration);
          $('#bluestone_main_menu').attr('state', 'closed');
        }
      );

    },

    getMaxHeight: function() {
      var max = 0;
      $('.bluestone_menu_column .bluestone_sublinks').each(function(){
        var height = $(this).height();
        if (height > max) {
          max = height;
        }
      });
      return max;
    }

  };


})(jQuery);
