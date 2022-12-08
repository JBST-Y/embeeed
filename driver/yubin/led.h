#ifndef _LED_H_ 
#define _LED_H_

int ledLibinit(void);
//led를  켜기  전에  반드시  함수 부르기
int ledOnOff(int ledNum, int onOff);
//ledNum에  0~7을  넣으면,  그에  해당하는  led ON OFF
int ledStatus(void);
// led상태 확인
//모든  led가  켜져  있으면  0xff  리턴
//모든  led가  꺼져  있으면  0x00  리턴
//(10101010)는 0xAA 리턴
int ledLibExit(void);
//led를  전부  끄고  driver를  close


#define  LED_DRIVER_NAME  "/dev/periled" 
#endif
