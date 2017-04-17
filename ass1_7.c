#include <stdio.h>
#include <string.h>

void main(){
	char s[50];
	printf("Enter a String.\n");
	gets(s);
	reverse(&s);
	return;
}

void reverse(char *s){
	int leng=strlen(s);
	int i;
	char out[50];
	for(i=0; i<leng; i++){
		out[i]=s[leng-i-1];
	}
	puts(out);
}
