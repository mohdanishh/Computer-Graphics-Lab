#include <stdio.h>
#include <string.h>

void main(){
	char a[32];
	printf("Enter a String: ");
	gets(a);
	int *p=(int *)a;
	printf("%d\n",p[0]);
}

