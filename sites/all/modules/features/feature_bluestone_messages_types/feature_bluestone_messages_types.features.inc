<?php
/**
 * @file
 * feature_bluestone_messages_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_bluestone_messages_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function feature_bluestone_messages_types_default_message_type() {
  $items = array();
  $items['measurement_update'] = entity_import('message_type', '{
    "name" : "measurement_update",
    "description" : "Mise a jours d\\u0027une mesure",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "fr",
    "arguments" : null,
    "message_text" : { "fr" : [
        {
          "value" : "\\u003Cp\\u003ENew measurement update\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ENew measurement update\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUne mesure \\u00e0 \\u00e9t\\u00e9 mise a jours .....\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUne mesure \\u00e0 \\u00e9t\\u00e9 mise a jours .....\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_comment_group_content'] = entity_import('message_type', '{
    "name" : "new_comment_group_content",
    "description" : "New comment group content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "fr",
    "arguments" : null,
    "message_text" : { "fr" : [
        {
          "value" : "\\u003Cp\\u003ENew comment group content\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ENew comment group content\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUn nouveau comentaire a ete post\\u00e9 sur un contenue de group .....\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUn nouveau comentaire a ete post\\u00e9 sur un contenue de group .....\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_comment_measure'] = entity_import('message_type', '{
    "name" : "new_comment_measure",
    "description" : "New comment on measure",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "fr",
    "arguments" : null,
    "message_text" : { "fr" : [
        {
          "value" : "New comment on measure",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew comment on measure\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-comment-ref:body]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-comment-ref:body]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_group_content'] = entity_import('message_type', '{
    "name" : "new_group_content",
    "description" : "New group content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "fr",
    "arguments" : null,
    "message_text" : { "fr" : [
        {
          "value" : "\\u003Cp\\u003ENew group content\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ENew group content\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUn nouveau contenue a ete post\\u00e9 dans une group .....\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUn nouveau contenue a ete post\\u00e9 dans une group .....\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
