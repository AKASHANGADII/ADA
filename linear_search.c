#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void search(int key,int a[],int n){
	count=0;
	int i=0;
	while(i<n){
	count++;
	if(a[i]==key){
		return;	
	}
	i++;
	}		
}
void main(){
	int ch,i,j,key;
	int *a;
	FILE *f1,*f2,*f3,*f;
	//Deleting the existing files
	system("rm l_best.txt");
	system("rm l_avg.txt");
	system("rm l_worst.txt");
	system("rm l_data.txt");
	
	//Opening the files
	f1=fopen("l_best.txt","a");
	f2=fopen("l_avg.txt","a");
	f3=fopen("l_worst.txt","a");
	f=fopen("l_data.txt","a");
	srand(time(0));
	
	for(i=10;i<100;i+=10){
		j=0;
		a=(int*)malloc(i*sizeof(int));
		
		while(j<i){
			a[j]=rand()%100;
			fprintf(f,"%d ",a[j]);
			j++;
		}
		fprintf(f,"\n\n");
		
		//best case
		key=a[0];
		search(key,a,i);
		fprintf(f1,"%d\t%d\n",i,count);
		//Average case
		a[(i-1)/2]=500;
		key=500;
		search(key,a,i);
		fprintf(f2,"%d\t%d\n",i,count);
		//Worst case
		key=150;
		search(key,a,i);
		fprintf(f3,"%d\t%d\n",i,count);
	}
	printf("Completed");
}
