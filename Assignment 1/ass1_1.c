#include <stdio.h>
#include <string.h>

void main(){
	char s1[100], s2[100];
	printf("Enter two Strings: \n");
	gets(s1);
	gets(s2);
	int l1=strlen(s1);
	int l2=strlen(s2);
	int flag=1;
	if(l1==l2){
		int i;
		for(i=0; i<l1; i++){
			if(s1[i]!=s2[i]){
				flag=0;
				break;
			}
		}
	}else{
		flag=0;
	}
	printf("\n%d\n",flag);
}
