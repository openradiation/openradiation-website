<!-- <span class="boot-debug"></span>  -->

<?php include('header.inc'); ?>

<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>
    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">

      <?php print theme('bluestone_title_nav'); ?>
      <?php print theme('bluestone_og_tabs'); ?>

      <?php if (!empty($og_tabs) && is_array($og_tabs) && count($og_tabs) > 1 && is_array($og_tabs['#primary']) && count($og_tabs['#primary']) > 0): ?>
      <?php print render($og_tabs); ?>
      <?php endif; ?>

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?> id="section-main">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
       <!-- <h1 class="page-header"><?php //print $title; ?></h1> -->
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php print $messages; ?>

      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print render($page['content_bottom']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-4" role="complementary" id="section-right">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div><!-- ! row -->

</div><!-- ! main-container container -->

<?php include('footer.inc'); ?>