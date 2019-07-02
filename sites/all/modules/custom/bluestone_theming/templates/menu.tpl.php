<?php
/**
 * @file menu.tpl.php
 *
 * Contains actually two templates :
 * - one for big screens
 * - one for very small screens (mobile navigation)
 */
?>

<?php $menu = menu_tree_all_data("main-menu");  ?>
<?php $c = 0; global $language; ?>

<?php
/* ==================================
   For medium and big screens only :
   ================================== */
?>

<div class="hidden-xs"><!-- hide for xs screens -->

  <div id="bluestone_main_menu" state="closed" class="row">
    <div class="bluestone_menu_column col-sm-2 logo">
      <a title="Accueil" href="<?php print url('<front>') ?>" class="logo navbar-btn">
        <img alt="Accueil" src="<?php print base_path() . drupal_get_path('theme', 'bootsass') ?>/logo.png" class="logo">
      </a>
    </div>
    <?php foreach($menu as $k => $m): ?>

      <?php
      if($m["link"]["hidden"]!="0"){continue;}
      ?>

      <div class="bluestone_menu_column col-sm-2 slidedown-menu bluestone-menu-block-<?php print $c ?>">
        <?php $c++; ?>
        <span class="parent_link" href="<?php print $m["link"]["link_path"] ?>"><?php print $m["link"]["link_title"] ?></span>
        <?php if(isset($m["below"]) && is_array($m["below"]) && count($m["below"]) > 0): ?>
          <div class="bluestone_sublinks" style="display:none;">
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

<?php
/* ===========================
   For small screens (xs) only
   =========================== */
?>

<?php $c = 0; ?>
<div class="visible-xs mobile-navigation"><!-- only visible for very small screens -->

  <nav class="navbar navbar-default">
    <div class="container-fluid">
      <!-- Brand and toggle get grouped for better mobile display -->
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>

        <a title="Accueil" href="<?php echo url('<front>'); ?>" class="logo navbar-btn">
          <img alt="Accueil" src="<?php echo base_path()?>sites/all/themes/bootsass/logo.png" class="logo">
        </a>

      </div>

      <!-- Collect the nav links, forms, and other content for toggling -->
      <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">

        <ul class="nav navbar-nav">

          <?php foreach($menu as $k => $m): ?>
          <li class="dropdown bluestone-menu-block-<?php print $c ?>">


            <?php if($m["link"]["hidden"]!="0") continue; ?>

            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false"><?php print $m["link"]["link_title"] ?> <span class="caret"></span></a>
            <ul class="dropdown-menu" role="menu">
              <?php foreach($m["below"] as $sm): ?>
                <li><a href="<?php print url($sm["link"]["link_path"]) ?>"><?php print $sm["link"]["link_title"] ?></a></li>
              <?php endforeach; ?>
            </ul>

          </li>
          <?php $c++ ?>
          <?php endforeach; ?>
        </ul>

      </div><!-- /.navbar-collapse -->
    </div><!-- /.container-fluid -->
  </nav>

</div>

