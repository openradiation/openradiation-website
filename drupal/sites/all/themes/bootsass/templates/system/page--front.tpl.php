<!-- <span class="boot-debug"></span>  -->

<?php include('header.inc'); ?>

<div class="main-container container">
	<header role="banner" id="page-header">
		<?php if (!empty($site_slogan)): ?>
		<p class="lead"><?php print $site_slogan; ?></p>
	<?php endif; ?>
	<?php print render($page['header']); ?>
</header> <!-- /#page-header -->

<div id="page-row-top" class="row no-gutter">

	<?php if (!empty($page['sidebar_first'])): ?>
	<aside class="col-sm-3" role="complementary">
		<?php print render($page['sidebar_first']); ?>
	</aside>
	<!-- /#sidebar-first -->
	<?php endif; ?>

	<section<?php print $content_column_class; ?>>
	<?php print $messages; ?>
	<?php if (!empty($tabs)): ?>
		<?php print render($tabs); ?>
	<?php endif; ?>
	<?php if (!empty($action_links)): ?>
		<ul class="action-links"><?php print render($action_links); ?></ul>
	<?php endif; ?>
	
	<?php if ($page['front_01']) { ?>
		<?php print render($page['front_01']); ?>
	<?php } ?>

	<?php if ($page['front_02']) { ?>
		<?php print render($page['front_02']); ?>
	<?php } ?>

	<?php if ($page['front_03']) { ?>
		<?php print render($page['front_03']); ?>
	<?php } ?>
	</section>

	<?php if (!empty($page['sidebar_second'])): ?>
		<aside class="col-sm-4" role="complementary">
			<?php print render($page['sidebar_second']); ?>
		</aside>  <!-- /#sidebar-second -->
	<?php endif; ?>

</div><!-- ! row -->

</div><!-- ! main-container container -->

<?php include('footer.inc'); ?>