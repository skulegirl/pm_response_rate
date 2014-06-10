<?php

/**
 * This file is used to tell the views module about the pm_response_rate table.
 *
 * Database definition:
 * @code
 * CREATE TABLE `pm_response_rate` (
 *   `uid` int(10) unsigned NOT NULL,
 *   `revisit_time` int(10) unsigned NOT NULL DEFAULT '0',
 *   `response_rate` int(10) unsigned DEFAULT NULL,
 *   `response_time` int(10) unsigned NOT NULL DEFAULT '0',
 *   `messages_used` int(10) unsigned NOT NULL DEFAULT '0',
 *   PRIMARY KEY (`uid`),
 *   KEY `updates` (`revisit_time`)
 * ) ENGINE=InnoDB DEFAULT CHARSET=utf8; 
 * @endcode   
 */

/**
 * Implement hook_views_data()
 */
function pm_response_rate_views_data() 
{
  $data['pm_response_rate'] = array(
    'table' => array(
      'group' => t('Privatemsg'),
      'base' => array(
        'field' => 'uid',
        'title' => t('Privatemsg Response Rate'),
        'help' => t('Response rate for private messages sent to users'),
      ),
      'join' => array(
        'users' => array(
          'left_field' => 'uid',
          'field' => 'uid'
        ),
        'node' => array(
          'left_field' => 'uid',
          'field' => 'uid',
        ),
      ),
    ),
  );

  // Describe the columns of the pm_response_rate table that are available
  $data['pm_response_rate']['revisit_time'] = array(
    'title' => t('Revisit Time'),
    'help' => t('The time that this user will be revisited to update response rate after gracetime expires'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['pm_response_rate']['response_rate'] = array(
    'title' => t('Response Rate'),
    'help' => t('The response rate, as a percentage, for the user\'s private messages'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pm_response_rate']['response_time'] = array(
    'title' => t('Response Time'),
    'help' => t('The average response time for the user'),
    'field' => array(
      'handler' => 'views_handler_field_response_time_text',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['pm_response_rate']['messages_used'] = array(
    'title' => t('Messages Used'),
    'help' => t('The number of messages used in calculations'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Add relationship to user table
  $data['pm_response_rate']['uid'] = array(
    'title' => t('User'),
    'help' => t('Relate privatemsg response rate table to the user table'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Users'),
      'handler' => 'views_handler_relationship',
    ),
  );
  dd($data, 'pm_response_rate_views_data');
  return $data;
}

function pm_response_rate_views_handlers() 
{
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'pm_response_rate') . '/includes',
    ),
    'handlers' => array(
      // field handlers
      'views_handler_field_response_time_text' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
