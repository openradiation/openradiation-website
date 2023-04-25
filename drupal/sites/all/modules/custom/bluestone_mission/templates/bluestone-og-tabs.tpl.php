
<?php if($tabs): ?>
    <ul class="nav nav-pills bluestone_og_tabs">
        <?php foreach($tabs as $k => $tab): ?>
            <li style="width:<?php echo 100 / count($tabs) ?>%" role="presentation" class="<?php if($tab['is_active']()){print "active";} ?>">
              <a href="<?php print url($tab['url']) ?>"><?php print $tab['title'] ?></a>
            </li>
        <?php endforeach; ?>
    </ul>
<?php endif; ?>
<?php if(isset($emptytabs) && $emptytabs): ?>
    <ul class="nav nav-pills bluestone_og_tabs"></ul>
<?php endif; ?>