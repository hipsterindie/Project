#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//we will get rid of stop words, special characters,
//sort the words in alphabetical order and store the words
//in a seperate file
//and we also will calculate frequency the word appears
//and the weight it has in the document
// (frequency of the word/highest frequency word in the text)

//We have split each word into a token.
//It's in it's own function
//write a new function that will eliminate stop words
//then write another function that will eliminate special chars
//I will have to open each text file.
//then compare it with the string we have.

#define BUFF_SIZE 1000000

void tokenizeString();
void removeStopWord(FILE *ifp, FILE *StopWord);



void main(){

	tokenizeString();

}

void removeStopWord(FILE *ifp, FILE *StopWord){
	
	FILE *ifp, *StopWord;

	char buff[BUFF_SIZE], Stopbuff[BUFF_SIZE];
	char *ifptoken, *StopWordtoken;
	
	char StopWordarray[BUFF_SIZE];
	int n;
	
	//read each line into the buffer
	while (fgets(buff, BUFF_SIZE, ifp) != NULL){
		
		//write the line to stdout
		fputs(buff, stdout);
	
		//new line to seperate stdout
		printf("\n------------------------------------------\n");
	
		//get the first token
		ifptoken = strtok(buff, " ");


		while (fgets(Stopbuff, BUFF_SIZE, StopWordtoken) != NULL){
			StopWordarray[BUFF_SIZE] = strtok(Stopbuff, "\n");
			n++;
		}

		
			
		//go through the other tokens
		while (ifptoken != NULL){
			
			char *temporary;
			for (int i = 0; i < n; i++)
			{

				if (ifptoken != StopWordarray[i]){
					
					printf("%s\n", ifptoken);
					ifptoken = strtok(NULL, " ");
				}
			}
			
			
		
		}
	
	}
}


void tokenizeString(){
	
	FILE *ifp, *ofp, *StopWord, *SpecialCharacters;

	char buff[BUFF_SIZE];
	char *last_token;


	ifp = fopen("d1.txt", "r");
	if (ifp == NULL){
		fprintf(stderr, "Can't open input file d1.txt.\n");
		exit(1);
	}

	ofp = fopen("Tokenizedd1.txt", "w");
	if (ofp == NULL){
		fprintf(stderr, "Can't open output file Tokenizedd1.txt.\n");
		exit(1);
	}

	StopWord = fopen("stopwords.txt", "r");
	if (StopWord == NULL){
		fprintf(stderr, "Can't open stopwords.txt.\n");
		exit(1);
	}

	SpecialCharacters = fopen("specialcharacters.txt", "r");
	if (SpecialCharacters == NULL){
		fprintf(stderr, "Can't open specialcharacters.txt.\n");
		exit(1);
	}

	removeStopWord(ifp, StopWord);

	//read each line into the buffer
/*	while (fgets(buff, BUFF_SIZE, ifp) != NULL){
		
		//write the line to stdout
		fputs(buff, stdout);
		
		//new line to seperate stdout
		printf("\n------------------------------------------\n");
		
		//get the first token
		last_token = strtok(buff, " ");
		
		//go through the other tokens
		while (last_token != NULL){
			fprintf(ofp, "%s\n", last_token);
			printf("%s\n", last_token);
			last_token = strtok(NULL, " ");
		}
		
		
	}				*/
	
	fclose(ifp);
	fclose(ofp);
	fclose(StopWord);
	fclose(SpecialCharacters);
	
}