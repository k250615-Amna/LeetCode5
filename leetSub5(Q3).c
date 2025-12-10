#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatinated(char *string1, char* string2){
	int lenght = strlen(string1)+strlen(string2)+1;
	char* concat = realloc(string1,lenght);
	if(concat==NULL){
		printf("Memory allocation failed\n");
		return;
	}
	strcat(concat,string2);
	return concat;
	
}
int main(){
	char stringConcat[100];
	char *totalStrings = malloc(1);
	if(totalStrings==NULL){
		printf("Memory allocation failed/n");
		return;
	}
	totalStrings[0]='\0';
	while(1){
		printf("Enter a string: ");
    	scanf("%s", stringConcat);
    	if(strcmp(stringConcat,"Q")==0){
    		break;
		}
    	totalStrings = concatinated(totalStrings,stringConcat);
    	printf("%s \n",totalStrings);
	}
	free(totalStrings);
	printf("Memory freed");
	
}
