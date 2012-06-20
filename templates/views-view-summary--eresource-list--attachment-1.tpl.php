<?php
/**
 * @file
 * Override the output for the alphabetical index on the eresource page.
 *
 * @ingroup views_templates
 */

// If we're currently filtering on a letter, add an active class to that
// letter's link.
if (!empty($view->original_args[1])) {
  $letter = drupal_strtoupper($view->original_args[1]); 
  
  foreach ($rows as $id => &$row) {
    if ($row->link === $letter) {
      if (isset($classes[$id])) {
        $classes[$id] .= ' active';
      }
      else {
        $classes[$id] = 'active';
      }
    }

    // Remove availablility filter from URLs. 
    if ($pos = strpos($row->url, '?availability')) {
      $row->url = substr($row->url, 0, $pos);
    }
  }
}
?>
<div class="item-list">
  <ul class="views-summary">
  <?php foreach ($rows as $id => $row): ?>
    <li><a href="<?php print $row->url; ?>"<?php print !empty($classes[$id]) ? ' class="'. $classes[$id] .'"' : ''; ?>><?php print $row->link; ?></a>
      <?php if (!empty($options['count'])): ?>
        (<?php print $row->count?>)
      <?php endif; ?>
    </li>
  <?php endforeach; ?>
  </ul>
</div>
