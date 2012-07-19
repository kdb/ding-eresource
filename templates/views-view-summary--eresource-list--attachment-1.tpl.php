<?php
/**
 * @file
 * Override the output for the alphabetical index on the eresource page.
 *
 * This is not really a template in the basic sense of the work, since
 * we rely on theme_links to render the actual markup, but it's a neat
 * way to override Views' standard rendering.
 *
 * @ingroup views_templates
 */

// Find the letter the View is currently filtered by, if any.
if (!empty($view->original_args[1])) {
  $letter = drupal_strtoupper($view->original_args[1]); 
}

// Array of links to render.
$links = array();

foreach ($rows as $id => &$row) {
  $link = array(
    'title' => $row->link,
    // Strip the initial / from the URL, since theme_links adds another
    // while rendering.
    'href' => ltrim($row->url, '/'),
    'attributes' => array(
      'class' => (isset($classes[$id])) ? $classes[$id] : '',
    ),
  );

  // Remove availablility filter from URLs. 
  if ($pos = strpos($link['href'], '?availability')) {
    $link['href'] = substr($link['href'], 0, $pos);
  }

  // Add the active-class to the currently active letter.
  if ($row->link === $letter) {
    $link['attributes']['class'] .= ' active';
  }

  $links[$id] = $link;
}

if (!empty($links)) {
  echo theme('links', $links, array('class' => 'eresource-alphabetical-index views-summary clearfix'));
}
