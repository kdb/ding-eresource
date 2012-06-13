<?php
/**
 * @file
 * Page callbacks for the Ding e-resource module.
 */

/**
 * Define the header text editing form.
 */
function ding_eresource_header_text_edit_form(&$form_state) {
  $form = array();
  $vid = variable_get('ding_eresource_eresource_category_vid', NULL);

  $form['text'] = array('#tree' => TRUE);

  $form['text']['default'] = _ding_eresource_pages_header_text_edit_element('default', t('Default header text'));

  foreach (taxonomy_get_tree($vid, 0, -1, 1) as $term) {
    $form['text'][$term->tid] = _ding_eresource_pages_header_text_edit_element($term->tid, t('Text for @term', array('@term' => $term->name)));
  }

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );

  return $form;
}

/**
 * Save the inserted text.
 */
function ding_eresource_header_text_edit_form_submit(&$form, &$form_state) {
  foreach ($form_state['values']['text'] as $key => $element) {
    $text = trim($element['value']);

    // If user provided an empty value value, make sure we wipe any
    // previously saved text from the database.
    if (empty($text)) {
      variable_del('ding_eresource_header_text_' . $key);
    }
    else {
      variable_set('ding_eresource_header_text_' . $key, $element);
    }
  }
}

/**
 * Generate a text editing fieldset for our form.
 *
 * It's really sille that core doesn't ship with a standard textarea +
 * input format selector widget, so we have to define our own.
 */
function _ding_eresource_pages_header_text_edit_element($key, $title) {
  $defaults = variable_get('ding_eresource_header_text_' . $key, array(
    'value' => '',
    'format' => FILTER_FORMAT_DEFAULT,
  ));

  $element = array(
    '#type' => 'fieldset',
    '#title' => $title,
    '#tree' => TRUE,
  );

  $element['value'] = array(
    '#type' => 'textarea',
    '#default_value' => $defaults['value'],
  );

  $element['format'] = filter_form($defaults['format'], NULL, array(
    // Configure where in the values array the format appears.
    'text', $key, 'format',
  ));

  return $element;
}
