#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int numberOfWords;
	int maximumLength;
}StringInfo;



/* INPUT: pointer to input string
   OUTPUT: The number of words, as defined by the assignment description

   This function determines how many words are in the input string
*/
//simple comment

void fillArray(char **array, char *s){
	
	int arrayPosition, count, start, i, j;

	arrayPosition = count = i = 0;


	// While we haven't run off the string
	while(s[i] != '\0'){

		// While we have a separator and have not fallen off the string, increase i
		while (!(isalpha(s[i])) && s[i] != '\0')
			i++;
		
		//If the last characters are separators, then break
		if (s[i] == '\0')
			break;
		

		start = i;		//the starting index of the word

		//find the length of the word to in order to malloc
		while (isalpha(s[i]) && s[i] != '\0'){
			count++;
			i++;
		}

		//allocate memory for the specific word
		char *ptr = (char *) malloc((count+1) *sizeof(char));

		//copy the word to ptr
		for (j = 0; j < count; j++){
			ptr[j] = s[start];
			start++;
		}
		ptr[j] = '\0';

		//have array[arrayPosition] point to word
		array[arrayPosition] = ptr;
		arrayPosition++;
		count = 0;
		

		// Call a sorting algorithm on the array of pointers
		// Print array of sorted wordsh
		// free all memory
		// return to main
	}

	printf("Values\n");

}




StringInfo numWords(char *s){
	int i, wordCount, maxLength, tempCount;
	StringInfo info;

	i = wordCount = maxLength =  tempCount = 0;
	

	while (s[i] != '\0'){

		// While we have a separator and have not fallen off the string, increase i
		while (!isalpha(s[i]) && s[i] != '\0')
			i++;

		//If the last characters are separators, then break
		if(s[i] == '\0')
			break;

		//Find the words
		while (isalpha(s[i]) && s[i] != '\0'){
			tempCount++;
			i++;
		}
		wordCount++;

		//If a word of new maxLength is found, reassign
		if (tempCount > maxLength)
			maxLength = tempCount;
		

		tempCount = 0;

	}
	
	//Setting values for return
	info.numberOfWords = wordCount;
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
	printf("The number of words is %d\n", info.numberOfWords);
	// char * arrayptr = (char *) malloc(wordCount * sizeof(char *))
	char *arrayptr[info.numberOfWords];  // Create an array of size wordCount to store words
	fillArray(arrayptr, string);


	return 0;	
}