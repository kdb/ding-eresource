<?php

/**
 * @file
 * Template to render event nodes.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">

<?php if ($page == 0): ?>


  <div class="picture"><?php print $field_list_image[0]['view']; ?></div>

  <div class="info">

    <?php if ($node->title): ?>
      <h3><?php print l($node->title, 'node/' . $node->nid); ?></h3>
    <?php endif; ?>

    <div class="meta">
    </div>

    <?php
      //field_teaser
      if ($node->field_teaser[0]['value']) {
        print $node->field_teaser[0]['value'];
      }
      else {
        print strip_tags($node->content['body']['#value']);
      }
    ?>

  </div>

<?php else:
//Content
?>
  <?php if($node->title){ ?>
    <h2><?php print $title;?></h2>
  <?php } ?>

  <?php
    // adding warning for event that has already occurred
  if ($past_event): ?>
    <div class="alert"><?php print t('NB! This event occurred in the past.'); ?></div>
  <?php endif; ?>

  <div class="info">
    <div class="meta">
    </div>

    <?php print $content ?>
  </div>

  <div class="meta">
    <?php if (count($taxonomy)){ ?>
      <div class="taxonomy">
        <?php print t("Tags:") . " " .  $terms ?>
      </div>
    <?php } ?>
  </div>

<?php endif; ?>
</div>

