void intSort(int *s){
	int i, j;
	for(i=0; i<SIZE-1; i++){
		int pos=i;
		for(j=i+1; j<SIZE; j++){
			if(s[pos]>s[j])
				pos=j;
		}
		if(pos!=i){
			int swap=s[i];
			s[i]=s[pos];
			s[pos]=swap;
		}
	}
	for(i=0; i<SIZE; i++){
		printf("%d\t",s[i]);
	}
	printf("\n");
}

void floatSort(float *s){
	int i, j;
	for(i=0; i<SIZE-1; i++){
		int pos=i;
		for(j=i+1; j<SIZE; j++){
			if(s[pos]>s[j])
				pos=j;
		}
		if(pos!=i){
			float swap=s[i];
			s[i]=s[pos];
			s[pos]=swap;
		}
	}
	for(i=0; i<SIZE; i++){
		printf("%f\t",s[i]);
	}
	printf("\n");
}
