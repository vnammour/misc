/* Sat Jul 25 06:15:39 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#define rows 2
#define cols 13
static char daytab[rows][cols] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int day_of_year(int year, int month, int day) {
    if (month < 0 || month >= sizeof(daytab[0])/sizeof(daytab[0][0])) return -1;
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (int i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
void month_day(int year, int day_of_year, int *month, int *day) {
    *month = *day = 0;
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    int i = 1;
    for (; day_of_year > daytab[leap][i]; i++)
        day_of_year -= daytab[leap][i];
    *day = day_of_year, *month = i; 
}
typedef enum {Invalid, Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} Month;
char *tostring(Month m) {
    switch (m) {
        case Jan: return "Jan"; break;
        case Feb: return "Feb"; break;
        case Mar: return "Mar"; break;
        case Apr: return "Apr"; break;
        case May: return "May"; break;
        case Jun: return "Jun"; break;
        case Jul: return "Jul"; break;
        case Aug: return "Aug"; break;
        case Sep: return "Sep"; break;
        case Oct: return "Oct"; break;
        case Nov: return "Nov"; break;
        case Dec: return "Dec"; break;
        Default: return "Invalid"; break;
    }
}
int main(int argc, char *argv[])
{
    int year = 2026, dayofyear = 63;
    int month, day;
    month_day(year,dayofyear,&month,&day);
    printf("day %d of month %s\n", day, tostring(month));
    printf("day of year = %d\n", day_of_year(year,month,day));
}
