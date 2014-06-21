<?php

/**
 * @file
 * Administration menu callbacks for pm_response_rate.module.
 */

/**
 * Menu callback for administration settings.
 */
function pm_response_rate_admin_settings_form() {
  $form['rebuild_rates']['rebuild'] = array(
    '#type' => 'fieldset',
    '#title' => t('(Re)Generate the privatemsg response rate data'),
    '#description' => t('Once you have set up your response rate parameters, click here to build/rebuild the response rate data. This may take a few minutes depending on the number of users and messages'),
  );
  $form['rebuild_rates']['rebuild']['pm_response_rate_run_all'] = array(
    '#type' => 'submit',
    '#value' => t('Regenerate'),
    '#submit' => array('_pm_response_rate_run_all_submit'),
  );  
    
  $form['pm_response_rate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Privatemsg response rate settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['pm_response_rate']['pm_response_rate_days_memory'] = array(
    '#type' => 'textfield',
    '#title' => t("Number of days to use in response rate measurement"),
    '#description' => t("Go back this many days in message threads when calcualating the user's response rate."),
    '#default_value' => variable_get('pm_response_rate_days_memory', PM_RESPONSE_RATE_DAYS_MEMORY_DEFAULT),
    '#size' => '3',
    '#weight' => 0,
  );

  $form['pm_response_rate']['pm_response_rate_ideal_min_messages'] = array(
    '#type' => 'textfield',
    '#title' => t("Number of messages to use in response rate measurement"),
    '#description' => t("Ideal minumum number of recent message threads when calculating the user's response rate. If this many cannot be found in the response rate timeframe above, then go back the number of days configured in the extended response rate memory configured below."),
    '#default_value' => variable_get('pm_response_rate_ideal_min_messages', PM_RESPONSE_RATE_IDEAL_MESSAGES_DEFAULT),
    '#size' => '3',
    '#weight' => 5,
  );
  
  $form['pm_response_rate']['pm_response_rate_days_extended_memory'] = array(
    '#type' => 'textfield',
    '#title' => t("Extended number of days to use in response rate measurement"),
    '#description' => t("If the ideal message number is not met in the memory timeframe, go back up to this many days in message history to find messages to calculate response rate"),
    '#default_value' => variable_get('pm_response_rate_days_extended_memory', PM_RESPONSE_RATE_DAYS_EXTENDED_MEMORY_DEFAULT),
    '#size' => '3',
    '#weight' => 10,
  );

  $form['pm_response_rate']['pm_response_rate_minimum_messages'] = array(
    '#type' => 'textfield',
    '#title' => t("Minimum number of messages to use in response rate measurement"),
    '#description' => t("Require at least this many message threads be used in the calculation for response rate. If this many messages are not available in the response rate time frame, then the user will be marked as having not enough data to calculate a response rate"),
    '#default_value' => variable_get('pm_response_rate_minimum_messages', PM_RESPONSE_RATE_MINIMUM_MESSAGES_DEFAULT),
    '#size' => '3',
    '#weight' => 20,
  );
  
  $form['pm_response_rate']['pm_response_rate_grace_period'] = array(
    '#type' => 'textfield',
    '#title' => t("Grace period, in days, before a message is marked as not being responded to"),
    '#description' => t("Before this time has elapsed, the user's response rate will not be affected by a message without a response."),
    '#default_value' => variable_get('pm_response_rate_grace_period', PM_RESPONSE_RATE_GRACE_PERIOD_DEFAULT),
    '#size' => '3',
    '#weight' => 30,
  );

  $form['pm_response_rate']['pm_response_rate_partial_calc_interval'] = array(
    '#type' => 'textfield',
    '#title' => t("Interval, in hours, to wait before paritally re-calculating response rates"),
    '#description' => t("Response rates will be updated in real-time as messages are responded to, however messages that are not responded to need to be handled asynchronously. The time interval set here will be used to determine if response rates of users with unanswered messages that have just passed the grace period should be recalculated or not"),
    '#default_value' => variable_get('pm_response_rate_partial_calc_interval', PM_RESPONSE_RATE_PARTIAL_CALC_INTERVAL_DEFAULT),
    '#size' => '3',
    '#weight' => 35,
  );

  $form['pm_response_rate']['pm_response_rate_full_calc_interval'] = array(
    '#type' => 'textfield',
    '#title' => t("Interval, in days, to wait before fully re-calculating response rates"),
    '#description' => t("As messages age out, response rates should be updated accordingly. This time interval is used to determine if a full recalculation of all response rates should occur."),
    '#default_value' => variable_get('pm_response_rate_full_calc_interval', PM_RESPONSE_RATE_FULL_CALC_INTERVAL_DEFAULT),
    '#size' => '3',
    '#weight' => 35,
  );

  $form['pm_response_rate']['pm_response_rate_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t("Roles for which response rate and time should be calculated"),
    '#options' => user_roles(TRUE),
    '#default_value' => variable_get('pm_response_rate_roles', array(DRUPAL_AUTHENTICATED_RID)),
  );

  $form['pm_response_time'] = array(
    '#type' => 'fieldset',
    '#title' => t('Privatemsg response time settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['pm_response_time']['pm_response_time_algo'] = array(
    '#type' => 'radios',
    '#title' => t("Algorithm for calculating response time"),
    '#default_value' => variable_get('pm_response_time_algo', PM_RESPONSE_TIME_ALGO_AVERAGE),
    '#options' => array(
      PM_RESPONSE_TIME_ALGO_AVERAGE => t('Mathematical average of all response times'),
      PM_RESPONSE_TIME_ALGO_MEDIAN => t('Mathematical median of all response times'),
    ),
  );

  $form = system_settings_form($form);
  return $form;
}

/***
 * Rebuild pm response rate data
 */
function _pm_response_rate_run_all_submit($form, &$form_state) {
  pm_response_rate_regenerate_data();
  drupal_set_message(t('PM Response rates have been regenerated'));
}
