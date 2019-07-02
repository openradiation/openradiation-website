<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<!--
THIS FILE IS NOT USED AND IS HERE AS A STARTING POINT FOR CUSTOMIZATION ONLY.
See http://api.drupal.org/api/function/theme_field/7 for details.
After copying this file to your theme's folder and customizing it, remove this
HTML comment.
-->
<?php 
$icotype = array_merge(
	array_fill_keys(array('jpeg','jpg','gif','png','tiff','bmp'), 'image'),
	array_fill_keys(array('ppt','pptx'), 'powerpoint'),
	array_fill_keys(array('doc','docx','rtf', 'txt'), 'word'),
	array_fill_keys(array('xls','xlsx','csv'), 'excel'),
	array('pdf' => 'pdf')
);


?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="document-files-bloc field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="document-file-bloc field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php 
	  //krumo($item);
	  $file = $item['#file'];
	  $file_extension = strtolower(pathinfo($file->filename, PATHINFO_EXTENSION));
    $icotype_class = 'icon-file-document';
    if (isset($icotype[$file_extension]))
      $icotype_class = 'icon-file-' . $icotype[$file_extension];
	  ?>
			<div class="big-icon">
				<span class="<?php print $icotype_class ?> fa-4x icon-gray pull-left"></span>
			</div>
			<div class="big-icon-text">
				<strong>Télécharger le document</strong><br>
				<a href="<?php print file_create_url($file->uri) ?>" 
				type="<?php print $file->filemime ?>; length=<?php print $file->filesize ?>"><?php
				print $file->filename ?></a><br>
				(<?php print field_file_human_filesize($file->filesize);  ?>)
			</div>
	  
	  </div>
    <?php endforeach; ?>
  </div>
</div>

<?php
function field_file_human_filesize($bytes, $decimals = 2) {
  $sz = ' KMGTP';
  $factor = floor((strlen($bytes) - 1) / 3);
  return sprintf("%.{$decimals}f", $bytes / pow(1024, $factor)) . ' ' . @$sz[$factor] . 'o';
}
