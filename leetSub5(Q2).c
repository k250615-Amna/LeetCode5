#include <stdio.h>
#include <stdlib.h>
int **createMatrix(int m, int n){
	int **p;
	int i;
	p=malloc(m*sizeof(int*));  //allocate the rows 
	p[0]=malloc(m*n*sizeof(int));  //then in one single block allocate the rest of the columns
	//3x2 array would look like this:  [][] [][] [][]
	for (i = 1; i < m; i++) {
        p[i] = p[0] + i * n; 
    }
	return p;
}
int main(){
	int rows,cols;
	printf("Enter the number of rows: ");
	scanf("%d", rows);
	printf("Enter the number of columns: ");
	scanf("%d", cols);
	int **matrix = createMatrix(rows,cols);
	
	free(matrix[0]);   
    free(matrix);
	
	//the matrix values can be accessed by the formula p[i][j] = [i*rows + cols]
	//rows and column counting starts from 0 ...
}


/* 
(i) malloc will be called once to allocate all the rows and then five more times to allocate all the four columns for each row
so malloc is called a total of six times
(ii) error checking could be used after using malloc to allocate memory . to check if p was null if it was null
the function should break as memory allocation failed
(iii) since we allocated each row seperately , only freeing the (p) causes leaks ,instead we should
free every row individually using a for loop
*/
