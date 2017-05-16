#include <stdio.h>

#include <time.h>



int main(void)

{

    time_t now_tm;

    struct tm *now;

    int sec, min, hour, year, yday;



    now_tm = time(NULL);

    now = localtime(&now_tm);


    sec  = now->tm_sec;
    min  = now->tm_min;
    hour = now->tm_hour;

    year = now->tm_year;
    yday = now->tm_yday;


    printf("%d/%d %d:%d:%d\n", yday, year, hour, min, sec);

}

