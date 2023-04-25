<div id="block-locale-language">
<?php
$path = drupal_is_front_page() ? '<front>' : $_GET['q'];
$links = language_negotiation_get_switch_links('language', $path);
// use language string ('fr', 'en') rather than language image for the links text
foreach ($links->links as $language_id => $link) {
  $links->links[$language_id]['title'] = check_plain($link['language']->language);
}
$class = "language-switcher-{$links->provider}";
$variables = array('links' => $links->links, 'attributes' => array('class' => array($class)));
// will be print inside the header.
$languages_links = theme('links__locale_block', $variables);
?>
</div>

<?php
// DO not remove ! js use those classes to detect bootstrap breakpoints
// Thanks to those div, we are able to create a function like this,
// usabled in javascript to detect breakpoints.
// function isBreakpoint( alias ) {
//  return $('.device-' + alias).is(':visible');
// }
?>
<div class="device-xs visible-xs"></div>
<div class="device-sm visible-sm"></div>
<div class="device-md visible-md"></div>
<div class="device-lg visible-lg"></div>


<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">

  <?php print $languages_links; ?>

  <?php //print drupal_get_title();exit; ?>

  <?php $tweet = urlencode(drupal_get_title() . " " . url($_GET['q'], ['absolute' => TRUE]) . " #openradiation");?>

  <!-- SHARE BUTTONS -->
  <div id="social_absolute" class="hidden-xs">

    <a target="_blank"
       href="https://twitter.com/intent/tweet?text=<?php echo $tweet ?>"
       class="infobulle bluestone-popup"
       title="<?php echo t("Share on") ?> Twitter">
      <img alt="twitter" src="<?php echo base_path() . drupal_get_path('theme', 'bootsass')?>/images/social/twitter.png">
    </a>

    <a target="_blank"
       href="https://www.facebook.com/sharer/sharer.php?u=<?php echo urlencode(url($_GET['q'], ['absolute' => TRUE])) ?>"
       title="<?php echo t("Share on")?> Facebook"
       class="infobulle fb-share-button bluestone-popup"
      >
      <img alt="facebook" src="<?php echo base_path() . drupal_get_path('theme', 'bootsass')?>/images/social/facebook.png">
    </a>

  </div>

  <!--
    <div class="navbar-header">
      -->
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
  <!--
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    </div>
    -->


    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>

              <?php print theme('bluestone_menu') ?>

          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
    <?php endif; ?>

</header>
