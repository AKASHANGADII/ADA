#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int match(int str[],int ptn[],int slen,int plen){
	int count=0;
	int i,j;
	for(i=0;i<(slen-plen);i++){
		j=0;
		while(j<plen && ptn[j]==str[i+j]){
			j++;
			count++;
		}
		if(j==plen){
			return count;
		}
	}
	return count;
}
void main(){
	FILE *f,*f1,*f2,*f3;
	int *str,i,ptn[4];
	system("rm string_data.txt");
	system("rm string_best.txt");
	system("rm string_avg.txt");
	system("rm string_worst.txt");
	
	f=fopen("string_data.txt","a");
	f1=fopen("string_best.txt","a");
	f2=fopen("string_avg.txt","a");
	f3=fopen("string_worst.txt","a");
	for(i=10;i<=100;i+=10){
		str=(int *)calloc(i,sizeof(int));
		str[i-1]=1;
		//BEST case
		ptn[3]=ptn[2]=ptn[1]=ptn[0]=0;
		fprintf(f1,"%d\t%d\n",i,match(str,ptn,i,4));
		
		//Worst case
		ptn[3]=1;
		fprintf(f3,"%d\t%d\n",i,match(str,ptn,i,4));
		
		//Avg case
		str[((i/2)+1)]=1;
		fprintf(f2,"%d\t%d\n",i,match(str,ptn,i,4));
		
	}
}
