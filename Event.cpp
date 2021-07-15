#include<iostream>
#include<string>
#include "Date.h"
#include "Event.h"

using namespace std;

string Event::ToString() const{
		return date.ToString() + ": " + desc;
}
