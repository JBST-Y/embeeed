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

int count = 0;

//////////////////////////////////////////////////////////////////////////////

void send_green1(void) {
	//   execlp("ssh", "ssh", "-l", "ecube", "192.168.x.x");
	//   execlp("./a.out", "./a.out", "green1",(char*)0);
}

void send_left_green1(void) {
	// execlp("ssh", "ssh", "-l", "ecube", "192.168.x.x");
	// execlp("./a.out", "./a.out", "left_green1", (char*)0);
}

void send_yellow1(void) {
	// execlp("ssh", "ssh", "-l", "ecube", "192.168.x.x");
	// execlp("./a.out", "./a.out", "yellow1", (char*)0);
}

void send_red1(void) {
	// execlp("ssh", "ssh", "-l", "ecube", "192.168.x.x");
	// execlp("./a.out", "./a.out", "red1", (char*)0);
}



void TRAFFIC_LIGHTS_1_10(void)
{
	switch (count) {
	case 0:   printf("green/red\n");      execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/0", (char*)0); send_green1();      break;        // 1신호 초록불   2신호 빨간불 10초
	case 10:  printf("yellow/red\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/1", (char*)0); send_yellow1();     break;        // 1신호 주황불   2신호 빨간불 3초 
	case 13:  printf("left_green/red\n"); execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/2", (char*)0); send_left_green1(); break;        // 1신호 좌화전불 2신호 빨간불 10초
	case 23:  printf("yellow/red\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/1", (char*)0); send_yellow1();     break;        // 1신호 주황불   2신호 빨간불  3초
	case 26:  printf("red/green\n");      execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/3", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 초록불 10초
	case 36:  printf("red/yellow\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/4", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 주황불 3초
	case 39:  printf("red/left_green\n"); execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/5", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 좌회전불 10초
	case 49:  printf("red/yellow\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/4", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 주황불 3초
	case 52:  count = 0; break;  // 반복
	}
}
void TRAFFIC_LIGHTS_1_15(void)
{
	switch (count) {
	case 0:   printf("green/red\n");      execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/0", (char*)0); send_green1();      break;        // 1신호 초록불   2신호 빨간불 15초
	case 15:  printf("yellow/red\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/1", (char*)0); send_yellow1();     break;        // 1신호 주황불   2신호 빨간불 3초 
	case 18:  printf("left_green/red\n"); execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/2", (char*)0); send_left_green1(); break;        // 1신호 좌화전불 2신호 빨간불 10초
	case 28:  printf("yellow/red\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/1", (char*)0); send_yellow1();     break;        // 1신호 주황불   2신호 빨간불  3초
	case 31:  printf("red/green\n");      execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/3", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 초록불 10초
	case 41:  printf("red/yellow\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/4", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 주황불 3초
	case 44:  printf("red/left_green\n"); execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/5", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 좌회전불 10초
	case 54:  printf("red/yellow\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/4", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 주황불 3초
	case 57:  count = 0; break;  // 반복
	}
}

void TRAFFIC_LIGHTS_1_20(void)
{
	switch (count) {
	case 0:   printf("green/red\n");      execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/0", (char*)0); send_green1();      break;        // 1신호 초록불   2신호 빨간불 20초
	case 20:  printf("yellow/red\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/1", (char*)0); send_yellow1();     break;        // 1신호 주황불   2신호 빨간불 3초 
	case 23:  printf("left_green/red\n"); execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/2", (char*)0); send_left_green1(); break;        // 1신호 좌화전불 2신호 빨간불 10초
	case 33:  printf("yellow/red\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/1", (char*)0); send_yellow1();     break;        // 1신호 주황불   2신호 빨간불  3초
	case 36:  printf("red/green\n");      execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/3", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 초록불 10초
	case 46:  printf("red/yellow\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/4", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 주황불 3초
	case 49:  printf("red/left_green\n"); execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/5", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 좌회전불 10초
	case 59:  printf("red/yellow\n");     execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/4", (char*)0); send_red1();        break;        // 1신호 빨간불   2신호 주황불 3초
	case 62:  count = 0; break;  // 반복
	}
}



void LED_3_1(void)
{
	/*led_1_orange = 0;
	led_1_white = 1;
	led_2_orange = 0;
	led_2_white = 1;
	led_3_orange = 1;
	led_3_white = 0;*/
	printf("3:1 led\n");
	execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/6", (char*)0);

}

void LED_2_2(void)
{
	/*led_1_orange = 0;
	led_1_white = 1;
	led_2_orange = 1;
	led_2_white = 0;
	led_3_orange = 0;
	led_3_white = 1;*/
	printf("2:2 led\n");
	execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/7", (char*)0);

}

void LED_1_3(void)
{
	/*led_1_orange = 1;
	led_1_white = 0;
	led_2_orange = 0;
	led_2_white = 1;
	led_3_orange = 0;
	led_3_white = 1;*/
	printf("1:3 led\n");
	execl("/usr/bin/curl", "-s", "192.168.6.20/gpio/8", (char*)0);
}

int count_delay(void)
{
	count++;
	sleep(1);
}


//-------------------------------------------------------------------
int main(void)
{
	BUTTON_MSG_T messageRxData;
	int Msgid = msgget(MESSAGE_ID, IPC_CREAT | 0666);
	int return_value = 0;
	while (1)
	{
		return_value = msgrcv(Msgid, &messageRxData, sizeof(int) * 2, 0,
			IPC_NOWAIT);
		if (return_value == -1) break;
	}
    buttonInit();

	while (1)
	{
		return_value = msgrcv(Msgid, &messageRxData, sizeof(int) * 2, 0, 0);
		if (messageRxData.pressed)
		{
			printf("EV_KEY(");
			switch (messageRxData.keyInput)                                                                                         // auto_car 키트에 보내주기, 사거리 led에 보내주기
			{
			case KEY_HOME:       printf("1.사거리: 차량 수 4)\r\n");  TRAFFIC_LIGHTS_1_10(); break;   //차량신호등1 :직진 초록불 10초-노3-좌초록10-노3-빨26-<  (총 26초 + 차량신호등2 빨간불26인 52초)
			case KEY_BACK:       printf("2.사거리: 차량 수 6)\r\n");  TRAFFIC_LIGHTS_1_15(); break;   //차량신호등1 :직진 초록불 15초-노3-좌초록10-노3-빨26-<  (총 31초 + 차량신호등2 빨간불26인 57초)
			case KEY_SEARCH:     printf("3.사거리: 차량 수 8)\r\n");  TRAFFIC_LIGHTS_1_20(); break;   //차량신호등1 :직진 초록불 20초-노3-좌초록10-노3-빨26-<  (총 36초 + 차량신호등2 빨간불26인 62초)
			case KEY_MENU:       printf("4.차선변경: 오른쪽 차량 수 6/ 왼쪽 차량 수 2)\r\n");  LED_3_1(); break;                        //led 3:1
			case KEY_VOLUMEUP:   printf("5.차선변경: 오른쪽 차량 수 4/ 왼쪽 차량 수 4)\r\n");  LED_2_2(); break;                        //led 2:2
			case KEY_VOLUMEDOWN: printf("6.차선변경: 오른쪽 차량 수 2/ 왼쪽 차량 수 6)\r\n");  LED_1_3(); break;                        //led 1:3
			}
			
		}
		else
		{
			printf("release\r\n");
		}
		count_delay();
	}

	buttonExit();

	return 0;

}
