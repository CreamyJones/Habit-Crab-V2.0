//Time.h 
#pragma once
#pragma warning(disable : 4996) //disable deprecation message
#include <iostream> 
#include <Windows.h> //specifically needed for windows-specific time references
#include <ctime> 
//#include <time.h> //sub of ctime, needed for specific implementation
#include <stdlib.h> //needed for dynamic memory management of persistent time-keeping functions
#include <vector> 
#include <sstream>

using namespace std;

class alarm
{
public:

    tm alarmTime, currentTime, timeDiff;

    time_t now;

    alarm()
    {
        now = time(0);

        currentTime = *localtime(&now); //asterisk is a pointer dereference

        alarmTime = currentTime;

        alarmTime.tm_sec = 0; //tm_sec truncates returned time at seconds
    }

};

/*void getTime()
{

}*/















/*int User_clock()
{
    int User_hour, User_min, User_sec;
    string clock;
    time_t now = time(0);            // get current time
    tm* local = localtime(&now);     // convert to local time structure
    int hour = local->tm_hour;   // hour 0-23
    int min = local->tm_min;    // minute 0-59
    int sec = local->tm_sec;
    cout << "Time: " << hour << ":" << min << ":" << sec << endl;
    return 0;
}

int datechecker()

{

    time_t now = time(0);            // get current time

    tm* local = localtime(&now);     // convert to local time structure

    vector<string> days = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    vector<string> months = { "January","Februay", "March", "April", "May", "June","July",

        "August", "September", "October,", "November", "December" };

    class DateChecker {

    public:

        string weekday;
        string month;
        int year;
        int date;
    };




    DateChecker myObj;

    int weekday = local->tm_wday;
    int month = local->tm_mon;



    myObj.weekday = days[weekday];  // 0 = Sunday, 1 = Monday, ...

    myObj.date = local->tm_mday;  // 1–31

    myObj.month = months[month]; // 0–11 → convert to 1–12

    myObj.year = local->tm_year + 1900;



    cout << "Weekday: " << myObj.weekday << endl;

    cout << "Date   : " << myObj.date << endl;

    cout << "Month  : " << myObj.month << endl;

    cout << "Year   : " << myObj.year << endl;



    return 0;

}*/