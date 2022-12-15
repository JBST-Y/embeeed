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
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <errno.h>
#include <getopt.h>
#include "accelmaggyro.h"

int main(void)
{
    Accel();
    Magnet();
    Gyro();

    return 0;
}
