#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define p_dd 31
// #define p_mm 1
// #define p_yy 2023

int p_dd, p_mm, p_yy;

void setTimeP()
{
    time_t t;
    time(&t);
    struct tm *t_local;
    t_local = localtime(&t);
    p_yy = t_local->tm_year + 1900;
    p_mm = t_local->tm_mon + 1;
    p_dd = t_local->tm_mday;
    // printf("%d,%d,%d", p_dd, p_mm, p_yy);
}

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int checkLeapYear(int);
// int uptoNextYear(int dd, int mm, int yy, int n_dd = p_dd, int n_mm = p_mm, int n_yy = p_yy);
int checkLeapYear(int i)
{
    if ((i % 100 == 0 && i % 400 == 0 && i != 0) || (i % 100 != 0 && i % 4 == 0))
        return 1;
    else
        return 0;
}

int uptoNextYear(int *from_d, int *upto_d)
{
    int dd = from_d[0], mm = from_d[1], yy = from_d[2];
    int n_dd = p_dd, n_mm = p_mm, n_yy = p_yy;
    int curDays = 0, m = 1;
    if (upto_d)
    {
        m = mm;
        n_dd = upto_d[0];
        n_mm = upto_d[1];
        n_yy = upto_d[2];
    }
    // terminate program for these four invalid cases;
    if (dd > 29 && mm == 2)
    {
        printf("February cannot have more then 29 day\'s\n");
        exit(1);
    }
    else if (dd == 29 && mm == 2 && checkLeapYear(yy) == 0)
    {
        printf("%d is not a leap year.\n", yy);
        exit(1);
    }
    else if (mm > 12)
    {
        printf("Month cannot be greater then 12\n");
        exit(1);
    }
    else if (dd > 31)
    {
        printf("Date cannot be greater then 31\n");
        exit(1);
    }

    if (n_yy == p_yy && upto_d != NULL) // upto_d , to avoid 365+ for same year
    {
        return 0;
    }
    else if (n_yy == p_yy)
    {
        goto currentYear;
    }

    curDays = month[m] - dd;
    m++;

    if (m == 2 && m <= n_mm) // dd <= 28
    {
        curDays += 28;
        m++;
    }
    if (m == 3 && m <= n_mm) // dd <= 31
    {
        curDays += 31;
        m++;
    }
    if (m == 4 && m <= n_mm) // dd <= 30
    {
        curDays += 30;
        m++;
    }
    if (m == 5 && m <= n_mm) // dd <= 31
    {
        curDays += 31;
        m++;
    }
    if (m == 6 && m <= n_mm) // dd <= 30
    {
        curDays += 30;
        m++;
    }
    if (m == 7 && m <= n_mm) // dd <= 31
    {
        curDays += 31;
        m++;
    }
    if (m == 8 && m <= n_mm) // dd <= 31
    {
        curDays += 31;
        m++;
    }
    if (m == 9 && m <= n_mm) // dd <= 30
    {
        curDays += 30;
        m++;
    }
    if (m == 10 && m <= n_mm) // dd <= 31
    {
        curDays += 31;
        m++;
    }
    if (m == 11 && m <= n_mm) // dd <= 30
    {
        curDays += 30;
        m++;
    }
    if (m == 12 && m <= n_mm) // dd <= 31
    {
        curDays += 31;
    }

    return curDays;

currentYear:
    if (n_mm == 1 && n_dd <= 31)
    {
        curDays = curDays + n_dd;
    }
    else if (n_mm == 2 && n_dd <= 28)
    {
        curDays = 31;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 3 && n_dd <= 31)
    {
        curDays = 59; // sum of jan& feb
        curDays = curDays + n_dd;
    }
    else if (n_mm == 4 && n_dd <= 30)
    {
        curDays = 90; // sum of jan& feb& mar
        curDays = curDays + n_dd;
    }
    else if (n_mm == 5 && n_dd <= 31)
    {
        curDays = 120;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 6 && n_dd <= 30)
    {
        curDays = 151;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 7 && n_dd <= 31)
    {
        curDays = 181;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 8 && n_dd <= 31)
    {
        curDays = 212;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 9 && n_dd <= 30)
    {
        curDays = 243;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 10 && n_dd <= 31)
    {
        curDays = 273;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 11 && n_dd <= 30)
    {
        curDays = 304;
        curDays = curDays + n_dd;
    }
    else if (n_mm == 12 && n_dd <= 31)
    {
        curDays = 334;
        curDays = curDays + n_dd;
    }
    else
        printf("Error in cyd!");

    return curDays;
}

int main()
{
    int dd, mm, yy;
    printf("\nEnter DOB in dd mm yy format:\t");
    scanf("%d%d%d", &dd, &mm, &yy);

    setTimeP(); // set present today's date

    int leapYear = 0, counter = yy;
    while (counter++ <= p_yy - 1)
    {
        if (checkLeapYear(counter) == 1)
            leapYear += 1;
    }

    // days upto next year, from birth year
    int nyd = 0;

    // days in between years, from birth next to current prev..
    long byd = 0;

    // days in current running year as (cyd)
    int cyd = 0;

    // total final days tillnow as (tfd)
    long tfd;

    if (p_yy - 1 - yy > 0)
        byd = ((p_yy - 1 - yy) * 365) + leapYear;

    int from_d[] = {dd, mm, yy}, upto_d[] = {31, 12, yy};
    nyd = uptoNextYear(from_d, upto_d);

    int cfrom_d[] = {1, 1, p_yy};
    cyd = uptoNextYear(cfrom_d, NULL); // null means upto present

    // if birth and current year is leap
    if (checkLeapYear(yy) == 1 && mm > 2)
    {
        nyd += 1;
    }
    else if (dd == 29 && mm == 2)
    {
        nyd += 1;
    }

    if (checkLeapYear(p_yy) == 1 && mm > 2)
    {
        cyd += 1;
    }
    else if (p_dd == 29 && mm == 2)
    {
        cyd += 1;
    }

    tfd = cyd + nyd + byd;
    printf("\nTotal days from %d/%d/%d to %d/%d/%d is : %d \n\n", dd, mm, yy, p_dd, p_mm, p_yy, tfd);
    return 0;
}
