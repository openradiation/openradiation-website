<?php
/**
 * @file
 * global.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function global_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-administration.
  $menus['menu-administration'] = array(
    'menu_name' => 'menu-administration',
    'title' => 'Administration webmaster du site',
    'description' => 'Menu d\'administration d\'openradiation, utilisé comme source pour le module admin menu, grâce au module admin_menu_source',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Administration webmaster du site');
  t('Main menu');
  t('Menu d\'administration d\'openradiation, utilisé comme source pour le module admin menu, grâce au module admin_menu_source');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
