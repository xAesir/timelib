#include <stdio.h>
#include "meinecoolenfunktionen.h"

int is_leapyear(int year){
     if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)){
        return 1;
     } else {
         return 0;
     }
}

int get_days_for_month(int month, int year){
    int daysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leapyear(year)){
        daysInMonths[2] = 29;
    }
    return daysInMonths[month];
}

int exists_date(int day, int month, int year){
    int error = 0;

    if(day < 1 || day > get_days_for_month(month, year)){
        printf("Bitte gueltigen Tag eingeben,\n");
        error = 1;
    }

    if(month < 1 || month > 12) {
        printf("Bitte gueltigen Monat eingeben,\n");
        error = 1;
    }

    if(year < 1582 || year > 2400){
        printf("Bitte gueltiges Jahr eingeben,\n");
        error = 1;
    }
    
    if(error){
        printf("Neue Datumseingabe erforderlich\n");
        printf("-----------------------------------\n");
        return 0;
    } else {
        return 1;
    }
}

int day_of_the_year(int day, int month, int year){
    int sumOfDays = 0;
    for (int i = 1; i < month; i++){
        sumOfDays += get_days_for_month(i, year);
    }
    sumOfDays += day;
    return sumOfDays;
}

void input_date(int *day, int *month, int *year){
    do
    {
        printf("Bitte gueltigen Tag eingeben: ");
        scanf("%i", day);
        printf("Bitte gueltigen Monat eingeben: ");
        scanf("%i", month);
        printf("Bitte gueltiges Jahr eingeben: ");
        scanf("%i", year);
    } while (!exists_date(*day, *month, *year)); 
}

//https://stackoverflow.com/a/21235587
void getWeekday(int day, int month, int year){
    int d = day;
    int m = month;
    int y = year;

    int result = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7; 

    switch (result){
        
        case 1:
        printf("Montag");
        break;

        case 2:
        printf("Dienstag");
        break;

        case 3:
        printf("Mittwoch");
        break;

        case 4:
        printf("Donnerstag");
        break;

        case 5:
        printf("Freitag");
        break;

        case 6:
        printf("Samstag");
        break;

        default:
        printf("Sonntag");
    }
}

int getWeekdayNumber(int day, int month, int year){
    int d = day;
    int m = month;
    int y = year;

    int result = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;

    if(result == 0){
        return 7;
    } else {
        return result;
    }
}

int has53Weeks(int year){
    if(is_leapyear(year)){
        if((getWeekdayNumber(1, 1, year) == 3 && getWeekdayNumber(31, 12, year) == 4) || (getWeekdayNumber(1, 1, year) == 4 && getWeekdayNumber(31, 12, year) == 5)){
            return 1;
        }
    } else{
        if(getWeekdayNumber(1, 1, year) == 4 || getWeekdayNumber(31, 12, year) == 4){
            return 1;
        }
    }
    return 0;
}

void getCalendarWeek(int day, int month, int year){
    int weekNumber = day_of_the_year(day, month, year) - getWeekdayNumber(day, month, year);
    weekNumber += 10;
    weekNumber /= 7;
    if(weekNumber == 0){
        if(has53Weeks(year-1)){
            printf("53. Kalenderwoche des letzten Jahres.\n");
        } else{
            printf("52. Kalenderwoche des letzten Jahres.\n");
        }
    } else if(weekNumber == 53){
        if(has53Weeks(year)){
            printf("53. Kalenderwoche des aktuellen Jahres.\n");
        } else{
            printf("1. Kalenderwoche des naechsten Jahres.\n");
        }
    } else {
        printf("%i. Kalenderwoche des aktuellen Jahres.\n", weekNumber);
    }
}

//gcc -o test.exe main.c meinecoolenfunktionen.c