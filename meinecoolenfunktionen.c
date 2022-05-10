#include <stdio.h>
#include "meinecoolenfunktionen.h"

/**
 * @brief Wikipedia Algorithmus, der ausrechnet, ob ein Jahr ein Schaltjahr ist.
 * 
 * @param year Das Jahr, welches überprüft wird.
 * @return int 1 falls Schaltjahr, sonst 0
 */

int is_leapyear(int year){
     if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)){
        return 1;
     } else {
         return 0;
     }
}

/**
 * @brief Gibt die Tage zurück, die in einem Monat liegen
 * 
 * @param date Das Datum, dessen Monat überprüft wird
 * @return int Die Anzahl der Tage in einem Monat
 */

int get_days_for_month(struct Date date){
    int daysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leapyear(date.year)){
        daysInMonths[2] = 29;
    }
    return daysInMonths[date.month];
}

/**
 * @brief Prüft, ob ein übergebens Datum existiert. Vergleicht dabei,
 * ob der Tag des Datums nicht die maximale Tage des Monats überschreitet oder unter 1 ist,
 * ob der Monat zwischen 1 und 12 liegt und ob das Jahr zwischen 1582 und 2400 liegt
 * 
 * @param date 
 * @return int 
 */

int exists_date(struct Date date){
    int error = 0;

    if(date.day < 1 || date.day > get_days_for_month(date)){
        printf("Bitte gueltigen Tag eingeben,\n");
        error = 1;
    }

    if(date.month < 1 || date.month > 12) {
        printf("Bitte gueltigen Monat eingeben,\n");
        error = 1;
    }

    if(date.year < 1582 || date.year > 2400){
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

/**
 * @brief Iteriert über alle Monate, die vor dem Monat des übergebenen Datums liegen,
 * und addiert die Tage in diesen. Für jeden Monat wird ein neues Struct angelegt.
 * Schlussendlich wird der Tag des Datums addiert.
 * 
 * @param date 
 * @return int Platzierung des Tages im Jahr.
 */

int day_of_the_year(struct Date date){
    int sumOfDays = 0;
    for (int i = 1; i < date.month; i++){
        struct Date tempDate = date;
        tempDate.month = i;
        sumOfDays += get_days_for_month(tempDate);
    }
    sumOfDays += date.day;
    return sumOfDays;
}

/**
 * @brief Legt ein neues Date-Struct an, in welches das gewünschte Datum des Users gelesen wird,
 * und gibt dieses an die Main-Methode zurück, solange das gewünschte Datum existiert.
 * 
 * @return struct Date 
 */
struct Date input_date(){
    struct Date date;
    do
    {
        printf("Bitte gueltigen Tag eingeben: ");
        scanf("%i", &date.day);
        printf("Bitte gueltigen Monat eingeben: ");
        scanf("%i", &date.month);
        printf("Bitte gueltiges Jahr eingeben: ");
        scanf("%i", &date.year);
    } while (!exists_date(date));
    
    return date;
}

/**
 * @brief Algorithmus, welcher berechnet, welcher Tag der Woche der Tag des
 * User Datums ist und printet diesen.
 * https://stackoverflow.com/a/21235587
 */

void getWeekday(struct Date date){
    int d = date.day;
    int m = date.month;
    int y = date.year;

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

/**
 * @brief Algorithmus, welcher berechnet, welcher Tag der Woche der Tag
 * des User-Datums ist. 1 = Montag, 7 = Sonntag.
 * https://stackoverflow.com/a/21235587
 * 
 * @param day 
 * @param month 
 * @param year 
 * @return int 
 */

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

/**
 * @brief Prüft, ob das übergebene Jahr 53 Kalenderwochen hat. Dies ist der Fall,
 * sollte das Jahr mit einem Donnerstag beginnen oder enden.
 * 
 * @param year Das Jahr, für welches geguckt werden soll, ob es 53 Kalenderwochen hat.
 * @return int 1 falls Ja, sonst 0.
 */

int has53Weeks(int year){
    if(getWeekdayNumber(1, 1, year) == 4 || getWeekdayNumber(31, 12, year) == 4){
        return 1;
    }
    return 0;
}

/**
 * @brief Wikipedia-Algorithmus, welcher prüft, in welcher Kalenderwoche des Jahres das User-Datum liegt.
 * Sollte die Variable WeekNumber = 0 sein, so liegt das Datum in der letzten Kalenderwoche des Vorjahres.
 * Sollte die Variable WeekNumber = 53 sein, das aktuelle Jahr allerdings keine 53 Kalenderwochen hat, so
 * liegt das Datum in der ersten Kalenderwoche des nächsten Jahres.
 * 
 * https://en.wikipedia.org/wiki/ISO_week_date
 * 
 * @param date 
 */

void getCalendarWeek(struct Date date){
    int weekNumber = day_of_the_year(date) - getWeekdayNumber(date.day, date.month, date.year);
    weekNumber += 10;
    weekNumber /= 7;
    if(weekNumber == 0){
        if(has53Weeks(date.year-1)){
            printf("53. Kalenderwoche des letzten Jahres.\n");
        } else{
            printf("52. Kalenderwoche des letzten Jahres.\n");
        }
    } else if(weekNumber == 53){
        if(has53Weeks(date.year)){
            printf("53. Kalenderwoche des aktuellen Jahres.\n");
        } else{
            printf("1. Kalenderwoche des naechsten Jahres.\n");
        }
    } else {
        printf("%i. Kalenderwoche des aktuellen Jahres.\n", weekNumber);
    }
}