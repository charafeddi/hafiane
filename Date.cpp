#include<iostream>
#include<string>
#include<ctime>
#include<sstream>
#include "Date.h"

using namespace std;

Date::Date() {

time_t t = time(0); //time(0); or time(NULL); returns the system time in seconds

struct tm *now = localtime(&t);
year = now->tm_year + 1900; 
month = now->tm_mon + 1;
day = now->tm_mday;
}

void Date::setDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

int Date::getDay() {
return day;
}

int Date::getMonth() {
return month;
}

int Date::getYear() {
return year;
}

const std::string Date::DayNames[7] = {"Sun","Mon","Tue","Wen","Thu","Fri","Sat"};
const std::string Date::MonthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
const int Date::MonthDays[12] = {31, 28, 31, 30, 31, 30,
								31, 31, 30, 31, 30, 31,	};
								
void Date::IncreaseMonth() {
	if (month < 12)
		++month;
	else {
		month = 1;
		++year;
	}
}
void Date::DecreaseMonth() {
		if (month > 1)
		--month;
		else {
		month = 12;
		--year;
		}
	}
string Date::ToString() const {
	stringstream output;
	output << year << "-" << month << "-" << day;
	return output.str();
}
