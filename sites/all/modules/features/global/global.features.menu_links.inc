<?php
/**
 * @file
 * global.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function global_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_afficher-la-carte:node/6
  $menu_links['main-menu_afficher-la-carte:node/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Afficher la carte',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_afficher-la-carte:node/6',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-carte-des-mesures:<front>',
  );
  // Exported menu link: main-menu_carte-des-utilisateurs:users/map
  $menu_links['main-menu_carte-des-utilisateurs:users/map'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users/map',
    'router_path' => 'users/map',
    'link_title' => 'Carte des utilisateurs',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_carte-des-utilisateurs:users/map',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_comment-fait-on-des-mesures-:node/10
  $menu_links['main-menu_comment-fait-on-des-mesures-:node/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/10',
    'router_path' => 'node/%',
    'link_title' => 'Comment fait-on des mesures ?',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_comment-fait-on-des-mesures-:node/10',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tout-savoir:<front>',
  );
  // Exported menu link: main-menu_comment-participer-:node/17
  $menu_links['main-menu_comment-participer-:node/17'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'Comment participer ?',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_comment-participer-:node/17',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_comment-se-procurer-un-capteur-:node/16
  $menu_links['main-menu_comment-se-procurer-un-capteur-:node/16'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'Comment se procurer un capteur ?',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_comment-se-procurer-un-capteur-:node/16',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_contacts:node/5
  $menu_links['main-menu_contacts:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Contacts',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_contacts:node/5',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_le-projet:<front>',
  );
  // Exported menu link: main-menu_dveloppeurs:node/18
  $menu_links['main-menu_dveloppeurs:node/18'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/18',
    'router_path' => 'node/%',
    'link_title' => 'Développeurs',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_dveloppeurs:node/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_foire-aux-questions:node/14
  $menu_links['main-menu_foire-aux-questions:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Foire aux questions',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_foire-aux-questions:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tout-savoir:<front>',
  );
  // Exported menu link: main-menu_forum:forum
  $menu_links['main-menu_forum:forum'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Forum',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_forum:forum',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_glossaire:node/13
  $menu_links['main-menu_glossaire:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'Glossaire',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_glossaire:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tout-savoir:<front>',
  );
  // Exported menu link: main-menu_je-minscris:node/19
  $menu_links['main-menu_je-minscris:node/19'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/19',
    'router_path' => 'node/%',
    'link_title' => 'Je m\'inscris',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_je-minscris:node/19',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_la-carte-des-mesures:<front>
  $menu_links['main-menu_la-carte-des-mesures:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'La carte des mesures',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_la-carte-des-mesures:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_la-communaut:<front>
  $menu_links['main-menu_la-communaut:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'La communauté',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_la-communaut:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_le-contexte:node/3
  $menu_links['main-menu_le-contexte:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Le contexte',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_le-contexte:node/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_le-projet:<front>',
  );
  // Exported menu link: main-menu_le-projet-openradiation:node/2
  $menu_links['main-menu_le-projet-openradiation:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Le projet openradiation',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_le-projet-openradiation:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_le-projet:<front>',
  );
  // Exported menu link: main-menu_le-projet:<front>
  $menu_links['main-menu_le-projet:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Le projet',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_le-projet:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_les-donness:node/7
  $menu_links['main-menu_les-donness:node/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Les donnéess',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_les-donness:node/7',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-carte-des-mesures:<front>',
  );
  // Exported menu link: main-menu_les-missions:<front>
  $menu_links['main-menu_les-missions:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Les missions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_les-missions:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_mes-missions:missions/my
  $menu_links['main-menu_mes-missions:missions/my'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'missions/my',
    'router_path' => 'missions/my',
    'link_title' => 'Mes missions',
    'options' => array(
      'node_type' => 'page',
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_mes-missions:missions/my',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_les-missions:<front>',
  );
  // Exported menu link: main-menu_mesures-les-plus-commentes:measurement/most-commented
  $menu_links['main-menu_mesures-les-plus-commentes:measurement/most-commented'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'measurement/most-commented',
    'router_path' => 'measurement/most-commented',
    'link_title' => 'Mesures les plus commentées',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_mesures-les-plus-commentes:measurement/most-commented',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-carte-des-mesures:<front>',
  );
  // Exported menu link: main-menu_missions-en-cours:missions
  $menu_links['main-menu_missions-en-cours:missions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'missions',
    'router_path' => 'missions',
    'link_title' => 'Missions en cours',
    'options' => array(
      'node_type' => 'page',
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_missions-en-cours:missions',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_les-missions:<front>',
  );
  // Exported menu link: main-menu_pourquoi-faire-des-mesures-:node/9
  $menu_links['main-menu_pourquoi-faire-des-mesures-:node/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'Pourquoi faire des mesures ?',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_pourquoi-faire-des-mesures-:node/9',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tout-savoir:<front>',
  );
  // Exported menu link: main-menu_pourquoi-rejoindre-la-communaut-:node/15
  $menu_links['main-menu_pourquoi-rejoindre-la-communaut-:node/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'Pourquoi rejoindre la communauté ?',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_pourquoi-rejoindre-la-communaut-:node/15',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_la-communaut:<front>',
  );
  // Exported menu link: main-menu_quest-ce-quune-mission-:node/20
  $menu_links['main-menu_quest-ce-quune-mission-:node/20'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/20',
    'router_path' => 'node/%',
    'link_title' => 'Qu\'est-ce qu\'une mission ?',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_quest-ce-quune-mission-:node/20',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_les-missions:<front>',
  );
  // Exported menu link: main-menu_qui-sommes-nous:node/4
  $menu_links['main-menu_qui-sommes-nous:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Qui sommes-nous',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'identifier' => 'main-menu_qui-sommes-nous:node/4',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_le-projet:<front>',
  );
  // Exported menu link: main-menu_supports-pdagogiques:supports-pedagogiques
  $menu_links['main-menu_supports-pdagogiques:supports-pedagogiques'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'supports-pedagogiques',
    'router_path' => 'supports-pedagogiques',
    'link_title' => 'Supports pédagogiques',
    'options' => array(
      'node_type' => 'page',
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_supports-pdagogiques:supports-pedagogiques',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tout-savoir:<front>',
  );
  // Exported menu link: main-menu_the-openradiation-project:node/2
  $menu_links['main-menu_the-openradiation-project:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'The Openradiation Project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_the-openradiation-project:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_the-project:node/2',
  );
  // Exported menu link: main-menu_the-project:node/2
  $menu_links['main-menu_the-project:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'The Project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_the-project:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_tout-savoir-sur-la-radioactivit:node/11
  $menu_links['main-menu_tout-savoir-sur-la-radioactivit:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Tout savoir sur la radioactivité',
    'options' => array(
      'node_type' => 'page',
      'identifier' => 'main-menu_tout-savoir-sur-la-radioactivit:node/11',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tout-savoir:<front>',
  );
  // Exported menu link: main-menu_tout-savoir:<front>
  $menu_links['main-menu_tout-savoir:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Tout savoir',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_tout-savoir:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'fr',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_ajouter-du-contenu:node/add
  $menu_links['menu-administration_ajouter-du-contenu:node/add'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Ajouter du contenu',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_ajouter-du-contenu:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_blocs:admin/structure/block
  $menu_links['menu-administration_blocs:admin/structure/block'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocs',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_blocs:admin/structure/block',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_forums:admin/structure/forum
  $menu_links['menu-administration_forums:admin/structure/forum'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/structure/forum',
    'router_path' => 'admin/structure/forum',
    'link_title' => 'Forums',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_forums:admin/structure/forum',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_liste-des-contenus:admin/content
  $menu_links['menu-administration_liste-des-contenus:admin/content'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Liste des contenus',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_liste-des-contenus:admin/content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_menu-principal:admin/structure/menu/manage/main-menu
  $menu_links['menu-administration_menu-principal:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Menu principal',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_menu-principal:admin/structure/menu/manage/main-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_points-de-contributions:admin/config/people/userpoints/bluestone-points
  $menu_links['menu-administration_points-de-contributions:admin/config/people/userpoints/bluestone-points'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/config/people/userpoints/bluestone-points',
    'router_path' => 'admin/config/people/userpoints/bluestone-points',
    'link_title' => 'Points de contributions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_points-de-contributions:admin/config/people/userpoints/bluestone-points',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_rapports:admin/reports
  $menu_links['menu-administration_rapports:admin/reports'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/reports',
    'router_path' => 'admin/reports',
    'link_title' => 'Rapports',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_rapports:admin/reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_traductions:admin/config/regional/translate
  $menu_links['menu-administration_traductions:admin/config/regional/translate'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/config/regional/translate',
    'router_path' => 'admin/config/regional/translate',
    'link_title' => 'Traductions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_traductions:admin/config/regional/translate',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_utilisateurs:admin/people
  $menu_links['menu-administration_utilisateurs:admin/people'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Utilisateurs',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_utilisateurs:admin/people',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-administration_webservices:admin/config/services/measurements
  $menu_links['menu-administration_webservices:admin/config/services/measurements'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/config/services/measurements',
    'router_path' => 'admin/config/services/measurements',
    'link_title' => 'Webservices',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_webservices:admin/config/services/measurements',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Afficher la carte');
  t('Ajouter du contenu');
  t('Blocs');
  t('Carte des utilisateurs');
  t('Comment fait-on des mesures ?');
  t('Comment participer ?');
  t('Comment se procurer un capteur ?');
  t('Contacts');
  t('Développeurs');
  t('Foire aux questions');
  t('Forum');
  t('Forums');
  t('Glossaire');
  t('Je m\'inscris');
  t('La carte des mesures');
  t('La communauté');
  t('Le contexte');
  t('Le projet');
  t('Le projet openradiation');
  t('Les donnéess');
  t('Les missions');
  t('Liste des contenus');
  t('Menu principal');
  t('Mes missions');
  t('Mesures les plus commentées');
  t('Missions en cours');
  t('Points de contributions');
  t('Pourquoi faire des mesures ?');
  t('Pourquoi rejoindre la communauté ?');
  t('Qu\'est-ce qu\'une mission ?');
  t('Qui sommes-nous');
  t('Rapports');
  t('Supports pédagogiques');
  t('The Openradiation Project');
  t('The Project');
  t('Tout savoir');
  t('Tout savoir sur la radioactivité');
  t('Traductions');
  t('Utilisateurs');
  t('Webservices');

  return $menu_links;
}
