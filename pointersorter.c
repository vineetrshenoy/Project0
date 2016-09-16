#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int numberWords;
	int maximumLength;
}StringInfo;



/* INPUT: pointer to input string
   OUTPUT: The number of words, as defined by the assignment description

   This function determines how many words are in the input string
*/


void fillArray(char **array, char *s){
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
		

		// Call a sorting algorithm on the array of pointers
		// Print array of sorted words
		// free all memory
		// return to main
	}

}




StringInfo numWords(char *s){
	int i, wordCount, maxLength, tempCount;

	i = wordCount = maxLength =  tempCount = 0;
	StringInfo info;

	while (s[i] != '\0'){

		while (!isalpha(s[i]) && s[i] != '\0')
			i++;


		if(s[i] == '\0')
			break;

		while (isalpha(s[i]) && s[i] != '\0'){
			tempCount++;
			i++;
		}
		wordCount++;

		if (tempCount > maxLength)
			maxLength = tempCount;
		

		tempCount = 0;

	}
	
	info.numWords = wordCount;
	info.maximumLength = maxLength;

	return info;
}







int main(int argc, char *argv[]){
	int wordCount;

	if (argc == 1){
		printf("Not Enough Arguments: Terminating program\n");
		return 0;
	}

	
	char *string = argv[1];
	//wordCount = numWords(string);
	StringInfo info = numWords(string);
	printf("The number of words is %d\n", info.numberWords);
	// char * arrayptr = (char *) malloc(wordCount * sizeof(char *))
	char *arrayptr[info.numberWords];  // Create an array of size wordCount to store words
	fillArray(arrayptr, string);


	return 0;	
}