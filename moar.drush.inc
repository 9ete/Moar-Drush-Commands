<?php
// $Id: example.drush.inc,v 1.1 2010/03/26 18:48:47 greg1anderson Exp $

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
  $items['dun'] = array(
    // a short description of your command
    'description' => "Disable and Uninstall Module.",
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function moar_drush_help($section) {
  switch ($section) {
    case 'drush:den':
      return dt("Downloads and enables modules.");
    case 'drush:reinstall':
      return dt("Disable, Uninstall, and Re-Enable Modules.");
    case 'drush:dun':
      return dt("Disable and Uninstall Module.");
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