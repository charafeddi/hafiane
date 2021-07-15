#include<iostream>
#include<string>
#ifndef DATE_H
#define DATE_H

using namespace std;

class Date{
	private:
		int year, month, day;
	public:
		static const std::string DayNames[7]; //all object have weekdays
		static const std::string MonthNames[12]; // Month Names
		static const int MonthDays[12]; // Days
		Date();//constractor
		//getter & setter
		int getYear();//get the current year
		int getDay();//get the current month
		int getMonth();//get the current day
		void setDate(int,int,int); //setting the date 
		void IncreaseMonth();//increassing the month going to the next month 
		void DecreaseMonth();// decreasing the month returning to the previous month 
		string ToString() const;
};

#endif
