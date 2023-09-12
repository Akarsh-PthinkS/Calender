#ifndef CALENDER_H
#define CALENDER_H
#include<iostream>
#include <ctime>


class Calender
{
public:

    enum Week{
        sunday = 1,
        monday = 2,
        tuesday = 3,
        wednesday = 4,
        thursday = 5,
        friday = 6,
        saturday = 7,
    };

    Calender();

    int date() const;
    Week day() const;
    int month() const;
    int year() const;

private:
    int m_date{};
    Week m_day{};
    int m_month{};
    int m_year{};
};

#endif // CALENDER_H
