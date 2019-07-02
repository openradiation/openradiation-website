(function ($) {

  // do not use drupal behaviors for that, or our functions will be called too many times.
  //
  // Quand on clique sur un pouce de vote, lancer en ajax le recalcul de la qualification.
  $(document).bind('eventAfterRate', function(event, data) {

    var base_url = Drupal.settings.basePath + Drupal.settings.pathPrefix;
    var url = base_url + 'api/measurements/qualifications/calculate/' + data.content_type + '/' + data.content_id + '/' + data.widget_id;

    $.get(url, function(response) {
      // update qualification on top of the node, changing term name and color
      if (typeof response.data.term !== "undefined") {
        $('#ajax-recalculated-qualification-term-wrapper').css("background", response.data.term.field_color.und[0].rgb);
        $('#ajax-recalculated-qualification-term').html(response.data.term.name);
      }
    });

  });



})(jQuery);
