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
    return daysInMonths[month];
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
    for (int i = 0; i < month-1; i++){
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

int main(){
    int day = 0;
    int month = 0;
    int year = 0;
    input_date(&day, &month, &year);
    
    printf("Das war der %i. Tag des Jahres.\n", day_of_the_year(day, month, year));
    printf("-----------------------------------");
}