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
#include "textlcd.h"

int main(int argc, char *argv[])
{
    int lineFlag = 0;
    lineFlag = textlcdwrite(argv[1], argv[2]);
    if(lineFlag == -1)
    {
        printf("failed!\n");
        return 1;
    }

    

    return 0;
}

