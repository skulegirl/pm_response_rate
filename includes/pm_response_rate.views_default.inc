<?php

/* 
 * Implementation of hook_views_default_views()
 */

function pm_response_rate_views_default_views() {
  /* User response rate view (for user pages) */
  $view = new view();
  $view->name = 'user_response_rate';
  $view->description = 'View with basic user response rate data to go in a panel on user page';
  $view->tag = '';
  $view->base_table = 'users';
  $view->human_name = 'Response Rate';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Response Rate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No response rate is available for this user. See our FAQ about response rates for more details.';
  $handler->display->display_options['empty']['area']['format'] = '2';
  /* Field: Privatemsg: Response Rate */
  $handler->display->display_options['fields']['response_rate']['id'] = 'response_rate';
  $handler->display->display_options['fields']['response_rate']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['response_rate']['field'] = 'response_rate';
  $handler->display->display_options['fields']['response_rate']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['response_rate']['suffix'] = '%';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_type'] = '0';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
        $thumbsUpLoc = drupal_get_path(\'module\', \'pm_response_rate\') . \'/images/ThumbsUp.png\';
        $thumbsDownLoc = drupal_get_path(\'module\', \'pm_response_rate\') . \'/images/ThumbsDown.png\';
        if ($data->pm_response_rate_response_rate >= 80)
        {
           // output thumbs up
           
           echo "<img class=\'response-rate-icon\' src=\'/" . $thumbsUpLoc . "\' width=\'30px\'>";
        }
        else if ($data->pm_response_rate_response_rate <50)
        {
          // output thumbs down
           echo "<img class=\'response-rate-icon\' src=\'/" . $thumbsDownLoc . "\' width=\'30px\'>";
        }
        ?>
        ';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Privatemsg: Response Time */
  $handler->display->display_options['fields']['response_time']['id'] = 'response_time';
  $handler->display->display_options['fields']['response_time']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['response_time']['field'] = 'response_time';
  $handler->display->display_options['fields']['response_time']['label'] = 'Average Response Time';
  $handler->display->display_options['fields']['response_time']['element_wrapper_type'] = 'div';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Privatemsg: Response Rate */
  $handler->display->display_options['filters']['response_rate']['id'] = 'response_rate';
  $handler->display->display_options['filters']['response_rate']['table'] = 'pm_response_rate';
  $handler->display->display_options['filters']['response_rate']['field'] = 'response_rate';
  $handler->display->display_options['filters']['response_rate']['operator'] = 'not empty';

  /* Display: Response Rate Pane */
  $handler = $view->new_display('panel_pane', 'Response Rate Pane', 'user_response_rate_pane');
  $views[$view->name] = $view;

  /* All User Response Rate view */
  $view = new view();
  $view->name = 'all_user_response_rates';
  $view->description = 'View with basic user response rate data to go in a panel on user page';
  $view->tag = '';
  $view->base_table = 'users';
  $view->human_name = 'All Response Rate';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Response Rate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view privatemsg response rate data';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'response_rate' => 'response_rate',
    'php' => 'php',
    'response_time' => 'response_time',
  );
  $handler->display->display_options['style_options']['default'] = 'response_rate';
  $handler->display->display_options['style_options']['info'] = array(
    'response_rate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
    ),
    'response_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No response rate is available for this user. See our FAQ about response rates for more details.';
  $handler->display->display_options['empty']['area']['format'] = '2';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
      $thumbsUpLoc = drupal_get_path(\'module\', \'pm_response_rate\') . \'/images/ThumbsUp.png\';
      $thumbsDownLoc = drupal_get_path(\'module\', \'pm_response_rate\') . \'/images/ThumbsDown.png\';
      if ($data->pm_response_rate_response_rate >= 80)
      {
         // output thumbs up
         
         echo "<img class=\'response-rate-icon\' src=\'/" . $thumbsUpLoc . "\' width=\'30px\'>";
      }
      else if ($data->pm_response_rate_response_rate <50)
      {
        // output thumbs down
         echo "<img class=\'response-rate-icon\' src=\'/" . $thumbsDownLoc . "\' width=\'30px\'>";
      }
      ?>
      ';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Privatemsg: Response Rate */
  $handler->display->display_options['fields']['response_rate']['id'] = 'response_rate';
  $handler->display->display_options['fields']['response_rate']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['response_rate']['field'] = 'response_rate';
  $handler->display->display_options['fields']['response_rate']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['response_rate']['suffix'] = '%';
  /* Field: Privatemsg: Response Time */
  $handler->display->display_options['fields']['response_time']['id'] = 'response_time';
  $handler->display->display_options['fields']['response_time']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['response_time']['field'] = 'response_time';
  $handler->display->display_options['fields']['response_time']['label'] = 'Average Response Time';
  $handler->display->display_options['fields']['response_time']['element_wrapper_type'] = 'div';
  /* Field: Privatemsg: Messages Used */
  $handler->display->display_options['fields']['messages_used']['id'] = 'messages_used';
  $handler->display->display_options['fields']['messages_used']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['messages_used']['field'] = 'messages_used';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Filter criterion: Privatemsg: Response Rate */
  $handler->display->display_options['filters']['response_rate']['id'] = 'response_rate';
  $handler->display->display_options['filters']['response_rate']['table'] = 'pm_response_rate';
  $handler->display->display_options['filters']['response_rate']['field'] = 'response_rate';
  $handler->display->display_options['filters']['response_rate']['operator'] = 'not empty';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    8 => '8',
  );

  /* Display: All User Response Rates */
  $handler = $view->new_display('page', 'All User Response Rates', 'all_user_response_rates');
  $handler->display->display_options['path'] = 'user_response_rates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User Response Rates';
  $handler->display->display_options['menu']['weight'] = '20';

  $views[$view->name] = $view;

  return $views;
}
