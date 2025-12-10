#include <stdio.h>
#include <stdlib.h>

int main(){
	int rows = 10,i,j;
	int **array;
	int *cols;
	cols = malloc(rows*sizeof(int));  //creating a pointer that stores the number of columns for each row
	array = malloc(rows*sizeof(int*));
	if(array!=NULL){
		printf("Memory allocation for rows was successfull\n");
	}
	
	for(i=0;i<rows;i++){
		printf("How many columns for row %d: ",i+1);
		scanf("%d", &cols[i]);  //number of columns for row[i] are saved in cols[i]
		array[i] = malloc(cols[i]*sizeof(int));
		for(j=0;j<cols[i];j++){  //loop played for number of columns for that particular row
			array[i][j]=i+1;  //since i row pointer starts from 0 we need to store 1 in row 0 hence we (i+1)
		}
		printf("\n");
	}	
	
	for(i=0;i<rows;i++){
		printf("row %d: ", i+1);
		for(j=0;j<cols[i];j++){   //uses the pointer we made to store columns for each row to print the whole array once allocation and initializing is done
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<rows;i++){
       free(array[i]);     //frees every row in the array
    }
    free(array);  
    free(cols);   //frees the cols pointer
 	printf("Memory allocated can be used again");
	
}

