<?php
// block en HOME / Sidebar : Construire son capteur + Télécharger l'application
?>

<div class="wrapper clearfix">
	<a class="capteur" title="" href="<?php global $language; if ($language->name == "English"): echo url('/how-can-you-acquire-sensor'); else: echo url('/comment-se-procurer-un-capteur'); endif; ?>"><?php echo t("Build your own sensor") ?></a>
	<a class="app" title="" href="<?php global $language; if ($language->name == "English"): echo url('/download-application'); else: echo url('/telecharger-lapplication'); endif; ?>"><?php echo t("Download application") ?></a>
</div>
<!--<a class="clearboth" title="" href="<?php echo url('') ?>"><img class="img-responsive" src="http://placehold.it/900x450&text=TEST TEST TEST"></a>-->
<!--<iframe height="300px" width="100%" src="https://www.youtube.com/embed/TRL7o2kPqw0" frameborder="0" allowfullscreen=""></iframe>-->
<img class="img-responsive" src="/sites/all/modules/custom/gazwaldev7_custom_block/photo_mesure.jpg">
