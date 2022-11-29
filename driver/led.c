#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include "led.h"

static unsigned int ledValue = 0; 
static int fd = 0;

int ledLibinit(void)
{
 fd = open("/dev/periled", O_WRONLY);
 ledValue = 0;
}

int ledOnOff(int ledNum, int onOff)
{
 int i = 1;
 i = i<<ledNum;
 ledValue = ledValue & (~i); 
 if(onOff != 0) ledValue |= i;
 write(fd, &ledValue, 4);
}

int ledStatus(void)
{
 return ledValue;
}

int ledLibExit(void)
{
 ledValue = 0;
 ledOnOff(0,0); 
 close(fd);
}
