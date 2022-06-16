#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sort(int arr[], int size){
	int index, i, j, count=0;
	for (i = 0; i<size-2; i++){
		int index = i;
		for (j = i+1; j<size-1; j++){
			count ++;
			if (arr[index] > arr[j])
				index = j;
		}
		
		if (index != i){
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
	return count;
}

void main(){
	FILE *s,*sa,*sb,*sw;
	int i, j, arr[1000];
	
	// DELETES PREVIOUSLY GENERATED FILES
	system("rm selection_data.txt");
	system("rm selection_B.txt");
	system("rm selection_W.txt");
	system("rm selection_A.txt");

	// OPEN IN APPEND MODE
	sa = fopen("selection_A.txt", "a");
	sb = fopen("selection_B.txt", "a");
	sw = fopen("selection_W.txt", "a");
	s = fopen("selection_data.txt", "a");


	for(i=100; i<=1000; i+=100){
		srand(time(0));
		
		// WORST CASE
		fprintf(s,"Worst case\n");
		for(j=0; j<i; j++){
			arr[j] = (j==0) ? rand()%10 : arr[j-1] - rand()%10;
			fprintf(s, "%d  ", arr[j]);
		}
		fprintf(sw, "%d\t%d\n", i, sort(arr, i));
		fprintf(s,"\n\n");
		
		// BEST CASE
		fprintf(s,"Best case\n");
		for(j=0; j<i; j++){
			arr[j] = (j==0) ? rand()%10 : arr[j-1] + rand()%10;
			fprintf(s, "%d  ", arr[j]);
		}
		fprintf(sb, "%d\t%d\n", i, sort(arr, i));
		fprintf(s,"\n\n");

		// AVERAGE CASE
		fprintf(s,"Average case\n");
		for(j=i/2; j<i; j++){
			arr[j] = rand()%100;
			fprintf(s, "%d  ", arr[j]);
		}
		fprintf(sa, "%d\t%d\n", i, sort(arr, i));
		fprintf(s,"\n\n");
	}
	
		fclose(s);
		fclose(sw);
		fclose(sa);
		fclose(sb);
	
}
