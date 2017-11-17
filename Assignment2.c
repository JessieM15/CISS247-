/*
  Jessie Manson
  Assignment 2
  11/17/2017
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 40
#define MAX_WORDS 110000
//declare array 110k long each with 40 characters
char wordlist[MAX_WORDS][MAX_WORD_LEN];
int lengwords; //total words in dictionary

//Then you can access the ith word in the list as wordlist[i].

int fillWordArray(char *argv){
  int lengwords=0;
  FILE *input = fopen(argv, "r");
//  char temp[MAX_WORD_LEN];
  //fgets(wordlist[i], MAX_WORD_LEN, input);

  while (1) {
    // if (wordlist[i] == '\n') {
    //   wordlist[i] = '\0';
    // }
    fgets(wordlist[lengwords], MAX_WORD_LEN, input);
    // for (int j = 0; j < (int) strlen(temp); j++) {// instead strcpy
    //   /* code */
    // }
  //  printf("%c",input[i]);
    if (feof(input)) {
      break;
    }
    lengwords++;
    //printf("%s\n", );
  }
  //printf("%d",lengwords);
  return lengwords;

}
int hammingDist(char *given, char *dword){
  // need to find all the same length words,
  // then find the first letter that is the same
  // closest word by comparing the next letters
  // and keeping track of hamming dist,
  // return words with same hamming distance
  //   if hammming dist = 0 return word
  int ham = 0;

  for (int i = 0; i < (int)strlen(given); i++) {
        if(dword[i] != given [i]){
          ham ++;
      }
    }
  //  printf("%d\n", ham);
    return ham;
  }

// int minham(int ham, int lengwords, char *wordlist, char *word2){
//   int bestham = MAX_WORD_LEN;
//   for (int i = 0; i < lengwords; i++) {
//     ham = (hammingDist(wordlist[i],word2)-2);
//     if (ham < bestham) {
//       bestham = ham;
//       //strcpy(hamtrack[j], wordlist[i]);
//
//     //  hamtrack [j] = wordlist[i];
//       //printf("b: %d ",bestham );
//       //j = 0;
//   }
//  }
//  return bestham;
// }

int main(int argc, char *argv[]) {
  // need to take input and make it all lower cases
  // so can later be compared
  char word[MAX_WORD_LEN];
  int ham;
  char hamtrack [5][MAX_WORD_LEN];
  int bestham = MAX_WORD_LEN;

  //printf("test");

   if(argc != 2){
     printf("Format of Command is as followed : ./Assignment2 wordlist.txt ");
    return 0;
   }

   lengwords = fillWordArray(argv[1]);
   //printf("%d\n",lengwords ); should be 194

   //this is to test the hamming distance
    // char word1[] = "app";
     char word2[] = "states";
    // printf("word %d\n",(int)strlen(word2));
    // hammingDist(word1, word2);
   for (int i = 0; i < lengwords; i++) {
//printf("%d\n", (int)(strlen(wordlist[i])+2));

    if ((strlen(wordlist[i])-2) == (strlen(word2))){ //|| (strlen(wordlist[i]) == (int)strlen(word2)+1)||
                                                //(int)strlen(wordlist[i]) == (int)strlen(word2)-1) {
        //printf("%d\n",(int)strlen(wordlist [i])-2);
        //printf("%s\n",wordlist [i]);
     ham = (hammingDist(wordlist[i],word2)-2);
     if (ham < bestham) {
        bestham = ham;
        // printf("%d \n",bestham );
        // printf("%s\n", wordlist[i]);
      }
    }
   }


int counter=0;
   for (int j = 0; j < lengwords; j++) {

     if ((strlen(wordlist[j])-2) == (strlen(word2))){ //|| (strlen(wordlist[i]) == (int)strlen(word2)+1)||
                                                //(int)strlen(wordlist[i]) == (int)strlen(word2)-1) {

     ham = (hammingDist(wordlist[j],word2)-2);
     // printf("h %d  ", ham);
     // printf("bh %d\n", bestham);
     if (ham == 0){
       printf("you spelled it correctly \n");
       return 0;
     }else if ((ham <= bestham) && (counter<5)) {
        bestham = ham;

        printf("%s\n",wordlist[j] );
        counter ++;
        //printf("c %d\n",counter  );
      }
    }
}
  //get word from user
  while(1){
    if
    printf("Enter a word: ");
    fgets(word, MAX_WORD_LEN, stdin);

    //tolower only looks at each individual charchter
    for (int i = 0; i < (int)strlen(word); i++) {
      word[i] = (char) tolower(word[i]);//tolower() makes user input lowercase
    }

    //printf("\n" );
    if (strlen(word-1)==0) {
      printf("Bye \n");
      return 0;
    }
  }
}
