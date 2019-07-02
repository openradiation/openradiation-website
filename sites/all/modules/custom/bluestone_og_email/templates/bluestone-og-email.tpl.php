<div class="container-fluid">
    <table class="table table-bordered">
        <tr>
            <td><?php print t('Email') ?></td>
            <td><?php print t('Date d\'inscription') ?></td>
        </tr>
        <?php foreach($users as $u): ?>
            <?php dsm($u) ?>
            <tr>
                <td><?php print $u->mail ?></td>
                <td><?php print format_date($u->created) ?></td>
            </tr>
        <?php endforeach; ?>
    </table>
</div>