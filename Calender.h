#include<iostream>
#include <vector>
#include "Date.h"
#include "Event.h"

#ifndef CALENDER_H
#define CALENDER_H

using namespace std;

class Calender{
	private:
		Date localDate;
		vector <Event> event;
	public:
		Calender();// the constractor 
		void Run(); //Main Menu system
		void Draw(); //Main calendar draw loop
		void NextMonth(); // Print Next month
		void PreviousMonth(); //Print Previous Month
		void InputDate(); // print a calendar corresponding to user input
		void CreateEvent(); //get date from users and create and event
		void ListEvents(); //List all event created while program was running
		void DeleteEvent(); // Delete e selected event;
		void Save(); //save all event to event file
		void Load(); //Load all event from event file
};

#endif
