<?php
/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
// override de ../bootstrap/templates/menu/menu-tree.func.php
function bootsass_menu_tree__primary(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}


function bootsass_preprocess_node(&$variables) {
  //krumo($variables);
  
  /* Surcharge de la ligne submitted */
  $picture = '';
  //$picture = $variables['user_picture'];
  $variables['submitted'] = '' . 
    $picture . $variables['name'] . ', le ' . 
	format_date($variables['created'], $type = 'short') ;
  
  /* Création d'un template spécifique à la vue teaser */
  if($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->type . '__teaser';   
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->nid . '__teaser';
  }
}

/**
 * Theme function to display a link, optionally buttonized.
 */
function bootsass_advanced_forum_l(&$variables) {
  $text = $variables['text'];
  $path = empty($variables['path']) ? NULL : $variables['path'];
  $options = empty($variables['options']) ? array() : $variables['options'];
  $button_class = empty($variables['button_class']) ? NULL : $variables['button_class'];

  $l = '';
  if (!isset($options['attributes'])) {
    $options['attributes'] = array();
  }
  if (!is_null($button_class)) {
    // Buttonized link: add our button class and the span.
    if (!isset($options['attributes']['class'])) {
      $options['attributes']['class'] = array("btn btn-primary af-button-$button_class");
    }
    else {
      $options['attributes']['class'][] = "btn btn-primary af-button-$button_class";
    }
    $options['html'] = TRUE;
    // @codingStandardsIgnoreStart
    $l = l('<span>' . $text . '</span>', $path, $options);
    // @codingStandardsIgnoreEnd
  }
  else {
    // Standard link: just send it through l().
    $l = l($text, $path, $options);
  }

  return $l;
}




/**
* Add line breaks to field text
*/
function bootsass_preprocess_field(&$vars) {
  if ($vars['element']['#field_type'] == 'text_long' OR $vars['element']['#field_type'] == 'text_with_summary') {
    $field_name = $vars['element']['#field_name'];
    foreach ($vars['items'] as $key => &$item) {
      if ($vars['element']['#object']->{$field_name}[LANGUAGE_NONE][$key]['format'] == NULL) {
        $item['#markup'] = nl2br($item['#markup']);
      }
    }
  }
}