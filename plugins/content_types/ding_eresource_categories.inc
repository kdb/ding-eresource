<?php
/**
 * @file
 * Provides a category browser for the eresource overview page.
 */

/**
 * Callback function to supply a list of content types.
 */
function ding_eresource_ding_eresource_categories_ctools_content_types() {
  return array(
    'title' => t('Ding e-resource categories'),
    'description' => t('Provides a selector for e-resource categories.'),
    'single' => TRUE,
    'category' => t('Ting'),
  );
}

/**
 * Return the pane contents.
 */
function ding_eresource_ding_eresource_categories_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  if (isset($conf['vocabulary']) && $conf['vocabulary'] > 0) {
    $links = array();

    $base_path = 'e-resurser';

    // Add all-link, removing the category.
    $links[] = l(t('All'), $base_path);

    // Add a link to each category.
    foreach (taxonomy_get_tree($conf['vocabulary'], 0, -1, 1) as $term) {
      $links[] = l($term->name, $base_path . '/' . $term->tid, array('query' => $query));
    }

    if (count($links) > 1) {
      $block->content = theme('item_list', $links);
    }
  }

  $block->attributes['class'] = 'tab-navigation';

  return $block;
}

/**
 * Return the pane titles.
 */
function ding_eresource_ding_eresource_categories_content_type_admin_title($subtype, $conf, $context) {
  return t('Ding e-resource categories');
}

/**
 * Returns an edit form for the content type.
 *
 * We're not actually doing anything here, but we need to have this hook
 * for this content type to work.
 */
function ding_eresource_ding_eresource_categories_content_type_edit_form(&$form, &$form_state) {
  $vocabulary_options = array();
  foreach (taxonomy_get_vocabularies() as $voc) {
    $vocabulary_options[$voc->vid] = $voc->name;
  }

  $form['vocabulary'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary'),
    '#description' => t('Select the vocabulary used for e-resource categories.'),
    '#options' => $vocabulary_options,
    '#default_value' => $form_state['conf']['vocabulary'],
  );

  return $form;
}

/**
 * Submit handler for the content type editing form.
 */
function ding_eresource_ding_eresource_categories_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['vocabulary'] = $form_state['values']['vocabulary'];
}
