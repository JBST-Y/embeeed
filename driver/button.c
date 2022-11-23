#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <linux/input.h>
#include <unistd.h> // for open/close  
#include <fcntl.h> // for O_RDWR  
#include <sys/ioctl.h> // for ioctl  
#include <sys/msg.h>
#include <pthread.h>  
#include "button.h"

#define INPUT_DEVICE_LIST "/dev/input/event" 
#define PROBE_FILE "/proc/bus/input/devices" 
#define HAVE_TO_FIND_1 "N: Name=\"ecube-button\"\n" 
#define HAVE_TO_FIND_2 "H: Handlers=kbd event"

pthread_t buttonTh_id;
pthread_mutex_t lock;

static int fd = 0;
static int msgID = 0;
void *buttonThFunc(void *arg);

int buttonInit(void)
{
 char buttonPath[200] = {0,};
 if (probeButtonPath(buttonPath) == 0)
  return 0;
 fd=open (buttonPath, O_RDONLY);
 msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);  
 pthread_create(&buttonTh_id, NULL, buttonThFunc, NULL); 
 return 1;
}

void *buttonThFunc(void *arg)
{
 BUTTON_MSG_T Data;
 int readSize, inputIndex;
 struct input_event B;

 while(1)
 {
  readSize = read(fd, &B, sizeof(B));
  Data.keyInput = B.code;
  Data.pressed = B. value;

  msgsnd(msgID, &Data, sizeof(Data)-4, 0);
  }
}

int buttonExit(void)
{
 pthread_join(buttonTh_id, NULL);
 close(fd);
}

