#include <stdio.h>

// int daysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

// void leapYearCheck(int year){
//     if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)){
//         daysInMonths[1] = 29;
//     }

// }

// int main()
// {
//     int year, month, day, sumOfDays;
//     year = month = day = sumOfDays = 0; 
    
//     do
//     {
//        printf("Bitte gueltiges Jahr eingeben: ");
//         scanf("%i", &year); 
//     } while (year < 0);
    
//     leapYearCheck(year);

//     do {
//         printf("Bitte gueltigen Monat eingeben: ");
//         scanf("%i", &month);
//     } while (month < 1 || month > 12);

//     do {
//         printf("Bitte gueltigen Tag eingeben, der in diesem Monat existierte: ");
//         scanf("%i", &day);
//     } while (day < 1 || day > daysInMonths[month-1]);

//     for (int i = 0; i < month-1; i++) {
//         sumOfDays += daysInMonths[i];
//     }

//     sumOfDays += day;
    
//     printf("Der %i. %i. %i war der %i. Tag des Jahres.", day, month, year, sumOfDays);
// }


int day = 25;
int month = 0;
int year = 0;

int is_leapyear(int year){
     if ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0)){
        return 1;
     } else {
         return 0;
     }
}

int get_days_for_month(int month, int year){
    int daysInMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leapyear(year)){
        daysInMonths[1] = 29;
    }
    return daysInMonths[month-1];
}

int exists_date(int day, int month, int year){
    int error = 0;
    printf("-----------------------------------\n");
    if(year < 1582 || year > 2400){
        printf("Bitte gueltiges Jahr eingeben,\n");
        error = 1;
    }
    if(month < 1 || month > 12) {
        printf("Bitte gueltigen Monat eingeben,\n");
        error = 1;
    }
    if(day < 1 || day > get_days_for_month(month, year)){
        printf("Bitte gueltigen Tag eingeben,\n");
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
    for (int i = 0; i < month; i++) {
        sumOfDays += get_days_for_month(i, year);
    }
    sumOfDays += day;
    printf("Tag %i", sumOfDays);
}

void input_date(int *tag, int *monat, int *jahr){
    do
    {
        printf("Bitte gueltigen Tag eingeben: ");
        scanf("%i", tag);
        printf("Bitte gueltigen Monat eingeben: ");
        scanf("%i", monat);
        printf("Bitte gueltiges Jahr eingeben: ");
        scanf("%i", jahr);
    } while (!exists_date(day, month, year));

    day_of_the_year(day, month, year); 
}

int main(){
    input_date(&day, &month, &year);
}