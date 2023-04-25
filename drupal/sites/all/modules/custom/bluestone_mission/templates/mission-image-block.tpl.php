<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


//print render($node->field_mission_picture);
/*
$image = field_get_items('node', $node, 'field_mission_picture');
$output = field_view_value('node', $node, 'field_mission_picture', $image[0], array(
  'type' => 'image',
  'settings' => array(
    'image_style' => 'large',
  ),
));
print render($output);       
*/

$node_view = node_view($node);
//krumodev($node_view);
print render($node_view['field_mission_picture']);
?>
<div class="mission-right-block">
<?php print render($node_view['group_group']); ?>
</div>
