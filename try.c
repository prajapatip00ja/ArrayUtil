#include <stdio.h>
int main(int argc, char const *argv[])
{
	char c[] = {'a','b','c','d'};
	int *p = (int*)c;
	printf("%d",p[0]);
	return 0;
}
