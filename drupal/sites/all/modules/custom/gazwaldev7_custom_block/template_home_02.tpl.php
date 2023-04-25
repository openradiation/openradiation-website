<?php
// block en HOME / Sidebar : S'incrire + Connexion
global $language;
global $user;
?>

<?php
// si le user n'est pas connecté
if (!user_is_logged_in()) { ############################################## ?>
<div class="row">
<div class="col col-sm-6">
	<div class="login-left">
        <p><?php print(t("Sign up to contribute to the radioactivity's open data")); ?></p>
        <a class="btn btn-primary" title="Register" href="/<?php print($language->language); ?>/user/register"><?php print(t("Register")); ?></a>
	</div>
</div>

<div class="col col-sm-6">
	<div class="login-right">
	<?php
	$block = module_invoke('user', 'block_view', 'login');
	print render($block['content']);
	?>	
	</div>
</div>
</div><!-- ! row -->

<?php } else { ############################################## ?>

<?php
// print du block user menu
$block = module_invoke('system', 'block_view', 'user-menu');
print render($block['content']);
?>

<?php } ############################################## ?>


