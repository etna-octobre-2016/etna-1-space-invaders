/*
* @Author: Bernar_s
* @Date:   2014-09-03 15:45:05
* @Last Modified by:   ahemt_s
* @Last Modified time: 2014-09-18 01:41:30
*/
#ifndef EVENT_H
#define EVENT_H

  typedef           struct
  {
    int             key;
    int             value;
    UT_hash_handle  hh;

  }                 t_events_hash;

  t_events_hash     *events_find_key(int key);
  void              events_add_key(int key, int value);
  void              events_clear();
  void              events_update();
#endif