<?php // krumo($content) ?>
<?php //krumo(get_defined_vars()) ?>
<div class="row node-mission-wrapper">
  <div class="node-mission-<?php print $view_mode ?>">

    <?php if (bluestone_mission_is_closed($node)): ?>
    <div class="alert alert-warning"><?php echo t("This mission is now closed !") ?>
      <?php endif ?>

      <?php $context_title_links = render($variables['elements']['group_group']); ?>
      <h2><?php print(t("Mission goals")); ?></h2>
      <div class="mission-objectifs"><?php print render($content['body']) ?></div>
      <div class="mission-stats">
        <div class="row animator">
          <div class="col-md-12"><?php print render($content['field_mission_animator']) ?></div>
        </div>
        <div class="row stats">
          <div class="col-md-4"><?php print render($content['field_mission_date_start']) ?></div>
          <div class="col-md-4"><?php print render($content['field_mission_date_end']) ?></div>
          <div class="col-md-4"><?php print render($content['field_mission_progress']) ?></div>
        </div>
      </div>

      <?php if (bluestone_mission_is_closed($node)): ?>
    </div>
  <?php endif ?>



  </div>

</div>