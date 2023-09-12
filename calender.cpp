#include "calender.h"

Calender::Calender(){

    std::time_t currentTime = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&currentTime);
    char day[20];
    std::strftime(day, sizeof(day), "%A", std::localtime(&currentTime));
    std::string strDay;

    m_date = timeInfo->tm_mday;
    strDay = static_cast<std::string>(day);
    m_month =  timeInfo->tm_mon + 1;
    m_year =   timeInfo->tm_year + 1900;

    if(strDay == "Monday"){m_day = Week::monday;}
    if(strDay == "Tuesday"){m_day = Week::tuesday;}
    if(strDay == "Wednesday"){m_day = Week::wednesday;}
    if(strDay == "Thursday"){m_day = Week::thursday;}
    if(strDay == "Friday"){m_day = Week::friday;}
    if(strDay == "Saturday"){m_day = Week::saturday;}
    if(strDay == "Sunday"){m_day = Week::sunday;}
}

int Calender::date() const
{
    return m_date;
}

Calender::Week Calender::day() const
{
    return m_day;
}

int Calender::month() const
{
    return m_month;
}

int Calender::year() const
{
    return m_year;
}

