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

int main(void)
{
	   execl("/usr/bin/ssh", "-l", "ecube", "192.168.6.56");

}
