/**
 * @brief Header Datei für das Programm.
 * 
 */
struct Date{
    int day;
    int month;
    int year;
};
int is_leapyear(int year);
int get_days_for_month(struct Date);
int exists_date(struct Date);
int day_of_the_year(struct Date);
struct Date input_date();
void getWeekday(struct Date);
int getWeekdayNumber(int day, int month, int year);
int has53Weeks(int year);
void getCalendarWeek(struct Date);