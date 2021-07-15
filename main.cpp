/*
The main Program
*/
#include<iostream>
#include <cstdlib>
#include <fstream>
#include "Calender.h"

using namespace std;

int main() {
system("Color 0A");
Calender calender;
//Create event data file if it doesn't exist
ifstream ifs("db.event");
if (!ifs.is_open()) {
ofstream outfile("db.event"); // create file
}
calender.Draw(); // print calendar
calender.Run(); //Menu options

return 0;
}
