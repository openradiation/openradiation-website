<?php
/**
 * @file
 * global.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function global_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:mission:add user'
  $permissions['node:mission:add user'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:administer group'
  $permissions['node:mission:administer group'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:approve and deny subscription'
  $permissions['node:mission:approve and deny subscription'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:create og_blog_post content'
  $permissions['node:mission:create og_blog_post content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:create og_discussion content'
  $permissions['node:mission:create og_discussion content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:create og_document content'
  $permissions['node:mission:create og_document content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:create og_news content'
  $permissions['node:mission:create og_news content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:create og_wiki content'
  $permissions['node:mission:create og_wiki content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:delete any og_blog_post content'
  $permissions['node:mission:delete any og_blog_post content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:delete any og_discussion content'
  $permissions['node:mission:delete any og_discussion content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:delete any og_document content'
  $permissions['node:mission:delete any og_document content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:delete any og_news content'
  $permissions['node:mission:delete any og_news content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:delete any og_wiki content'
  $permissions['node:mission:delete any og_wiki content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:delete own og_blog_post content'
  $permissions['node:mission:delete own og_blog_post content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:delete own og_discussion content'
  $permissions['node:mission:delete own og_discussion content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:delete own og_document content'
  $permissions['node:mission:delete own og_document content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:delete own og_news content'
  $permissions['node:mission:delete own og_news content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:delete own og_wiki content'
  $permissions['node:mission:delete own og_wiki content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:manage members'
  $permissions['node:mission:manage members'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:manage permissions'
  $permissions['node:mission:manage permissions'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:manage roles'
  $permissions['node:mission:manage roles'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:subscribe'
  $permissions['node:mission:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:mission:subscribe without approval'
  $permissions['node:mission:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:mission:unsubscribe'
  $permissions['node:mission:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:update any og_blog_post content'
  $permissions['node:mission:update any og_blog_post content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:update any og_discussion content'
  $permissions['node:mission:update any og_discussion content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:update any og_document content'
  $permissions['node:mission:update any og_document content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:update any og_news content'
  $permissions['node:mission:update any og_news content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:update any og_wiki content'
  $permissions['node:mission:update any og_wiki content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:update group'
  $permissions['node:mission:update group'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:update own og_blog_post content'
  $permissions['node:mission:update own og_blog_post content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:update own og_discussion content'
  $permissions['node:mission:update own og_discussion content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:update own og_document content'
  $permissions['node:mission:update own og_document content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:update own og_news content'
  $permissions['node:mission:update own og_news content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
    ),
  );

  // Exported og permission: 'node:mission:update own og_wiki content'
  $permissions['node:mission:update own og_wiki content'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:mission:write privatemsg to group'
  $permissions['node:mission:write privatemsg to group'] = array(
    'roles' => array(
      'Project manager' => 'Project manager',
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
