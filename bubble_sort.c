#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
#define MIN 10
int count;
int n;
void sort(int a[]){
	count=0;
	int i,j,temp,flag=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			
			if(a[j]<a[j+1]){
				count++;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=a[j];
				flag=1;	
			}	
		}
		if(flag==0){
			return;
		}	
	}
}


void main(){
	int *a,i,j;
	FILE *f1,*f2,*f3,*f;
	srand(time(0));
	system("rm bubble_best.txt");
	system("rm bubble_avg.txt");
	system("rm bubble_worst.txt");
	system("rm bubble_data.txt");

	f1=fopen("bubble_best.txt","a");
	f2=fopen("bubble_avg.txt","a");
	f3=fopen("bubble_worst.txt","a");
	f=fopen("bubble_data.txt","a");
	
	printf("Generating random numbers>>");
	
	for(n=MIN;n<=MAX;n+=10){
		
		//BEST
		a=(int *)calloc(n,sizeof(int));
		for(j=0;j<n;j++){
			a[j]=(2*n)-i;
			fprintf(f,"%d\t",a[j]);	
		}
		sort(a);
		fprintf(f1,"%d\t%d\n",n,count);

		//Average		
		for(j=(n/2);j<n;j++){
			a[j]=a[j-1]+rand()%10+1;
			fprintf(f,"%d\t",a[j]);	
		}
		sort(a);
		fprintf(f2,"%d\t%d\n",n,count);

		//Worst
		for(j=0;j<n;j++){
			a[j]=(j==0)? rand()%10:a[j-1]+3;
			fprintf(f,"%d\t",a[j]);	
		}
		sort(a);
		fprintf(f3,"%d\t%d\n",n,count);
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f);
	printf("Completed\n");
	
}
