/*
* @Author: Bernar_s
* @Date:   2014-09-03 15:45:05
* @Last Modified by:   Bernar_s
* @Last Modified time: 2014-09-03 15:45:10
*/

#include "uthash.h"

#ifndef EVENT_H
#define EVENT_H

	typedef struct 
	{
		int key;
		int value;
		UT_hash_handle hh; /* makes this structure hashable */
	} hash;

	hash *find_key(int key);
	void add_key(int key, int value);

	void UpdateEvents();
#endif