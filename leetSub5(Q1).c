#include <stdio.h>
#include <stdlib.h>

int main(){
	int rows = 10,i,j;
	int **array;
	int *cols;
	cols = malloc(rows*sizeof(int));
	array = malloc(rows*sizeof(int*));
	if(array!=NULL){
		printf("Memory allocation for rows was successfull\n");
	}
	
	for(i=0;i<rows;i++){
		printf("How many columns for row %d: ",i+1);
		scanf("%d", &cols[i]);
		array[i] = malloc(cols[i]*sizeof(int));
		for(j=0;j<cols[i];j++){
			array[i][j]=i+1;
		}
		printf("\n");
	}	
	
	for(i=0;i<rows;i++){
		printf("row %d: ", i+1);
		for(j=0;j<cols[i];j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<rows;i++){
       free(array[i]); 
    }
    free(array);  
    free(cols); 
 	printf("Memory allocated can be used again");
	
}
