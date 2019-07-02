<?php
/**
 * List top contributors of the month
 */

$users_by_row = 2;
$i = 0;

?>

<?php foreach ($datas as $row) : ?>

  <?php $user = user_load($row->uid); ?>

  <?php if ($i % $users_by_row === 0) : ?>
    <div class="row">
  <?php endif ?>

  <?php $i++ ?>


  <div class="text-center col-xs-12 col-md-<?php echo 12 / $users_by_row ?> img-circle">

    <?php
    /*
    $image_params = [
      'attributes' => ['class' => ['img-circle']],
      "style_name" => "thumbnail",
      "path" => $user->picture->uri,
      "height" => NULL,
      "width" => NULL
    ];
    */
    ?>

    <?php //echo theme('image_style', $image_params); ?>
    <?php echo l(theme('user_picture',  array('account' => $user)), "user/$user->uid", array('html' => TRUE)); ?>

    <h5><?php echo l($user->name, "user/$user->uid"); ?></h5>
    <p><?php echo check_plain($row->points) ?>  points</p>

    <?php if (!empty($user->picture->uri)) : ?>


    <?php endif ?>
  </div>


  <?php if ($i % $users_by_row === 0) : ?>
    </div>
  <?php endif ?>


<?php endforeach; ?>


