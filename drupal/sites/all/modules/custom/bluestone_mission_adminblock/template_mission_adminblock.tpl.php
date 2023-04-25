<?php
    $group = '';
    $group_datas = og_context();
    if ($group_datas) {
      $group = $group_datas['gid'];
    }

?>
<?php if (bluestone_og_email_access($group)): ?>

<h2 class="block-title">Administration</h2>
<ul>
    <li><a href="/group/node/<?php print $group; ?>/admin/people/add-user">Ajouter des utilisateurs</a></li>
    <li><a href="/group/node/<?php print $group; ?>/admin/people">Gérer les membres</a></li>
    <?php if (module_exists('og_manager_change')): ?>
    <li><a href="/group/node/<?php print $group; ?>/admin/manager">Changer le responsable du groupe</a></li>
    <?php endif; ?>
    <li><a href="/mission/<?php print $group; ?>/email">Envoyer un mail aux membres</a></li>
</ul>

<?php endif; ?>