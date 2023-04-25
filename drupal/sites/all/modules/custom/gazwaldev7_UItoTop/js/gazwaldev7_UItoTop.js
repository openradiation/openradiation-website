(function($) {
	Drupal.behaviors.gazwaldev7_UItoTop = {
		attach: function(context, settings) {
			$().UItoTop({
				easingType: 'easeOutQuart'
			});
		} // end 
	};
})(jQuery);