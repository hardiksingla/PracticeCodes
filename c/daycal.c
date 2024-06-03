#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    
    
    int date, month, year, yearc, yearl, monthc, sum, daynum,i=0;
    while(i<2){
    printf("date: ");
    scanf("%d", &date);
    printf("month");
    scanf("%d", &month);
    printf("year");
    scanf("%d", &year);
    if (year >= 1900 && year < 1999)
    {
        yearc = 0;
    }
    else if (year >= 2000 && year < 2100)
    {
        yearc = 6;
    }
    if (month == 1 || month == 10)
    {
        monthc = 0;
    }
    else if (month == 2 || month == 3 || month == 11)
    {
        monthc = 3;
    }
    else if (month == 4 || month == 7)
    {
        monthc = 6;
    }
    else if (month == 5 || month == 8)
    {
        monthc = 1;
    }
    else if (month == 6)
    {
        monthc = 4;
    }
    else if (month == 12 || month == 9)
    {
        monthc = 5;
    }
    yearl = year % 100;
    sum = yearl + yearl / 4 + date + yearc + monthc;
    daynum = sum % 7;
    if (daynum == 0)
    {
        printf("sunday\n");
    }
    if (daynum == 1)
    {
        printf("monday\n");
    }
    if (daynum == 2)
    {
        printf("tuesday\n");
    }
    if (daynum == 3)
    {
        printf("wednesday\n");
    }
    if (daynum == 4)
    {
        printf("thurday\n");
    }
    if (daynum == 5)
    {
        printf("friday\n");
    }
    if (daynum == 6)
    {
        printf("saturday\n");
    }
    i++;
    }
    return 0;
}