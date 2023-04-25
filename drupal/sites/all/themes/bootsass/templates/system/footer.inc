<footer class="footer">
  <div class="footer-inner container">
    <?php //print render($page['footer']); ?>
    <div class="row">
      <div class="col-xs-12 col-md-8 nopadding">

        <?php $menu = menu_tree_all_data("main-menu");  ?>
        <?php $c = 0; global $language; ?>
        <div id="bluestone_footer_menu" class="row">

          <?php foreach($menu as $k => $m): ?>

            <?php
            if($m["link"]["hidden"]!="0"){continue;}
            ?>

            <div class="bluestone_footer_column col-sm-3 bluestone-footer-block-<?php print $c ?>">
              <?php $c++; ?>
              <span class="footer_parent_link" href="<?php print $m["link"]["link_path"] ?>"><?php print $m["link"]["link_title"] ?></span>
              <?php if(isset($m["below"]) && is_array($m["below"]) && count($m["below"]) > 0): ?>
                <div class="bluestone_footer_sublinks">
                  <ul class="list-unstyled">
                    <?php foreach($m["below"] as $sm): ?>
                      <li><a href="<?php print url($sm["link"]["link_path"]) ?>"><?php print $sm["link"]["link_title"] ?></a></li>
                    <?php endforeach; ?>
                  </ul>
                </div>
              <?php endif; ?>
            </div>

          <?php endforeach; ?>
          <div class="clearfix"></div>

        </div>


      </div>
      <div class="col-xs-12  col-md-4 nopadding" id="bluestone_footer_contact">
        <?php
        // block Footer / Adresse + Réseaux sociaux
        global $language;
        $theme_path = base_path() . drupal_get_path('theme', 'bootsass');?>


        <!-- <a title="" href="/fr/#"><img class="img-responsive partners" src="http://placehold.it/300x50&amp;text=Visuel"></a>  -->

        <div class="row">
          <div class="col col-xs-8 ">
            <div class="adresse">
              <h3>Contact</h3>
            <!--  <span class="glyphicon glyphicon-map-marker"></span>31, av de la Division Leclerc<br>
              92260 Fontenay-aux-Roses<br>
              France<br>
              <span class="glyphicon glyphicon-earphone"></span> +33 1 58 35 88 88<br> -->
              <span class="glyphicon glyphicon-envelope"></span> <a href="mailto:contact@openradiation.org">contact@openradiation.org</a>
            </div>
          </div>
          <div class="col col-xs-4">
            <div class="social">
              <h3><?php print t("Follow us") ?></h3>
              <div class="row">
                <a class="infobulle" title="" href="https://twitter.com/openradiation" target="_blank" data-original-title="Suivez nous sur Twitter"><img src="/sites/all/themes/bootsass/images/social/twitter.png" alt="twitter"></a>
                <a class="infobulle" title="<?php echo t("Follow us on") ?> Facebook" href="https://www.facebook.com/OpenRadiation"><img src="<?php print $theme_path; ?>/images/social/facebook.png" alt="facebook" /></a>
              </div>
              <!--
              <div class="row">
                <a class="" title="Flux Rss" href="#"><img src="<?php //print $theme_path; ?>/images/social/rss.png" alt="rss" /></a>
                <a class="" title="Youtube" href="#"><img src="<?php //print $theme_path; ?>/images/social/youtube.png" alt="youtube" /></a>
              </div>
              <div class="row">
                <a class="" title="Google Plus" href="#"><img src="<?php //print $theme_path; ?>/images/social/googleplus.png" alt="googleplus" /></a>
                <a class="" title="LinkedIn" href="#"><img src="<?php //print $theme_path; ?>/images/social/linkedin.png" alt="linkedin" /></a>
              </div>
              -->




            </div>
          </div>
        </div>

        <div class="row">
          <?php if (!empty($page['masquerade'])): ?>
            <?php print render($page['masquerade']); ?>
          <?php endif; ?>
        </div>
        <div class="row">
          <div class="col col-xs-12">
            <?php
            $block = module_invoke('search', 'block_view', 'search');
            print render($block);
            ?>
          </div>

        </div>
      </div>
    </div>
  </div>
</footer>

<div id="fb-root"></div>
<script>(function(d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id)) return;
    js = d.createElement(s); js.id = id;
    js.src = "//connect.facebook.net/fr_FR/sdk.js#xfbml=1&version=v2.4";
    fjs.parentNode.insertBefore(js, fjs);
  }(document, 'script', 'facebook-jssdk'));</script>
