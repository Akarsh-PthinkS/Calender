#include "calenderdisplay.h"

CalenderDisplay calender;
void navigate()
{
    int input{};
    CalenderDisplay calender;
    calender.displayCalender();

    do
    {
        std::cout<<"Enter 1 >> Next Month  ||  ";
        std::cout<<"Enter 2 >> Previous Month  ||  ";
        std::cout<<"Enter 3 >> Present Month  ||  ";
        std::cout<<"Enter 4 >> Exit  :  ";
        std::cin>>input;
        switch(input)
        {
        case 1:calender.displayNextMonth();
            break;
        case 2:calender.displayPreviousMonth();
            break;
        case 3:calender.displayCalender();
            break;
        default:
            std::cout<<"Please Enter the Correct Option\n";
        }
    }
    while(input != 4);
}
