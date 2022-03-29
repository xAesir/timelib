#include <stdio.h>

int leapYearCheck(int year){
    if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)){
        return 1;
    }
    return 0;
}

int main()
{
    int year, month, day, sumOfDays;
    year = month = day = sumOfDays = 0;

    int daysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    do
    {
       printf("Bitte gueltiges Jahr eingeben: ");
        scanf("%i", &year); 
    } while (year < 0);

    if (leapYearCheck(year))
    {
       daysInMonths[1] = 29;
    }
    
    do {
        printf("Bitte gueltigen Monat eingeben: ");
        scanf("%i", &month);
    } while (month < 1 || month > 12);

    do {
        printf("Bitte gueltigen Tag eingeben, der in diesem Monat existierte: ");
        scanf("%i", &day);
    } while (day < 1 || day > daysInMonths[month-1]);

    for (int i = 0; i < month-1; i++) {
        sumOfDays += daysInMonths[i];
    }

    sumOfDays += day;
    
    printf("Der %i. %i. %i war der %i. Tag des Jahres.", day, month, year, sumOfDays);
}