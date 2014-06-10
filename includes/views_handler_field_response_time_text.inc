<?php

/**
 * @file
 * Contains the pm_response_rate response_time text field handler.
 */

class views_handler_field_response_time_text extends views_handler_field {

  function render($values) {
    $value = $this->get_value($values);
    $response_time_map = array(
      PM_RESPONSE_RATE_NOT_DEFINED => t("Not available"),
      PM_RESPONSE_RATE_LESS_THAN_12_HOURS => t("Less than 12 hours"),
      PM_RESPONSE_RATE_LESS_THAN_24_HOURS => t("Less than 24 hours"),
      PM_RESPONSE_RATE_LESS_THAN_2_DAYS => t("Less than 2 days"),
      PM_RESPONSE_RATE_LESS_THAN_4_DAYS => t("Less than 4 days"),
      PM_RESPONSE_RATE_LESS_THAN_1_WEEK => t("Less than 1 week"),
      PM_RESPONSE_RATE_LESS_THAN_2_WEEKS => t("Less than 2 weeks"),
      PM_RESPONSE_RATE_MORE_THAN_2_WEEKS => t("More than 2 weeks"),
    );
    return $response_time_map[$value];
  }

}

