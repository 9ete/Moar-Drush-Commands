<?php
/**
 *   Drush command.
 */
function moar_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['den'] = array(
    // a short description of your command
    'description' => "Download and Enable Module.",
  );
  $items['reinstall'] = array(
    // a short description of your command
    'description' => "Disable, Uninstall, and Re-Enable Module.",
  );
  $items['ren'] = array(
    // a short description of your command
    'description' => "Disable, Uninstall, and Re-Enable Module.",
    'callback' => 'drush_moar_reinstall',
  );
  $items['dun'] = array(
    // a short description of your command
    'description' => "Disable and Uninstall Module.",
  );
  $items['site-offline'] = array(
    // a short description of your command
    'description' => "Take the site offline.",
  );
  $items['soff'] = array(
    // a short description of your command
    'description' => "Take the site offline.",
    'callback' => 'drush_moar_site_offline',
  );
  $items['site-online'] = array(
    // a short description of your command
    'description' => "Put the site online.",
  );
  $items['son'] = array(
    // a short description of your command
    'description' => "Put the site online.",
    'callback' => 'drush_moar_site_online',
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function moar_drush_help($section) {
  switch ($section) {
    case 'drush:den':
      return dt("Downloads and enables module(s).");
      break;
    case 'drush:ren':
    case 'drush:reinstall':
      return dt("Disables, Uninstalls, and Re-Enables Module(s).");
      break;
    case 'drush:dun':
      return dt("Disables and Uninstalls Module(s).");
      break;
    case 'drush:soff':
    case 'drush:site-offline':
      return dt("Puts the site offline.");
      break;
    case 'drush:son':
    case 'drush:site-online':
      return dt("Puts the site online.");
      break;
  }
}

/**
 * Drush command callback. This is where the action takes place.
 */
function drush_moar_den() {
  $args = func_get_args();
  //print_r($args);
  foreach($args as $id => $module){
    drush_pm_download($module);
    drush_pm_enable($module);
  }
}

function drush_moar_reinstall() {
  $args = func_get_args();
  //print_r($args);
  foreach($args as $id => $module){
    drush_pm_disable($module);
    drush_pm_uninstall($module);
    drush_pm_enable($module);
  }
}

function drush_moar_dun() {
  $args = func_get_args();
  //print_r($args);
  foreach($args as $id => $module){
    drush_pm_disable($module);
    drush_pm_uninstall($module);
  }
}

function drush_moar_site_offline(){
  $args = func_get_args();
  drush_variable_set("site_offline", "1");
}

function drush_moar_site_online(){
  $args = func_get_args();
  //drush_variable_set("site_offline", 1);
  drush_variable_delete("site_offline");
}