#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>

int main()
{
 printf("hello\n");
 execlp("./a.out", "./a.out", (char *)0);
}
