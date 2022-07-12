

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a, count = 0;

void dfs(int graph[][a], int *visited, int i,FILE *f){
	int j;
	visited[i] = 1;
	fprintf(f,"%d ",i);
	for(j = 0; j< a; j++){
		count++;
		if ( graph[i][j] == 1 && !visited[j])
			dfs(graph, visited, j,f);
	}
}

void main(){
	int i, j;
	FILE *c,*f;
	system("rm count.txt");
	system("rm data.txt");
	f=fopen("data.txt","a");
	c = fopen("count.txt", "a");

	for(a = 5; a<=80; a+=5){
		int graph[a][a];
		int *visited = (int *)calloc(sizeof(int) , a);

		for(i = 0; i<a; i++){
			for(j = 0; j<a; j++){
				graph[i][j] = rand()%2;
				fprintf(f,"%d ",graph[i][j]);	
			}
			fprintf(f,"\n");
		}
		fprintf(f,"\n\n");
		i = rand()%a;
		dfs(graph, visited, i,f);
		fprintf(f,"\n\n");
		fprintf(c, "%d\t%d\n", a, count);
		count = 0;
	}
}
