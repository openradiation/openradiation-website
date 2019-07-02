<?php

/**
 * @file
 * Contains geolocation field migration handler.
 */

/**
 * Geolocation field migration handler class.
 *
 * Geolocation field requires both latitude and longitude values, so it doesn't
 * make sense to use the primary value, i.e. map to field itself.
 * In order to use it, please map values to the subfields (mapping to the field
 * won't work).
 *
 * Subfields:
 *   - 'lat': Geolocation field latitude value.
 *   - 'lng': Geolocation field longitude value.
 *   - 'language': Geolocation field value language.
 *
 * See more at https://www.drupal.org/node/2671068
 */
class MigrateGeolocationFieldHandler extends MigrateFieldHandler {

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    $this->registerTypes(array('geolocation_latlng'));
  }

  /**
   * {@inheritdoc}
   */
  static public function arguments($lat = NULL, $lng = NULL, $language = NULL) {
    $arguments = array();
    if (!is_null($lat)) {
      $arguments['lat'] = $lat;
    }
    if (!is_null($lng)) {
      $arguments['lng'] = $lng;
    }
    if (!is_null($language)) {
      $arguments['language'] = $language;
    }
    return $arguments;
  }

  /**
   * {@inheritdoc}
   */
  public function fields($type, $instance, $migration = NULL) {
    return array(
      'lat' => t('Subfield: Geolocation field latitude value'),
      'lng' => t('Subfield: Geolocation field longitude value'),
      'language' => t('Subfield:  Geolocation field value language'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {

    $arguments = isset($values['arguments']) ? $values['arguments'] : array();
    $arguments += array(
      'lat' => array(),
      'lng' => array(),
    );

    // When a single value is mapped to an argument, Migrate module doesn't wrap
    // it in array.
    foreach (array('lat', 'lng') as $subelement) {
      if (!is_array($arguments[$subelement])) {
        $arguments[$subelement] = array($arguments[$subelement]);
      }
    }

    $return = array();
    foreach ($arguments['lat'] as $delta => $value) {
      $item = array(
        'lat' => $arguments['lat'][$delta],
        'lng' => isset($arguments['lng'][$delta]) ? $arguments['lng'][$delta] : NULL,
      );

      if ($this->validate($entity, $field_info, $instance, $item)) {
        $language = $this->getGeolocationFieldLanguage($entity, $field_info, $arguments, $delta);
        $return[$language][] = _geolocation_field_precalculate_values($item);
      }
    }

    return !empty($return) ? $return : NULL;
  }

  /**
   * Determines field language.
   *
   * @param object $entity
   *   Entity being processed.
   * @param array $field_info
   *   Field info.
   * @param array $arguments
   *   Arguments passed to the field migration handler.
   * @param int $delta
   *   Field values delta.
   *
   * @return string
   *   Language code.
   *
   * @see MigrateFieldHandler::getFieldLanguage()
   */
  public function getGeolocationFieldLanguage($entity, array $field_info, array $arguments, $delta = 0) {
    static $language = NULL;

    if (is_null($language)) {
      $language = $this->getFieldLanguage($entity, $field_info, $arguments);
    }

    if (!is_array($language)) {
      return $language;
    }
    else {
      if (!empty($language[$delta])) {
        return $language[$delta];
      }
      else {
        return LANGUAGE_NONE;
      }
    }
  }

  /**
   * Validates given geolocation field value item.
   *
   * @param object $entity
   *   Entity being processed.
   * @param array $field_info
   *   Field info.
   * @param array $instance
   *   Field instance.
   * @param array $item
   *   Field values delta.
   *
   * @return bool
   *   TRUE if given item contains valid geolocation field value, FALSE -
   *   otherwise.
   */
  protected function validate($entity, array $field_info, array $instance, array $item) {
    $item_is_valid = TRUE;

    $migration = Migration::currentMigration();

    if (((string) $item['lat'] === '') || ((string) $item['lng'] === '')) {
      $migration->saveMessage(t('%name: both latitude and longitude values are required.', array('%name' => $instance['label'])), Migration::MESSAGE_ERROR);
      $item_is_valid = FALSE;
    }
    if (!is_numeric($item['lat']) || !is_numeric($item['lng'])) {
      $migration->saveMessage(t('%name: only numeric values are acceptable.', array('%name' => $instance['label'])), Migration::MESSAGE_ERROR);
      $item_is_valid = FALSE;
    }
    if ($item['lat'] < -90 || $item['lat'] > 90 || $item['lng'] < -180 || $item['lng'] > 180) {
      $migration->saveMessage(t('%name: invalid latitude or longitude has been provided.', array('%name' => $instance['label'])), Migration::MESSAGE_ERROR);
      $item_is_valid = FALSE;
    }

    return $item_is_valid;
  }

}
