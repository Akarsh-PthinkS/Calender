#include "calenderdisplay.h"

CalenderDisplay::CalenderDisplay()
{
    m_calender =  new Calender{};
    m_currentDate = m_calender->date();
    m_month = m_calender->month();
    m_day = m_calender->day();
    m_year = m_calender->year();
}

CalenderDisplay::~CalenderDisplay()
{
    delete m_calender;
}

void CalenderDisplay::displayCalender()
{
    m_staticCurrentMonth = m_month;
    m_staticCurrentYear = m_year;
    m_lastDate = getLastDate(m_month);
    m_firstDate = getFirstDate(m_currentDate,m_day);
    m_staticCurrentDate = m_firstDate;
    m_nextFirstDate = m_firstDate;
    m_previousFirstDate = m_firstDate;
    int tempFirstDate = m_firstDate;

    std::cout<<std::endl;
    std::cout<<m_staticCurrentYear<<" - ";
    printMonth(m_staticCurrentMonth);
    std::cout<<"Sun\tMon\tTue\tWed\tThu\tFri\tSat"<<std::endl;
    for(int i = 1; i <= m_lastDate; )
    {
        for(int j = 0; j < 7 && i <= m_lastDate; ++j)
        {
            if(tempFirstDate>1)
            {
                std::cout<<"\t";
                --tempFirstDate;
            }
            else{
                std::cout<<i;
                if(m_currentDate == i){std::cout<<'x';}
                std::cout<<"\t";
                ++i;
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}

void CalenderDisplay::displayPreviousMonth()
{

    if(m_staticCurrentMonth == 1 || m_staticCurrentMonth == 0)
    {
        --m_staticCurrentYear;
        m_staticCurrentMonth = 12;
        m_lastDate = getLastDate(m_staticCurrentMonth);
    }
    else{m_lastDate = getLastDate(--m_staticCurrentMonth);}

    m_staticCurrentDate = m_staticCurrentDate - (m_lastDate%7) > 0? m_staticCurrentDate - (m_lastDate%7): 7 - abs(m_staticCurrentDate - m_lastDate%7);
    int tempFirstDate = m_staticCurrentDate;

    std::cout<<std::endl;
    std::cout<<m_staticCurrentYear<<" - ";
    printMonth(m_staticCurrentMonth);
    std::cout<<"Sun\tMon\tTue\tWed\tThu\tFri\tSat"<<std::endl;
    for(int i = 1; i <= m_lastDate;)
    {
        for(int j = 0; j < 7 && i <= m_lastDate; ++j)
        {
            if(tempFirstDate>1)
            {
                std::cout<<"\t";
                --tempFirstDate;
            }
            else{
                std::cout<<i;
                if(m_currentDate == i && m_staticCurrentMonth == m_month){std::cout<<'x';}
                std::cout<<"\t";
                ++i;
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}

void CalenderDisplay::displayNextMonth()
{
    m_nextFirstDate = m_nextFirstDate + (m_lastDate%7);
    m_staticCurrentDate = (m_staticCurrentDate + m_lastDate%7) > 7? (m_staticCurrentDate + m_lastDate%7)%7:(m_staticCurrentDate + m_lastDate%7);
    int tempFirstDate = m_staticCurrentDate;
    m_lastDate = getLastDate(++m_staticCurrentMonth);

    std::cout<<std::endl;
    std::cout<<m_staticCurrentYear<<" - ";
    printMonth(m_staticCurrentMonth);
    if(m_staticCurrentMonth == 12)
    {
        ++m_staticCurrentYear;
        m_staticCurrentMonth = 0;
    }
    std::cout<<"Sun\tMon\tTue\tWed\tThu\tFri\tSat"<<std::endl;
    for(int i = 1; i <= m_lastDate; )
    {
        for(int j = 0; j < 7 && i <= m_lastDate; ++j)
        {
            if(tempFirstDate>1)
            {
                std::cout<<"\t";
                --tempFirstDate;
            }
            else{
                std::cout<<i;
                if(m_currentDate == i && m_staticCurrentMonth == m_month){std::cout<<'x';}
                std::cout<<"\t";
                ++i;
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}
int CalenderDisplay::getLastDate(int month)
{
    if(month<=7)
    {
        return month % 2 == 1 ? 31 : (month == 2 ? (isLeapYear()?29:28) : 30);
    }
    else {
        return month % 2 == 1 ? 30 : 31;
    }
}

int CalenderDisplay::getFirstDate(int currentDate, Calender::Week day)
{
    int reducedDate = currentDate%7;
    int firstDate = static_cast<int>(day);

    while(reducedDate>1)
    {
        if(firstDate == 0)
        {
            firstDate = 7;
        }
        --firstDate;
        --reducedDate;
    }
    return firstDate;
}

void CalenderDisplay::printMonth(int month)
{
    switch(month)
    {
    case 1: std::cout<<"January\n"; break;
    case 2: std::cout<<"February\n"; break;
    case 3: std::cout<<"March\n"; break;
    case 4: std::cout<<"April\n"; break;
    case 5: std::cout<<"May\n"; break;
    case 6: std::cout<<"June\n"; break;
    case 7: std::cout<<"July\n"; break;
    case 8: std::cout<<"August\n"; break;
    case 9: std::cout<<"September\n"; break;
    case 10: std::cout<<"October\n"; break;
    case 11: std::cout<<"November\n"; break;
    case 12: std::cout<<"December\n"; break;
    }
}

bool CalenderDisplay::isLeapYear()
{
    if(m_staticCurrentYear % 4 == 0)
    {
        if(m_staticCurrentYear % 100 == 0)
        {
            if(m_staticCurrentYear % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
