#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int numberOfWords;
	int maximumLength;
}StringInfo;

void quicksorter(char ** array, int left, int right);
void swapElements(char ** array, int i, int j);
void printWords(char ** array, int length);
void freeMemory(char ** array, int arrayLength);
/* INPUT: pointer to input string
   OUTPUT: The number of words, as defined by the assignment description

   This function determines how many words are in the input string
*/


void fillArray(char **array, char *s, int arrayLength){
	
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
		ptr = NULL;
	}

	quicksorter(array, 0, arrayLength - 1); //Sort the array using quicksort
	printWords(array, arrayLength);     //print the array in order
	freeMemory(array,arrayLength);		//Frees the memory created by malloc
	//printf("Process complete\n");
}


void freeMemory(char ** array, int arrayLength){
	int i;

	for (i = 0; i < arrayLength; i++){
		free(array[i]);
		array[i] = NULL;
	}
}



void printWords(char ** array, int arrayLength){
	int i;
	for(i = 0; i < arrayLength; i++)
		printf("%s\n", array[i]);

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



void quicksorter(char **array, int left, int right){
	int i, last;

	if (left >= right)
		return;
	swapElements(array, left, (left+right)/2);
	last = left;
	for (i = left + 1; i <= right; i++){
		if (strcmp(array[i], array[left]) < 0)
			swapElements(array, ++last, i);
	}

	swapElements(array, left, last);
	quicksorter(array, left, last -1);
	quicksorter(array, last + 1, right);


}


void swapElements(char ** array, int i, int j){

	char * p;

	p = array[i];
	array[i] = array[j];
	array[j] = p;

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
	fillArray(arrayptr, string, info.numberOfWords);


	return 0;	
}