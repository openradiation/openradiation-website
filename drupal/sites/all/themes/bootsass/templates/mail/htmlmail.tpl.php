<?php
/**
 * @file
 * The default template file for e-mails.
 */

$theme_url = drupal_get_path('theme', 'bootsass');
$absolute_theme_url = url(drupal_get_path('theme', 'bootsass'), array('absolute' => TRUE));
?>
<style type="text/css">
table tr td {
  font-family: Helvetica, Arial;
  font-size: 12px;
}
</style>


<table width="800px" border="0" cellpadding="0" cellspacing="0" style="width:100%; background-color: #EEE;">
  <tr>
    <td style="width:15px;"></td>
    <td height="60" valign="middle"><img src="image:<?php print $theme_url . '/logo.png' ?>" alt="Openradiation" height="73" width="170" style="margin-bottom: 15px; margin-top: 20px;"></td>
    <td style="width:15px;"></td>
  </tr>
  <tr>
    <td></td>
    <td style="background-color: #FFF; padding: 15px;">
        <div class="htmlmail-body">
          <?php print $body; ?>
        </div>
    </td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td>&nbsp;</td>
    <td></td>
  </tr>
</table>