/*
  Jessie Manson
  Assignment 2
  11/17/2017
*/
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 40
#define MAX_WORDS 110000

//declare array 110k long each with 40 characters
//char wordlist[MAX_WORDS][MAX_WORD_LEN];
//Then you can access the ith word in the list as wordlist[i].

void fillWordArray(char *wordlist){
  // fill 2d array from the 1d array so it is filled properly
  int j = 0;

  for (int i = 0; i < sizeof(input); i++) {
    fgets(wordlist[i], MAX_WORD_LEN, input);
   if(input [i] == '\n'){
      j ++;
      i ++;
    }else{
      input[i]= fullArray[i][j];
    }


  }
}


int hammingDist(char given[], char *wordlist[][]){
  int ham = 0;
  // need to find all the same length words,
  // then find the first letter that is the same
  // closest word by comparing the next letters
  // and keeping track of hamming dist,
  // return words with same hamming distance
  int len = sizeof(given);

  for (int i = 0; i < count; i++) {
    if(sizeof(word[i][]) == len && word [i]== given [i]){
      tempWord[i] = word[i];
    }
  }

  //for loop thru temp word to get hamming dist




  return 0;
}

int main(int argc, char *argv[]) {
  // need to take input and make it all lower cases
  // so can later be compared

   if(strlen(argv) < 2){
     printf("Format of Command is as followed : ./Assignment2 wordlist.txt ");
     return 0;
   }

    char wordlist[MAX_WORDS][MAX_WORD_LEN];
    FILE *input = fopen(argv[1], "r");
    printf("test" );
    for (int i = 0; i < sizeof(input); i++) {
      fgets(wordlist[i], MAX_WORD_LEN, input);

    }

//  }
  //get word from user
  char word[MAX_WORD_LEN];
  fgets(word, MAX_WORD_LEN, stdin);

  //fillWordArray( wordlist);
}
