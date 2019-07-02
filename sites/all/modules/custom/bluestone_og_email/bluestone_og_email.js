jQuery( document ).ready(function() {
    jQuery('body').on('change', '#og_email_select_all input', function(e){
        var elt = jQuery(this);
        var ch = elt.is(':checked');
        if(ch)
        {
            elt.parent().find('label').text('Tout désélectionner');
            jQuery('#edit-users .form-checkbox').each(function(){
                this.checked = true;
            });
        }
        else
        {
            elt.parent().find('label').text('Tout sélectionner');
            jQuery('#edit-users .form-checkbox').each(function(){
                this.checked = false;
            });
        }

    });
    //
});