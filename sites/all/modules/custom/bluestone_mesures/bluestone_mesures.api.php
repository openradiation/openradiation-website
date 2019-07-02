<?php

/**
 * Do something when a qualification is updated
 *
 * @see bluestone_measurements_qualification_calculate() for qualification array documentation
 * @param array $qualification
 */
function hook_measurement_qualification_update($qualification) {
  $term = $qualification['term'];
  $node = $qualification['node'];
  $api = openradiationApi::getInstance();
  $datas = ['qualification' => $term->field_term_machine_name['und'][0]['safe_value']];
  $api->post("/measurements/$node->uuid", $datas);
}