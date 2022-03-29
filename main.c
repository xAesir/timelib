#include <stdio.h>
#include <stdlib.h>

int leapYearCheck(int year){
    if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)){
        return 1;
    }
    return 0;
}

int day_of_the_year(int day, int month, int year)
{

    int sumOfDays = 0;

    int daysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (leapYearCheck(year))
    {
       daysInMonths[1] = 29;
    }

    for (int i = 0; i < month-1; i++) {
        sumOfDays += daysInMonths[i];
    }

    sumOfDays += day;
    
    return sumOfDays;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
