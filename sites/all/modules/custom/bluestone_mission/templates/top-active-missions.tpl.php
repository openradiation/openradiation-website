<?php
/**
 * @variables : array $datas
 *   array of objects containing a nid property
 *
 */
?>

<ul>
  <?php foreach ($datas as $data) : ?>
    <?php $node = node_load($data['nid']); ?>
    <li>
      <?php print l($node->title, "node/$node->nid") ?>
      <!-- only for debug : number of comments and content since one month for this mission
      <span class="badge"><?php // echo $data['count_contents'] ?> content(s)</span>
      <span class="badge"><?php // echo $data['count_comments'] ?> comment(s)</span>
      -->
    </li>
  <?php endforeach ?>

</ul>


