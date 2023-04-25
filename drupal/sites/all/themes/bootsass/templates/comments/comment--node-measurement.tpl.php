<?php
$u = user_load($comment->uid);
?>

<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
  <table class="comment_table">
    <tr>
      <td rowspan="3" valign="top" class="picture">
        <?php print $picture ?>
      </td>
      <td>
        <span class="username"><?php print $u->name ?></span>
        <span class="date"><?php print format_date($comment->created) ?></span>
      </td>
      <td class="comment_quali" width="290">
        <?php if(isset($content["field_measure_qualification"])): ?>
          <?php

          $tid = $comment->field_measure_qualification[LANGUAGE_NONE][0]['tid'];
          $term = taxonomy_term_load($tid);

          ?>
          <div style="background-color:<?php print $term->field_color[LANGUAGE_NONE][0]["rgb"] ?>;" class="field field-name-field-measure-qualification field-type-taxonomy-term-reference field-label-hidden">
            <div class="field-items">
                <div class="field-item even"><?php print t(check_plain($term->name)); ?></div>
            </div>
          </div>

        <?php endif; ?>
      </td>
      <td class="rating_comment" width="150">
        <?php if(isset($content["field_measure_qualification"])) {
            print render($content["rate_qualification_vote"]) ;
        } ?>
      </td>
    </tr>
    <tr>
      <td class="comment_body" colspan="3">
        <?php print render($content["comment_body"]); ?>
      </td>
    </tr>
    <tr>
      <td colspan="4" class="reply_form">
        <?php print render($content['links']) ?>
      </td>
    </tr>
  </table>
    </div>
</div>