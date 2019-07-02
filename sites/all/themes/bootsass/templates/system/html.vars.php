<?php
/**
 * Implements hook_preprocess_html().
 */
function bootsass_preprocess_html(&$variables) {
	
	// GOOGLE FONT
	$element = array(
		'#tag' => 'link',
		'#attributes' => array(
			'href' => '//fonts.googleapis.com/css?family=Signika:400,300',
			'rel' => 'stylesheet',
			'type' => 'text/css',
		),
	);
	drupal_add_html_head($element, 'google_font_signika');

	// GOOGLE FONT
	$element = array(
		'#tag' => 'link',
		'#attributes' => array(
			'href' => '//fonts.googleapis.com/css?family=Varela+Round',
			'rel' => 'stylesheet',
			'type' => 'text/css',
		),
	);
	drupal_add_html_head($element, 'google_font_varela');

}