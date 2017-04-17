#include<stdio.h>

void main(){
	int n;
	printf("Enter a Number: ");
	scanf("%d",&n);
	int i;
	for(i=2; i<=n; i++){
		if(n%i==0){
			if(isPrime(i)){
				printf("%d\t",i);
			}
		}
	}printf("\n");
}

int isPrime(int n){
	if(n==2) return 1;
	else if(n%2==0) return 0;
	else{
		int i=3;
		for(i; i<n; i+=2){
			if(n%i==0) return 0;
		}
	}
	return 1;
}

