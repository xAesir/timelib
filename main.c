#include <stdio.h>
#include "meinecoolenfunktionen.h"

int main(){
    int day = 0;
    int month = 0;
    int year = 0;
    input_date(&day, &month, &year);
    
    if(exists_date(day, month, year)){
        printf("Das war der %i. Tag des Jahres. Es war ein ", day_of_the_year(day, month, year));
        getWeekday(&day, &month, &year);
        printf(" und die Woche war die %i.\n", getCalendarWeek(&day, &month, &year));
        printf("-----------------------------------\n");
    }
}