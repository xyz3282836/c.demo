#include <stdio.h>
#include "./inc/add.h"
int main(int argc, char const *argv[])
{
	int a = 5;
	int b = 3;
	printf("%d + %d = %d \n", a,b,add(a,b));
	return 0;
}