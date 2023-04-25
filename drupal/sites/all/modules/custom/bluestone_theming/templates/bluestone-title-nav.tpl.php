
<?php
$o = menu_get_object();
if(is_object($o) && isset($o->nid))
{
  $node = $o;
}
else
{
  $node = false;
}

// for mission organic group, fetch group node by url.
if (arg(0) == 'mission') {
  $node = node_load(arg(1));
}

$prev = "";
$next = "";
if(isset($node->field_previews_article[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_previews_article[LANGUAGE_NONE][0]['access']))
{
  $prev = '
    <a class="js-to-article prev_article btn" href="'.url('node/'.$node->field_previews_article[LANGUAGE_NONE][0]['target_id']).'" title="'.$node->field_previews_article[LANGUAGE_NONE][0]["entity"]->title.'">
    <span class="arrow">&#10094;</span>
    <span style="display:none" class="js-title"> ' . check_plain($node->field_previews_article[LANGUAGE_NONE][0]["entity"]->title) . '</span>
    </a>';
}

if(isset($node->field_next_article[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_next_article[LANGUAGE_NONE][0]['access']))
{

  $next = '
    <a class="js-to-article next_article btn" href="'.url('node/'.$node->field_next_article[LANGUAGE_NONE][0]['target_id']).'" title="'.$node->field_next_article[LANGUAGE_NONE][0]["entity"]->title.'">
    <span style="display:none" class="js-title"> ' . check_plain($node->field_next_article[LANGUAGE_NONE][0]["entity"]->title) . '</span>
    <span class="arrow">&#10095;</span>
    </a>';
}

$active_trail = menu_get_active_trail();

$colors[640]="#009FD8";
$colors[620]="#0059B0";
$colors[625]="#243297";
$colors[631]="#703B99";
$colors[636]="#59238F";
$colors[5]="#0059B0";
$colors[6]="#59238F";

$object = menu_get_object();
$menu = menu_get_item();
$og_tabs = false;
if(is_object($object) && isset($object->nid) && isset($object->type) && $object->type == "mission")
{
  $active_trail[1]["mlid"] = 636;
}
elseif(is_object($object) && isset($object->nid) && isset($object->type))
{
  list(,, $bundle) = entity_extract_ids('node', $object);
  if (og_is_group_content_type('node', $bundle)) {
    $active_trail[1]["mlid"] = 636;
  }
}
elseif($menu["page_callback"] == "node_page_view" or $menu["page_callback"] == "views_page")
{
  $arg1 = $menu["page_arguments"][0];
  $expl = explode('_',$arg1);
  if(in_array("og", $expl))
  {
    $active_trail[1]["mlid"] = 636;
  }
}
elseif($menu["page_callback"] == "node_add" or $menu["page_callback"] == " node_add")
{
  $bundle = $menu["page_arguments"][0];
  if (og_is_group_content_type('node', $bundle)) {
    $active_trail[1]["mlid"] = 636;
  }

}

if(isset($active_trail[1]) && isset($active_trail[1]["mlid"])) {
  $menu_column = $active_trail[1];
  $mlid = $menu_column["mlid"];
  if (isset($colors[$mlid])) {
    $color = $colors[$mlid];
  }
}

if (empty($color)) {
  $color = $colors[640];
}

?>

<?php // dirty hack, because we are not always on a node ... ?>
<?php 
    //$title =  !empty($node->title) ? $node->title : drupal_get_title();
    if (!empty($node->title)) {
        if ($node->type =="measurement") {
            $formated_date = format_date($node->field_time['und'][0]['value'], $type = 'medium', $format = '', $timezone = $node->field_time['und'][0]['timezone']);
            $title = t('Measurement of ') . $formated_date;
        } else {
            $title = $node->title;
        }
    } else {
        $title = drupal_get_title();
    }
?>


<div id="title_nav" style="background-color:<?php print $color ?>;" class="row section-<?php echo !empty($mlid) ? $mlid : 0 ?>">
  <div id="user-infos">
    <?php if (user_is_anonymous()): ?>
      <?php echo l(t("Log in"), 'user/login') ?>
    <?php else : ?>
      <?php echo l(t("My account"), 'user') ?> <span class="vertical-divider"></span> <?php echo l(t("Log out"), "user/logout"); ?>
    <?php endif ?>

  </div>
  <?php print $prev ?>
  <?php print $next ?>
  <div class="col-md-12 title_nav_block"><h1><?php print strip_tags($title) ?></h1></div>
</div>





