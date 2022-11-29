#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <dirent.h>
#include "buzzer.h"



int main(int argc, char *argv[])
{
    int freIndex;
    if(argc < 2 || findBuzzerSysPath())
    {
        printf("Error!\n");
        doHelp();
        return 1;
    }

    buzzerInit();

    freIndex = atoi(argv[1]);
    printf("freIndex :%d \n",freIndex);

    buzzerPlaySong(freIndex);
    buzzerStopSong();  
    buzzerExit();

 return 0;
}




