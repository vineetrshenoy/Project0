#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void quicksorter(char ** array, int left, int right);
void swapElements(char ** array, int i, int j);
void printWords(char ** array, int length);
void freeMemory(char ** array, int arrayLength);
void fillArray(char **array, char *s, int arrayLength);
int numWords(char *s);

int main(int argc, char *argv[]){
	int wordCount;

	if (argc != 2){
		printf("Incorrect Number of Arguments: Terminating program\n");
		exit(1);
	}

	
	char *string = argv[1];
	if (string == NULL){
		printf("Null input string: Terminating program\n");
		exit(1);
	}

	wordCount = numWords(string);
	if (wordCount == 0){
		printf("No words present in string: Terminating Program\n");
		exit(1);

	}
	//printf("The number of words is %d\n", wordCount);
	char *arrayptr[wordCount];  // Create an array of size wordCount to store words
	fillArray(arrayptr, string, wordCount);


	return 0;	
}


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
		if (ptr == NULL){
			printf("Not enough memory: Terminating Program\n");
			exit(1);
		}

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
	
}

/*
	INPUT: Array of char pointers; length of array
	OUTPUT: None

	This fuctions clear memory of malloc and sets pointers to null
*/
void freeMemory(char ** array, int arrayLength){
	int i;

	for (i = 0; i < arrayLength; i++){
		free(array[i]);
		array[i] = NULL;
	}
}


/*
	INPUT: Array of char pointers; length of array
	OUTPUT: None

	This functions prints the array of words in sorted order
*/
void printWords(char ** array, int arrayLength){
	int i;
	for(i = 0; i < arrayLength; i++)
		printf("%s\n", array[i]);

}

/*
	INPUT: The string argument given from the command line
	OUTPUT: The number of words in the string

	This function takes the string given at the command line and outputs the 
	number of words	in the string
*/
int numWords(char *s){
	int i, wordCount;
	

	i = wordCount = 0;
	

	while (s[i] != '\0'){

		// While we have a separator and have not fallen off the string, increase i
		while (!isalpha(s[i]) && s[i] != '\0')
			i++;

		//If the last characters are separators, then break
		if(s[i] == '\0')
			break;

		//Find the words
		while (isalpha(s[i]) && s[i] != '\0'){
			i++;
		}
		wordCount++;

	}
	
	return wordCount;
}


/*
	INPUT: The array of char* to words, the left-most index, the right-most index
	OUTPUT: None

	This function takes the array of char pointers and sorts it in alphabhetical order 
	using quicksort. I used the book "The C Programming Language" by Kernighan and
	Ritchie as a guide when devloping the quicksort.
*/
void quicksorter(char **array, int left, int right){
	int i, end;

	if (left >= right)
		return;				//Simple case: only one element: One element array is sorted
	swapElements(array, left, (left+right)/2);	//chosing a partition element and swapping it
	end = left;
	//moving elements smaller than pivot to left, items larger to right
	for (i = left + 1; i <= right; i++){
		if (strcmp(array[i], array[left]) < 0)
			swapElements(array, ++end, i);
	}

	swapElements(array, left, end);		//Moving the pivot
	//Sorting the left and right halves
	quicksorter(array, left, end -1);
	quicksorter(array, end + 1, right);


}



/*
	INPUT: The array of char* to words, index i and j of elements to be swapped
	OUTPUT: None

	This function swaps the pointers of two elements. This is a classic swap function
	
*/
void swapElements(char ** array, int i, int j){

	char * p;

	p = array[i];
	array[i] = array[j];
	array[j] = p;

}





