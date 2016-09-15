#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int a;
	int b;
}Node;



/* INPUT: pointer to input string
   OUTPUT: The number of words, as defined by the assignment description

   This function determines how many words are in the input string
*/


void fillArray(char *array, char *s){
	int arrayPosition;
	int count;
	int start;
	int i;
	int j;

	arrayPosition = 0;
	count = 0;
	i = 0;


	// While we haven't run off the string
	while(s[i] != '\0'){

		// While we have a separator and have not fallen off the string, continue
		while (!isalpha(s[i]) && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break;
		start = i;
		while (isalpha(s[i]) && s[i] != '\0'){
			count++;
			i++;
		}
		char *ptr = (char *) malloc((count+1) *sizeof(char));

		for (j = 0; j < count; j++){
			ptr[j] = s[start];
			start++;
		}
		ptr[j] = '\0';
		array[arrayPosition] = ptr;
		arrayPosition++;
		free(ptr);
	}

}




int numWords(char *s){
	int i;
	int wordCount;

	i = 0;
	wordCount = 0;

	while (s[i] != '\0'){

		while (!isalpha(s[i]) && s[i] != '\0')
			i++;


		if(s[i] == '\0')
			break;

		while (isalpha(s[i]) && s[i] != '\0')
			i++;
		wordCount++;

	}
	return wordCount;
}







int main(int argc, char *argv[]){
	int countOfWords;

	if (argc == 1){
		printf("Not Enough Arguments: Terminating program\n");
		return 0;
	}

	
	char *string = argv[1];
	countOfWords = numWords(string);
	printf("The number of words is %d\n", countOfWords);

	char *arrayptr[countOfWords];  // Create an array of size countOfWords to store words
	fillArray(arrayptr, string);


	return 0;	
}