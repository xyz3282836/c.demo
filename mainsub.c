#include <stdio.h>
#include "./lib/sub.h"
int main(int argc, char const *argv[])
{
	int a = 5;
	int b = 3;
	printf("%d - %d = %d \n", a,b,sub(a,b));
	return 0;
}