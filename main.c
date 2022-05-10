#include <stdio.h>
#include "meinecoolenfunktionen.h"

/**
 * @brief Main-Methode. Ruft eine Methode zur Datumseinlesung 
 * auf und gibt den Tag des Jahres und die Kalenderwoche des Datums aus.
 * 
 * @return int 
 */

int main(){
    while(1){
        struct Date date = input_date();
        
        if(exists_date(date)){
            printf("-----------------------------------\n");
            printf("Das war der %i. Tag des Jahres. Es war ein ", day_of_the_year(date));
            getWeekday(date);
            printf(" und das Datum liegt in der ");
            getCalendarWeek(date);
            printf("-----------------------------------\n");
        }
    }
}