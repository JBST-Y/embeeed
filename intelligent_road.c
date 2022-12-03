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
#include "lcd.h"

int main(void)
{
	//신호 전달 (exec 사용)
	BUTTON_MSG_T messageRxData;
	int Msgid = msgget(MESSAGE_ID, IPC_CREAT | 0666);
	while (1)
	{
		int return_value = 0;
		return_value = msgrcv(Msgid, &messageRxData, sizeof(int) * 2, 0,
			IPC_NOWAIT);
		if (return_value == -1) break;
	}
	buttonInit();

	while (1)
	{
		int return_value = 0;
		return_value = msgrcv(Msgid, &messageRxData, sizeof(int) * 2, 0, 0);
		if (messageRxData.pressed)
		{
			printf("EV_KEY(");
			switch (messageRxData.keyInput)                                                                                         // auto_car 키트에 보내주기, 사거리 led에 보내주기
			{
			case KEY_VOLUMEUP:   printf("사거리: 차량 수 4\r\n"); TRAFFIC_LIGHTS_1_10(); break;   //차량신호등1 :직진 초록불 10초-노3-좌초록10-노3-빨26-<  (총 26초 + 차량신호등2 빨간불26인 52초)
			case KEY_HOME:       printf("사거리: 차량 수 6\r\n"); TRAFFIC_LIGHTS_1_15(); break;   //차량신호등1 :직진 초록불 15초-노3-좌초록10-노3-빨26-<  (총 31초 + 차량신호등2 빨간불26인 57초)
			case KEY_SEARCH:     printf("사거리: 차량 수 8\r\n"); TRAFFIC_LIGHTS_1_20(); break;   //차량신호등1 :직진 초록불 20초-노3-좌초록10-노3-빨26-<  (총 36초 + 차량신호등2 빨간불26인 62초)
			case KEY_BACK:       printf("차선변경: 오른쪽 차량 수 6/ 왼쪽 차량 수 2\r\n"); LED_3_1(); break;                        //led 3:1
			case KEY_MENU:       printf("차선변경: 오른쪽 차량 수 4/ 왼쪽 차량 수 4\r\n"); LED_2_2(); break;                        //led 2:2
			case KEY_VOLUMEDOWN: printf("차선변경: 오른쪽 차량 수 2/ 왼쪽 차량 수 6\r\n"); LED_1_3(); break;                        //led 1:3
			}
		}
		else
		{
			printf("release\r\n");
		}
	}

	return 0;

}

//exec(); // 차량키트
//exec(); // 사거리 신호등
//exec(); // 차선변경 도로
//헤더 파일에 밑의 함수 추가 필요

