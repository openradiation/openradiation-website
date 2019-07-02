<?php

/**
 * @file
 * Rate widget theme
 */
?>

<?php

  /*
  <div class="rate-label">
    <?php print $display_options['title']; ?>
  </div>
  */
?>

<ul class="bluestone-thumbs-up-down">
  <li class="thumb-up">
    <?php print $up_button; ?>
    <span class="points"><?php print check_plain($results['up']); ?></span>
  </li>
  <li class="thumb-down">
    <?php print $down_button; ?>
    <span class="points"><?php print check_plain($results['down']); ?></span>
  </li>
</ul>
<?php

if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
