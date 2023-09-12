#ifndef CALENDERDISPLAY_H
#define CALENDERDISPLAY_H
#include <string>
#include<iostream>
#include"calender.h"

class CalenderDisplay
{
public:
    CalenderDisplay();
    ~CalenderDisplay();

    void displayCalender();
    void displayPreviousMonth();
    void displayNextMonth();
    int getLastDate(int month);
    int getFirstDate(int currentDate, Calender::Week day);
    void printMonth(int month);
    bool isLeapYear();

private:
    Calender* m_calender;
    int m_lastDate{};
    int m_firstDate{};
    int m_currentDate{};
    int m_month{};
    int m_year{};
    Calender::Week m_day{};

    int m_staticCurrentMonth;
    int m_staticCurrentDate;
    int m_staticCurrentYear;
    int m_nextFirstDate;
    int m_previousFirstDate;

};

#endif // CALENDERDISPLAY_H
