<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php //krumo($node); ?>


<div id="node-<?php print $node->nid; ?>" class="node-teaser <?php print $classes; ?> clearfix media"<?php print $attributes; ?>>
  <span class="icon-pencil"></span>
  <div>
  <?php print render($title_prefix); ?>
    <div<?php print $title_attributes; ?>>
		<a href="<?php print $node_url; ?>"><h3><?php print $title; ?></h3></a>
		<?php if ($comment_count): ?>
			<span class="badge" data-toggle="tooltip" data-placement="top" title="<?php print format_plural($comment_count, 'Il y a un commentaire sur cette rédaction collaborative', 'Il y a @count commentaires sur cette rédaction collaborative') ?>"><?php print $comment_count ?></span> 
		<?php endif; ?>
		<?php $new_comments = comment_num_new($node->nid); ?>
		<?php if ($new_comments): ?>
			<span class="badge badge-success" data-toggle="tooltip" data-placement="top" title="<?php print format_plural($new_comments, 'Il y a un nouveau commentaire sur cette rédaction collaborative', 'Il y a @count nouveaux commentaires sur cette rédaction collaborative') ?>"><?php print $new_comments ?></span>
		<?php endif; ?>
	</div>
  <?php print render($title_suffix); ?>
  
  <?php
	$date = $created;
    $submitted = 'Créé par ' . $user_picture . $name . ', le ' . format_date($date, $type = 'short');
	if ($changed != $created) {
		$date = $changed;
		$submitted = 'Modifié par ' . $user_picture . $name . ', le ' . format_date($date, $type = 'short');
	}
	if (isset($last_comment_timestamp) && $last_comment_timestamp > $date) {
		$date = $last_comment_timestamp;
		$user = user_load($last_comment_uid);
		$user_picture = theme('user_picture', array('account' =>$user));
		$name = theme('username', array('account' =>$user));
		$submitted = 'Commenté par ' . $user_picture . $name . ', le ' . format_date($date, $type = 'short');
	}
  ?>
  
    <div class="submitted">  
	  <?php //print $user_picture; ?>
      <?php //print $submitted; ?>
    </div>
  </div>
  
  <div class="mission-teaser-summary">
    <?php 
    $teaser = field_view_field('node', $node, 'body', array(
      'label'=>'hidden', 'type' => 'text_summary_or_trimmed', 'settings'=>array('trim_length' => 500),
    ));
    print render($teaser);?>
  </div>
</div>
<div class="clearfix"></div>