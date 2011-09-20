<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ding_eresource_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function ding_eresource_node_info() {
  $items = array(
    'eresource' => array(
      'name' => t('E-Resource'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'has_body' => '1',
      'body_label' => t('Beskrivelse'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
