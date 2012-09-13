<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function ding_eresource_user_default_permissions() {
  $permissions = array();

  // Exported permission: create eresource content
  $permissions['create eresource content'] = array(
    'name' => 'create eresource content',
    'roles' => array(
      '0' => 'Formidler',
      '1' => 'Formidlingskoordinator',
      '2' => 'redaktør (KDB)',
      '3' => 'super-admin',
    ),
  );

  // Exported permission: delete any eresource content
  $permissions['delete any eresource content'] = array(
    'name' => 'delete any eresource content',
    'roles' => array(
      '0' => 'redaktør (KDB)',
      '1' => 'super-admin',
    ),
  );

  // Exported permission: delete own eresource content
  $permissions['delete own eresource content'] = array(
    'name' => 'delete own eresource content',
    'roles' => array(
      '0' => 'Formidler',
      '1' => 'Formidlingskoordinator',
      '2' => 'redaktør (KDB)',
      '3' => 'super-admin',
    ),
  );

  // Exported permission: edit any eresource content
  $permissions['edit any eresource content'] = array(
    'name' => 'edit any eresource content',
    'roles' => array(
      '0' => 'redaktør (KDB)',
      '1' => 'super-admin',
    ),
  );

  // Exported permission: edit own eresource content
  $permissions['edit own eresource content'] = array(
    'name' => 'edit own eresource content',
    'roles' => array(
      '0' => 'Formidler',
      '1' => 'redaktør (KDB)',
      '2' => 'super-admin',
    ),
  );

  return $permissions;
}
