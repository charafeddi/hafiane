#include<iostream>
#include<ctime>
#include<iomanip>
#include<fstream>
#include "Date.h"
#include "Event.h"
#include "Calender.h"

using namespace std;

 Calender::Calender(){
 }
 
 /*********************************************
 in this function we will make the system Menu
 *********************************************/
 void Calender::Run(){
int work=1;

while (work==1) {

char op;
string file;
cout
	<< "\nPress 'N': Show the calendar for the next month: \n"
	<< "Press'P': Show the calendar for the previous month: \n" 
	<< "Press'C': Input year and month,the program will show the calendar as you inputted: "
	<< "\nPress'A'': Input year/month/day, then input a description,it will add an event to the calendar: \n" 
	<< "Press'L': Show all events you have created.each one with an ID: \n"
	<< "Press'D': Input event ID, delete the event with this ID: " 
	<< "\nPress'S': Input a file name, save the events you have created in this calendar program to a file in the disk: \n"
	<< "Press'R': Input a file name, load the events you have saved: \n" 
	<< "Press'Q': Exit the program: \n" 
	<< "\nInput your command ";
	cin >> op;
if (op >= 'a' && op <= 'z') op += ('A' - 'a');

switch (op) {
case 'N':
NextMonth();
Draw();
break;
case 'P':
PreviousMonth();
Draw();
break;
case 'C':
InputDate();
Draw();
break;
case 'A':
CreateEvent();
break;
case 'L':
ListEvents();
break;
case 'D':
DeleteEvent();
break;
case 'S':
Save();
break;
case 'R':
Load();
break;
case 'Q':
 work=0;
break;
default:
cout << "Invalid input." << endl;
break;
}
}
}
/************************************
  in this function we draw the calender 
**************************************/ 
 void Calender::Draw(){
 int year = localDate.getYear();
 int month = localDate.getMonth();

 cout << " " << Date::MonthNames[month - 1];
 cout << " " << year << endl;

 cout << "**************************" << endl;

 for (int i = 0; i < sizeof Date::DayNames / sizeof Date::DayNames[0]; ++i) {
  cout << Date::DayNames[i] << " ";
 }
 cout << endl;

 int y = year - (month < 3);
 static int t[] = { -1, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
 int startingDay;
 int d = 1;
 int c,m;
 bool leap = false;
 
 if (month == 1 || month == 2) {
  d = 0;
  y = (year - 1) % 100; c = (year - 1) / 100;
   m = month + 12; 
 }else {
  y = year % 100; c = year / 100; m = month;
 }
 
 startingDay = ((y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10) % 7 + 7) % 7;
 
 if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
 {
  leap = true;
 }
 
 int dayCount = Date::MonthDays[month - 1];
 
 for (int x = 0; x < startingDay; ++x) {
  cout << "    ";
 }


 for (int d = 0; d < dayCount; ++d) {
  if (d < 9){ 
   cout << "0" << d + 1 << "  ";
  }else{
   cout << d + 1 << "  ";
  }

  ++startingDay;
  if (startingDay == 7) {
   startingDay = 0;
   cout << endl;
  }
  
  if (month == 2 &&d == 27&&leap==true) {
   cout  << "29";
  }
 }

 cout << endl;
}

//**************************************
//in this function we display next month
//**************************************

void Calender::NextMonth() {
localDate.IncreaseMonth ();
}

//*****************************************
//in this function we display previous month
//******************************************

void Calender::PreviousMonth() {
localDate.DecreaseMonth();
}

/******************************************************
/* printing the calender acording to the user date input
********************************************************/


/*
in this function we will get the date from the user 
*/
void Calender::InputDate() {
int year, month, day;
do {
cout << "Year:";
cin >>year;
} while (year < 0);

do {
cout << "Month:";
cin>>month;
} while (1 > month || month > 12);

do {
cout << "day:";
cin>>day;
} while (1 > day || day > 31);
localDate.setDate(day, month, year);
}

/***************************************************/
/* Get a date from a user and store as an event */
/***************************************************/
void Calender::CreateEvent() {
Event theEvent;

int year, month, day;
cout << "Input Year:";
cin >> year;

cout << "Input Month:";
cin >> month;

cout << "Input day:";
cin >> day;

theEvent.date.setDate(year, month, day);

string desc;
cout << "Input description: ";
cin >> theEvent.desc;

event.push_back(theEvent);
}

void Calender::ListEvents() {
for (int i = 0; i < event.size(); ++i) {
cout << setw(4) << i + 1 << " " << event[i].ToString() << endl;
}
}

/***************************************************************/
/* Delete and event corresponding to the user selected index */

/***************************************************************/
void Calender::DeleteEvent() {
int id;
cout << "Input event ID: ";
cin >> id;

if (id < event.size() + 1) {
event.erase(event.begin() + id - 1);
} else {
cerr << "Invalid event ID" << endl;
}
}

/*****************************************************/
/* Create and event file and store all the event */
/*****************************************************/
void Calender::Save() {
//string filename = ;
ofstream file;
file.open("db.event", ios::app);

for (int i = 0; i < event.size(); ++i) {
file << event[i].date.getYear()
<< event[i].date.getMonth()
<< event[i].date.getDay()
<< event[i].desc << endl;
}

file.close();

cout << "Save to file success." << endl;
}


/**********************************************/
/* Load all event to the event file */
/*********************************************/

void Calender::Load() {
event.clear();

ifstream file;
file.open("db.event", ios::app);
file.seekg(0, ios::end); // put the "cursor" at the end of the file
int length = file.tellg(); // find the position of the cursor

if (!file.is_open()) {
cerr << "Unable to open the file: " << endl;
cerr << "Abort loading event." << endl;
return;
}

while (true) {
Event theEvent;

int year, month, day;
file >> year >> month>> day;

if (file.eof())
break;

theEvent.date.setDate(year, month, day);

string desc;
file >> theEvent.desc;

event.push_back(theEvent);
}


file.close();
cout << "Load from file success." << endl;
if (length == 0) {
cout << "The are no event currently stored\n";
}
}
