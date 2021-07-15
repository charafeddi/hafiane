#include<iostream>
#include<string>
#ifndef EVENT_H
#define EVENT_H
#include "Date.h"

using namespace std;

class Event{
	public:
		Date date;
		string desc;
		string ToString ()const;
};

#endif
