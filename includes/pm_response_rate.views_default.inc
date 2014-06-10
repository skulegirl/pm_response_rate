<?php

/* 
 * Implementation of hook_views_default_views()
 */

function pm_response_rate_views_default_views() {
  $view = new view;
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
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No response rate is available for this user. See our FAQ about response rates for more details.';
  $handler->display->display_options['empty']['area']['format'] = '2';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Privatemsg: Response Rate */
  $handler->display->display_options['fields']['response_rate']['id'] = 'response_rate';
  $handler->display->display_options['fields']['response_rate']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['response_rate']['field'] = 'response_rate';
  $handler->display->display_options['fields']['response_rate']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['external'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['response_rate']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['response_rate']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['response_rate']['alter']['html'] = 0;
  $handler->display->display_options['fields']['response_rate']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['response_rate']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['response_rate']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['response_rate']['hide_empty'] = 0;
  $handler->display->display_options['fields']['response_rate']['empty_zero'] = 0;
  $handler->display->display_options['fields']['response_rate']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['response_rate']['format_plural'] = 0;
  $handler->display->display_options['fields']['response_rate']['suffix'] = '%';
  /* Field: Customfield: PHP code */
  $handler->display->display_options['fields']['phpcode']['id'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['table'] = 'customfield';
  $handler->display->display_options['fields']['phpcode']['field'] = 'phpcode';
  $handler->display->display_options['fields']['phpcode']['label'] = '';
  $handler->display->display_options['fields']['phpcode']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['external'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['phpcode']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['phpcode']['alter']['html'] = 0;
  $handler->display->display_options['fields']['phpcode']['element_type'] = '0';
  $handler->display->display_options['fields']['phpcode']['element_label_type'] = '0';
  $handler->display->display_options['fields']['phpcode']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['phpcode']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['phpcode']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['phpcode']['hide_empty'] = 0;
  $handler->display->display_options['fields']['phpcode']['empty_zero'] = 0;
  $handler->display->display_options['fields']['phpcode']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['phpcode']['value'] = '<?php
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
  /* Field: Privatemsg: Response Time */
  $handler->display->display_options['fields']['response_time']['id'] = 'response_time';
  $handler->display->display_options['fields']['response_time']['table'] = 'pm_response_rate';
  $handler->display->display_options['fields']['response_time']['field'] = 'response_time';
  $handler->display->display_options['fields']['response_time']['label'] = 'Average Response Time';
  $handler->display->display_options['fields']['response_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['response_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['response_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['response_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['response_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['response_time']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['response_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['response_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['response_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['response_time']['hide_alter_empty'] = 1;
  /* Argument: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter: Privatemsg: Response Rate */
  $handler->display->display_options['filters']['response_rate']['id'] = 'response_rate';
  $handler->display->display_options['filters']['response_rate']['table'] = 'pm_response_rate';
  $handler->display->display_options['filters']['response_rate']['field'] = 'response_rate';
  $handler->display->display_options['filters']['response_rate']['operator'] = 'not empty';
  $handler->display->display_options['filters']['response_rate']['allow_null'] = 0;

  /* Display: Response Rate Pane */
  $handler = $view->new_display('panel_pane', 'Response Rate Pane', 'user_response_rate_pane');

  $views[$view->name] = $view;
  return $views;
}
