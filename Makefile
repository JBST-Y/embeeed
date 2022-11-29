all: libMyPeri.a textlcdtest

libMyPeri.a: led.o button.o buzzer.o fnd.o textlcd.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o  buzzer.o fnd.o textlcd.o

led.o: led.h led.c
	arm-linux-gnueabi-gcc led.c -o led.o -c

button.o: button.h button.c
	arm-linux-gnueabi-gcc button.c -o button.o -c

buzzer.o: buzzer.h buzzer.c
	arm-linux-gnueabi-gcc buzzer.c -o buzzer.o -c

fnd.o: fnd.h fnd.c
	arm-linux-gnueabi-gcc fnd.c -o fnd.o -c

textlcd.o: textlcd.h textlcd.c
	arm-linux-gnueabi-gcc textlcd.c -o textlcd.o -c

textlcdtest: led.h button.h buzzer.h fnd.h textlcd.h libMyPeri.a
	arm-linux-gnueabi-gcc --static -c -o textlcdtest.o textlcdtest.c
	arm-linux-gnueabi-gcc textlcdtest.o -l MyPeri -L. -lpthread -o textlcdtest


clean:
	rm -rf *.o *.a textlcdtest
