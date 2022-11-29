#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <pthread.h>
#include <dirent.h>
#include "fnd.h"

#define MODE_STATIC_DISPLAY 1
#define MODE_TIME_DISPLAY 2
#define MODE_COUNT_DISPLAY 3
#define MODE_FND_OFF 4

int main(int argc, char *argv[])
{
    int mode = atoi(argv[1]);
    int number = atoi(argv[2]);

    if(mode == MODE_STATIC_DISPLAY)
    {
        printf("static display mode\n");
        fndDisp(number, 0);
    }
    else if(mode == MODE_TIME_DISPLAY)
    {
        printf("time display mode\n");
        struct tm *ptmcur;
        time_t tTime;
        if( -1 == time(&tTime))
        {
            return -1;
        }

        ptmcur = localtime(&tTime);

        number = ptmcur->tm_hour * 10000;
        number += ptmcur->tm_min * 100;
        number += ptmcur->tm_sec;

        fndDisp(number, 0b1010);
    }
    else if(mode == MODE_COUNT_DISPLAY)
    {
        printf("count mode\n");
        int count = 0;

        while(1)
        {
            if(!fndDisp(count, 0)) break;
            printf("%d->", count);
            count++;
            sleep(1);
            if(count > number) break;
        }
        printf("\n");
    }
   else if(mode == MODE_FND_OFF)
   {
     printf("display off\n");
     return 100;
    }

   return 0;
}
