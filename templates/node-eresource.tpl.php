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
  <?php if ($field_list_image) { ?>
     <div class="logo">
       <?php print $field_list_image[0]['view']; ?>
     </div>
  <?php } ?>

  <?php if($node->title){ ?>
    <h2><?php print $title;?></h2>
  <?php } ?>

  <div class="info">
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

