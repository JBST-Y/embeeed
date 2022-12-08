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

#include "myMessage.h"

int main(int argc, char *argv[])
{
 printf("JBST\r\n");
 structMyMsg messageTxData;
 int msgQueue = msgget((key_t)MY_MESSAGE_ID, IPC_CREAT|0666);

 while(1)
 {
  snprintf(messageTxData.piggyBack, sizeof(messageTxData.piggyBack)-1, argv[1]);
  messageTxData.messageType = 1;
  msgsnd(msgQueue, &messageTxData, sizeof(messageTxData.piggyBack), 0);
 }
}

