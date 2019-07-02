<?php
/**
 * @file
 * global.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function global_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:mission:Project manager'.
  $roles['node:mission:Project manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'mission',
    'name' => 'Project manager',
  );

  return $roles;
}
