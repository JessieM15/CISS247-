/*
  Jessie Manson
  Assignment 2
  11/17/2017
*/
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 40
#define MAX_WORDS 110000

// //declare array 110k long each with 40 characters
// //char wordlist[MAX_WORDS][MAX_WORD_LEN];
// //Then you can access the ith word in the list as wordlist[i].
//
void fillWordArray(char (*wordlist)[MAX_WORD_LEN]){
  // fill 2d array from the 1d array so it is filled properly
  int j = 0;
  //printf("%d\n",sizeof(wordlist[i][]));
  for (int i = 0; i < sizeof(wordlist)+1; i++) {

    for (int j = 0; j < sizeof(wordlist)+1; j++) {
      //printf("%d\n",sizeof(wordlist[i][j]));
  //  printf("%c\n",wordlist[i][j]);

    //while (wordlist[i][j] == '\n') {
    wordlist[i][j] = wordlist[i][j];
    //printf("%c",wordlist[i][j]);
    //}
    if(wordlist[i][j] == '\n'){
      wordlist[i][j] = '\0';
      //printf("test");
    }


    }


  }
//printf("\n" );
}


// void hammingDist(char *given, char (*wordlist)[MAX_WORD_LEN]){
//   // need to find all the same length words,
//   // then find the first letter that is the same
//   // closest word by comparing the next letters
//   // and keeping track of hamming dist,
//   // return words with same hamming distance
     // if hammming dist = 0 return word
//   chat tempWords [][];
//
//   for (int i = 0; i < sizeof(wordlist); i++) {
//     for (int j = 0; j< sizeof(wordlist); j++) {
//       printf("%c",wordlist[i][j]);
//
//         if(wordlist [i][j]== given [i]){
//           printf("%c\n",wordlist[i][j]);
//       }
//     }
//   }
//
//   //for loop thru temp word to get hamming dist
//   //return 0;
// }

int main(int argc, char *argv[]) {
  // need to take input and make it all lower cases
  // so can later be compared

   if(strlen(argv) < 2){
     printf("Format of Command is as followed : ./Assignment2 wordlist.txt ");
     return 0;
   }

    char wordlist[MAX_WORDS][MAX_WORD_LEN];
    FILE *input = fopen(argv[1], "r");
    for (int i = 0; i < sizeof(input); i++) {
      fgets(wordlist[i], MAX_WORD_LEN, input);
    }
printf("%d\n",sizeof(wordlist));
  //get word from user
  char word[MAX_WORD_LEN];
fgets(word, MAX_WORD_LEN, stdin);
  if (word == 0){
    printf("Form");
    return 0;
  }

  tolower(word); //makes user input lowercase
  fillWordArray(wordlist);
  //hammingDist(word, wordlist);
}
