function update_bundles()
{
    jQuery.getJSON( "/ariane_message_stack_get_bundle/"+jQuery('#ams_entity_type').val(), function( json )
    {
        jQuery('#ams_bundle').html('');
        for (var key in json)
        {
            var entity = json[key];
            jQuery('#ams_bundle').append('<option value="'+key+'">'+entity+'</option>');
        }
        update_machine_name();
    });
}


function update_machine_name()
{
    var str = [];
    var label = [];

    var entity_type_val = jQuery('#ams_entity_type').val();
    var bundle_val = jQuery('#ams_bundle').val();
    var op_val = jQuery('#ams_op').val();
    var op_status = jQuery('#ams_status').val();

    var entity_type_text = jQuery('#ams_entity_type option:selected').text();
    var bundle_text = jQuery('#ams_bundle option:selected').text();
    var op_text = jQuery('#ams_op option:selected').text();
    var all_status = jQuery('#ams_status option:selected').text();

    label.push(op_text);
    label.push(entity_type_text);
    label.push(bundle_text);
    label.push('Status : '+all_status);

    str.push(entity_type_val);
    str.push(bundle_val);
    str.push(op_val);
    str.push(op_status);

    var final_str = str.join('_o_');

    var final_label = '';

    if(label && label.length > 0)
    {
        final_label = label.join(' ');
    }

    jQuery('#edit-description').val(final_label);
    jQuery('#edit-name').val(final_str);
}

function ucfirst(str) {
    str += '';
    var f = str.charAt(0)
        .toUpperCase();
    return f + str.substr(1);
}

jQuery(function() {

    jQuery('#ams_entity_type').change(function(){
        update_bundles();
    });

    jQuery('.message_type_helper').change(function(){
        update_machine_name();
    });

    jQuery.getJSON( "/ariane_message_stack_get_possible_strings", function( possible_strings )
    {
        var default_value = jQuery('#message_stack_helper').attr('value');
        update_bundles();
        jQuery('#message_stack_helper').show();
    });

});

