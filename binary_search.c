#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void search(int key,int arr[],int n){
	int start,end,mid;
	count=0;
	start=0;
	end=n-1;
	while(start<=end){
		mid=(start+end)/2;
		count++;
		if(arr[mid]==key){
			return;		
		}
		else if(key>*(arr+mid))
			start=mid+1;	
		else 
			end=mid-1;
	}
}
void main(){
	int ch,i,j,key;
	int *a;
	FILE *f1,*f2,*f3,*f;
	//Deleting the existing files
	system("rm b_best.txt");
	system("rm b_avg.txt");
	system("rm b_worst.txt");
	system("rm b_data.txt");
	
	//Opening the files
	f1=fopen("b_best.txt","a");
	f2=fopen("b_avg.txt","a");
	f3=fopen("b_worst.txt","a");
	f=fopen("b_data.txt","a");
	srand(time(0));
	
	for(i=10;i<=200;i+=10){
		j=0;
		a=(int*)malloc(i*sizeof(int));
		
		while(j<i){
			a[j]=(i==0)?rand()%10:a[j-1]+rand()%5+1;
			fprintf(f,"%d ",a[j]);
			j++;
		}
		fprintf(f,"\n\n");
		
		//best case
		key=a[(i-1)/2];
		search(key,a,i);
		fprintf(f1,"%d\t%d\n",i,count);
		//Average case
		key=a[(i-1)/4];
		search(key,a,i);
		fprintf(f2,"%d\t%d\n",i,count);
		//Worst case
		key=5000;
		search(key,a,i);
		fprintf(f3,"%d\t%d\n",i,count);
	}
	printf("Completed");
}