int TRAFFIC_LIGHTS_1_10(void) 
{
	int green1 = 0;
	int left_green1 = 0;
	int yellow1 = 0;
	int red1 = 0;

	int green2 = 0;
	int left_green2 = 0;
	int yellow2 = 0;
	int red2 = 1;

	int count = 0;

	while (1)
	{
		if (red2 == 1) {
			red1 = 0;
			return 0;
			green1 = 1;
			execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
			count++;
			sleep(1);
			if (count > 10) {
				count = 0;
				green1 = 0;
				yellow1 = 1;
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char*)0);
				count++;
				sleep(1);
				if (count > 3) {
					count = 0;
					yellow1 = 0;
					left_green1 = 1;
					execlp("curl", "curl", "-s", ""192.168.6.7/gpio/1"", (char*)0);
					count++;
					sleep(1);
					if (count > 10) {
						count = 0;
						left_green1 = 0;
						yellow1 = 1;
						execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char*)0);
						count++;
						sleep(1);
						if (count > 3) {
							count = 0;
							yellow1 = 0;
							red1 = 1;
							if (red1 == 1) {
								red2 = 0;
								green2 = 1;
								execlp("curl", "curl", "-s", ""192.168.6.7/gpio/3"", (char*)0);
								count++;
								sleep(1);
								if (count > 10) {
									count = 0;
									green2 = 0;
									yellow2 = 1;
									execlp("curl", "curl", "-s", ""192.168.6.7/gpio/5"", (char*)0);
									count++;
									sleep(1);
									if (count > 3) {
										count = 0;
										yellow2 = 0;
										left_green2 = 1;
										execlp("curl", "curl", "-s", ""192.168.6.7/gpio/4"", (char*)0);
										count++;
										sleep(1);
										if (count > 10) {
											count = 0;
											left_green2 = 0;
											yellow2 = 1;
											execlp("curl", "curl", "-s", ""192.168.6.7/gpio/5"", (char*)0);
											count++;
											sleep(1);
											if (count > 3) {
												count = 0;
												yellow2 = 0;
												red2 = 1;

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
}

int TRAFFIC_LIGHTS_1_15(void)
{
	int green1 = 0;
	int left_green1 = 0;
	int yellow1 = 0;
	int red1 = 0;

	int green2 = 0;
	int left_green2 = 0;
	int yellow2 = 0;
	int red2 = 1;

	int count = 0;

	while (1)
	{
		if (red2 == 1) {
			red1 = 0;
			return 0;
			green1 = 1;
			execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
			count++;
			sleep(1);
			if (count > 15) {
				count = 0;
				green1 = 0;
				yellow1 = 1;
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char*)0);
				count++;
				sleep(1);
				if (count > 3) {
					count = 0;
					yellow1 = 0;
					left_green1 = 1;
					execlp("curl", "curl", "-s", ""192.168.6.7/gpio/1"", (char*)0);
					count++;
					sleep(1);
					if (count > 10) {
						count = 0;
						left_green1 = 0;
						yellow1 = 1;
						execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char*)0);
						count++;
						sleep(1);
						if (count > 3) {
							count = 0;
							yellow1 = 0;
							red1 = 1;
							if (red1 == 1) {
								red2 = 0;
								green2 = 1;
								execlp("curl", "curl", "-s", ""192.168.6.7/gpio/3"", (char*)0);
								count++;
								sleep(1);
								if (count > 10) {
									count = 0;
									green2 = 0;
									yellow2 = 1;
									execlp("curl", "curl", "-s", ""192.168.6.7/gpio/5"", (char*)0);
									count++;
									sleep(1);
									if (count > 3) {
										count = 0;
										yellow2 = 0;
										left_green2 = 1;
										execlp("curl", "curl", "-s", ""192.168.6.7/gpio/4"", (char*)0);
										count++;
										sleep(1);
										if (count > 10) {
											count = 0;
											left_green2 = 0;
											yellow2 = 1;
											execlp("curl", "curl", "-s", ""192.168.6.7/gpio/5"", (char*)0);
											count++;
											sleep(1);
											if (count > 3) {
												count = 0;
												yellow2 = 0;
												red2 = 1;

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int TRAFFIC_LIGHTS_1_20(void)
{
	int green1 = 0;
	int left_green1 = 0;
	int yellow1 = 0;
	int red1 = 0;

	int green2 = 0;
	int left_green2 = 0;
	int yellow2 = 0;
	int red2 = 1;

	int count = 0;

	while (1)
	{
		if (red2 == 1) {
			red1 = 0;
			return 0;
			green1 = 1;
			execlp("curl", "curl", "-s", ""192.168.6.7/gpio/0"", (char*)0);
			count++;
			sleep(1);
			if (count > 20) {
				count = 0;
				green1 = 0;
				yellow1 = 1;
				execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char*)0);
				count++;
				sleep(1);
				if (count > 3) {
					count = 0;
					yellow1 = 0;
					left_green1 = 1;
					execlp("curl", "curl", "-s", ""192.168.6.7/gpio/1"", (char*)0);
					count++;
					sleep(1);
					if (count > 10) {
						count = 0;
						left_green1 = 0;
						yellow1 = 1;
						execlp("curl", "curl", "-s", ""192.168.6.7/gpio/2"", (char*)0);
						count++;
						sleep(1);
						if (count > 3) {
							count = 0;
							yellow1 = 0;
							red1 = 1;
							if (red1 == 1) {
								red2 = 0;
								green2 = 1;
								execlp("curl", "curl", "-s", ""192.168.6.7/gpio/3"", (char*)0);
								count++;
								sleep(1);
								if (count > 10) {
									count = 0;
									green2 = 0;
									yellow2 = 1;
									execlp("curl", "curl", "-s", ""192.168.6.7/gpio/5"", (char*)0);
									count++;
									sleep(1);
									if (count > 3) {
										count = 0;
										yellow2 = 0;
										left_green2 = 1;
										execlp("curl", "curl", "-s", ""192.168.6.7/gpio/4"", (char*)0);
										count++;
										sleep(1);
										if (count > 10) {
											count = 0;
											left_green2 = 0;
											yellow2 = 1;
											execlp("curl", "curl", "-s", ""192.168.6.7/gpio/5"", (char*)0);
											count++;
											sleep(1);
											if (count > 3) {
												count = 0;
												yellow2 = 0;
												red2 = 1;

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


int LED_3_1(void)
{
	int led_1_orange, led_1_white, led_2_orange, led_2_white, led_3_orange, led_3_white;

	led_1_orange = 0;
	led_1_white = 1;
	led_2_orange = 0;
	led_2_white = 1;
	led_3_orange = 1;
	led_3_white = 0;

	execlp("curl", "curl", "-s", ""192.168.x.x/gpio/6"", (char *)0);

}

int LED_2_2(void)
{
	int led_1_orange, led_1_white, led_2_orange, led_2_white, led_3_orange, led_3_white;

	led_1_orange = 0;
	led_1_white = 1;
	led_2_orange = 1;
	led_2_white = 0;
	led_3_orange = 0;
	led_3_white = 1;

	execlp("curl", "curl", "-s", ""192.168.x.x/gpio/7"", (char *)0);

}

int LED_1_3(void)
{
	int led_1_orange, led_1_white, led_2_orange, led_2_white, led_3_orange, led_3_white;

	led_1_orange = 1;
	led_1_white = 0;
	led_2_orange = 0;
	led_2_white = 1;
	led_3_orange = 0;
	led_3_white = 1;

	execlp("curl", "curl", "-s", ""192.168.x.x/gpio/8"", (char *)0);
}

