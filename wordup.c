//Author Alex Guerrero
//Final Project CS 135

#include <stdio.h>
#include <stdbool.h>

#define WORD "mystery.txt"
#define WSIZE 6
#define GUESSES 6

void getguess(char wordguess[GUESSES][WSIZE], int guessN);

int main(){
	char wordguess[GUESSES][WSIZE], textword[WSIZE];
	int guessN = 0;

	FILE* readword = fopen(WORD, "r");
	
	if(readword == NULL){
		printf("There is an issue opening the file :(");
		return 0;
	}
	
	fscanf(readword, "%s", textword);
	//printf("%s", wordguess);
	fclose(readword);
	
	//getguess(wordguess, guessN);
	
	
	
	
	//printf("%s %s",wordguess[guessN], textword);
	
	int huh = 5;
	int yes = 0;
	
	do{
		getguess(wordguess, guessN);
		
		for(int i = 0; wordguess[guessN][i] != '\0'; i++){
			if(wordguess[guessN][i] == textword[i]){
			huh +=1;
			}
		}
		
		if(huh = 5){
			for(int i = 0; textword[i] != '\0'; i++){
				textword[i] -= 32;
			}
			printf("\n                 %s", textword);
			printf("\n         You won in %d guesses!\n", guessN+1);
			
			return 0;
		}
		for(int i = 0; wordguess[guessN][i] != '\0'; i++){
			if(wordguess[guessN][i] == textword[i]){
			wordguess[guessN][i] -= 32;
			}
			printf("/n%s/n", wordguess[guessN]);
			
			for(int i = 0; wordguess[guessN][i] != '\0'; i++){
				if(wordguess[guessN][i] == textword[i]){
				yes = 1;
				}
				if(yes ==1){
					printf("^");
					yes = 0;
				}
				else{
				printf(" ");
				}
			}
		}
		huh -= 1;
		guessN ++;
	}while(huh != 0);
	
	
return 0;
}

void getguess(char wordguess[GUESSES][WSIZE], int guessN){
	int good = 0, count = 0;
	
	printf("GUESS %d! Enter your guess: ", guessN + 1);
	
	do{
		if(good == 1 || good == 2){
		
			printf("\nPlease Try again: ");
		}
		count = 0;
		good = 0;
		scanf("%s", wordguess[guessN]);
		
		for(int i = 0; wordguess[guessN][i] != '\0'; i++){
			count++;
		}
		//printf("%d", count);
		if(count!=5){
				printf("Your guess must be 5 letters long.");
				good = 1;
		}
		for(int i = 0; wordguess[guessN][i] != '\0'; i++){
			if(wordguess[guessN][i] < 'A'|| wordguess[guessN][i] > 'z'){
				good = 2;	
			}
			if(wordguess[guessN][i] >= 'A' && wordguess[guessN][i] <= 'Z'){
				wordguess[guessN][i] += 32;
			}
		}
		if(good == 2){
			printf("Your guess must contain only letters.");
		}
		//printf("%d", good);
		//printf("%s", wordguess[guessN]);
	}while(good != 0);
	
	printf("=====================================");
	//printf("%s", wordguess[guessN]);
}
