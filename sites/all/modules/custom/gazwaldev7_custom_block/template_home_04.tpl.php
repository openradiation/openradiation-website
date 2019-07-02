<?php
// block Footer / Adresse + Réseaux sociaux
global $language;
$theme_path = base_path() . drupal_get_path('theme', 'bootsass');
?>

<a title="" href="/"><img class="img-responsive" height="120" width="100%" src="<?php echo base_path() ?>/sites/all/themes/bootsass/images/user-icon-default.jpg"></a>

<div class="row">
	<div class="col col-sm-7">
		<div class="adresse">
			<h3>Contact</h3>
			<span class="glyphicon glyphicon-map-marker"></span> 12, rue de Paris<br />
			75012 - PARIS<br />
			France<br />
			<span class="glyphicon glyphicon-earphone"></span> +00 1 48 46 47 38<br />
			<span class="glyphicon glyphicon-envelope"></span> <a href="mailto:contact@openradiation.org">contact@openradiation.org</a>
		</div>
	</div>
	<div class="col col-sm-5">
		<div class="social">
			<a class="" title="Twitter" href="#"><img src="<?php print $theme_path; ?>/images/social/twitter.png" alt="twitter" /></a>
			<a class="" title="Facebook" href="#"><img src="<?php print $theme_path; ?>/images/social/facebook.png" alt="facebook" /></a>
          <!--
			<a class="" title="Flux Rss" href="#"><img src="<?php // print $theme_path; ?>/images/social/rss.png" alt="rss" /></a>
			<a class="" title="Youtube" href="#"><img src="<?php // print $theme_path; ?>/images/social/youtube.png" alt="youtube" /></a>
			<a class="" title="Google Plus" href="#"><img src="<?php // print $theme_path; ?>/images/social/googleplus.png" alt="googleplus" /></a>
			<a class="" title="LinkedIn" href="#"><img src="<?php // print $theme_path; ?>/images/social/linkedin.png" alt="linkedin" /></a>
			-->
			
		</div>
	</div>
</div>
