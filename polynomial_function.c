#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ORDER 100
#define x 2

void main(){
	int *a,power,sum,i,j,k;
	FILE *p,*p1;
	system("rm poly_data.txt");
	system("rm poly_output.txt");
	
	p=fopen("poly_data.txt","a");
	p1=fopen("poly_output.txt","a");
	
	for(i=10;i<=ORDER;i+=10){
		a=(int *)malloc(i*sizeof(int));
		for(j=0;j<i;j++){
			a[j]=j+1;
			fprintf(p,"%d\t",a[j]);
		}
		fprintf(p,"\n");
		
		sum=a[0];
		power=1;
		for(k=1;k<i;k++){
			power=power*i;
			sum=sum+a[k]*power;
		}
		fprintf(p,"Sum of polynomial with x=%d and order %d is%d\n\n",ORDER,i-1,sum);
		fprintf(p1,"%d\t%d\n",i-1,i);
	}
	
}
