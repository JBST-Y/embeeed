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
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "textlcd.h"
#include "myMessage.h"

int main(void)  
{
	int stop = 0;
	int go1 = 0;
	int go2 = 0;
	int left = 0;                            // 보내줘야할 것(경우 4)

	int obstacle;                            // 받아오기 ??(차량 흰색 -> 흰색 인식 -> car_speed=0)
	int current_position;                    // 1: 일반도로  2: 어린이보호구역 (openCV로 확인 -> 받아오기)


	int green1, left_green1, yellow1, red1;  // 신호 인식...??

	int freIndex;
	char buffer[10] = "8";

	int lineFlag1 = 0;
	int lineFlag2 = 0;

	char str1[100] = "driving_position";
	char str2[100] = "general_road";
	char str3[100] = "child_zone";
	char str01[100] = "1";
	char str02[100] = "2";

	///////////////////
	structMyMsg messageRxData;
	int msgQueue = msgget((key_t)MY_MESSAGE_ID, IPC_CREAT|0666);
	///////////////////

	lineFlag1 = textlcdwrite(str01, str1);

	while (1) {                                 //curl - s "192.168.6.7/gpio/0-4"     0:stop  1:go1   2:go2   3:left

		int returnValue = 0;
		returnValue = msgrcv(msgQueue, &messageRxData, sizeof(messageRxData.piggyBack), 0, IPC_NOWAIT);
		printf("%s", messageRxData.piggyBack);  // <- 신호 인식 값

		if (current_position == 1) {
			lineFlag2 = textlcdwrite(str02, str2);

			stop = 0;
			go2 = 1;
			ledOnOff(255, 1);
			execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char *)0);


			if (messageRxData.piggyBack == "green1") {                    // 차량 신호를 차선과 가까울 때 인식
				stop = 0;
				go2 = 1;
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char *)0);
				ledOnOff(255, 1);
			}
			else if (messageRxData.piggyBack == "left_green1") {
				stop = 0;
				left = 1;
				ledOnOff(255, 1);
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/3"", (char *)0);
			}
			else if (messageRxData.piggyBack == "yellow1") {

				stop = 1;
				go2 = 0;
				ledOnOff(0, 0);
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
			}
			else if (messageRxData.piggyBack == "red1") {
				stop = 1;
				go2 = 0;
				ledOnOff(0, 0);
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
				buzzerInit();
				freIndex = atoi(buffer);
				buzzerPlaySong(freIndex);
				buzzerStopSong();
				buzzerExit();
			}
		}
		else if (current_position == 2) {
			lineFlag2 = textlcdwrite(str02, str3);

			stop = 0;
			go1 = 1;
			ledOnOff(15, 1);
			execlp("curl", "curl", "-s", ""192.168.6.7/gpio/1"", (char *)0);


			if (messageRxData.piggyBack == "green1") {
				stop = 0;
				go1 = 1;
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/1"", (char *)0);
				ledOnOff(15, 1);
			}
			else if (messageRxData.piggyBack == "left_green1") {
				stop = 0;
				left= 1;
				ledOnOff(15, 1);
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/3"", (char *)0);
			}
			else if (messageRxData.piggyBack == "yellow1") {
				stop = 1;
				go1 = 0;
				ledOnOff(0, 0);
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
			}
			else if (messageRxData.piggyBack == "red1" == 1) {
				stop = 1;
				go1 = 0;
				ledOnOff(0, 0);
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
				buzzerInit();
				freIndex = atoi(buffer);
				buzzerPlaySong(freIndex);
				buzzerStopSong();
				buzzerExit();
			}
		}
	}

	return 0;
}

