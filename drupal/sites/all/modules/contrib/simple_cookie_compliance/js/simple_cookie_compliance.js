(function($) {
  Drupal.behaviors.simple_cookie_compliance = {
    attach: function () {
      // Show cookie compliance message if the cookie is not set.
      if (document.cookie.indexOf('simple_cookie_compliance_dismissed=') == -1) {
        $('#cookie-compliance').show();
      }
    }
  }
}(jQuery));
