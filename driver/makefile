all: libMyPeri.a buzzertest

libMyPeri.a: led.o button.o buzzer.o
        arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o  buzzer.o

led.o: led.h led.c
        arm-linux-gnueabi-gcc led.c -o led.o -c

button.o: button.h button.c
        arm-linux-gnueabi-gcc button.c -o button.o -c

buzzer.o: buzzer.h buzzer.c
        arm-linux-gnueabi-gcc buzzer.c -o buzzer.o -c

buzzertest: led.h button.h buzzer.h libMyPeri.a
        arm-linux-gnueabi-gcc --static -c -o buzzertest.o buzzertest.c
        arm-linux-gnueabi-gcc buzzertest.o -l MyPeri -L. -lpthread -o buzzertest
        scp buzzertest ecube@192.168.0.110:/home/ecube

clean:
        rm -rf *.o *.a buzzertest