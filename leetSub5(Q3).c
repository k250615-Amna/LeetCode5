#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatinated(char *string1, char* string2){
	int lenght = strlen(string1)+strlen(string2)+1;  //stores total lenght of both strings plus one for the null terminator
	char* concat = realloc(string1,lenght);   //makes a pointer to store memory address of the reallocated memory for each iteration of a new string
	if(concat==NULL){
		printf("Memory allocation failed\n");
		return;
	}
	strcat(concat,string2);   //concatinates the strings
	return concat;
	
}
int main(){
	char stringConcat[100];
	char *totalStrings = malloc(1);
	if(totalStrings==NULL){     //initializes a pointer where  strings are stored
		printf("Memory allocation failed/n");  //if the function concatinated is called five times them all of those five strings are stored here
		return;
	}
	totalStrings[0]='\0';
	while(1){
		printf("Enter a string: ");
    	scanf("%s", stringConcat);
    	if(strcmp(stringConcat,"Q")==0){   //terminates if user types Q
    		break;
		}
    	totalStrings = concatinated(totalStrings,stringConcat);  
    	printf("%s \n",totalStrings);   
	}
	free(totalStrings);      //memory freed
	printf("Memory freed");
	
}

