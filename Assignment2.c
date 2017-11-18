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
  while (1) {
    fgets(wordlist[lengwords], MAX_WORD_LEN, input);

    if (feof(input)) {
      break;
    }
    lengwords++;
  }
  return lengwords;

}
int hammingDist(char *given, char *dword){

  int ham = 0;

  for (int i = 0; i < (int)strlen(given); i++) {
        if(dword[i] != given [i]){
          ham ++;
      }
    }
  //  printf("%d\n", ham);
    return ham;
  }

int getusr(){
  char word[MAX_WORD_LEN];
  int ham,bestham;
  char hamtrack [5][MAX_WORD_LEN];

  while(1){
    bestham = MAX_WORD_LEN;
    printf("\nEnter a word: ");
    fgets(word, MAX_WORD_LEN, stdin);

    if ((strlen(word)-1)==0) {
      printf("Bye \n");
      return 0;
    }
    int bestham = MAX_WORD_LEN;
    //tolower only looks at each individual charchter
    for (int i = 0; i < (int)strlen(word); i++) {
      word[i] = (char) tolower(word[i]);//tolower() makes user input lowercase
    }

    for (int i = 0; i < lengwords; i++) {
 //printf("%d\n", (int)(strlen(wordlist[i])+2));

     if (((strlen(wordlist[i])-2) == (strlen(word))-1) || ((strlen(wordlist[i])-2) == (strlen(word)+1)) || ((strlen(wordlist[i])-2) == (strlen(word)-2))){
         //printf("%d\n",(int)strlen(wordlist [i])-2);
         //printf("%s\n",wordlist [i]);
      ham = (hammingDist(wordlist[i],word)-2);
      if (ham < bestham) {
         bestham = ham;
         // printf("%d \n",bestham );
         // printf("%s\n", wordlist[i]);
       }
     }
    }


 int counter=0;
    for (int j = 0; j < lengwords; j++) {

      if (((strlen(wordlist[j])-2) == (strlen(word))-1) || ((strlen(wordlist[j])-2) == (strlen(word)+1)) || (strlen(wordlist[j])-2) == (strlen(word)-2)){
      ham = (hammingDist(wordlist[j],word)-2);
      // printf("h %d  ", ham);
      // printf("bh %d\n", bestham);
      if (ham == 0){
        printf("you spelled it correctly \n");
        getusr();
        //return 0;
      }else if ((ham <= bestham) && (counter<5)) {
         bestham = ham;

         printf(" possiblilty: %s",wordlist[j] );
         counter ++;
         //printf("c %d\n",counter  );
       }
     }
 }

    //printf("\n" );

  }
}

int main(int argc, char *argv[]) {
  // need to take input and make it all lower cases
  // so can later be compared
  char word[MAX_WORD_LEN];
  int ham;
  char hamtrack [5][MAX_WORD_LEN];


  //printf("test");

   if(argc != 2){
     printf("Format of Command is as followed: \n  ./Assignment2 wordlist.txt \n  ./Assignment2 wordEn.txt \n");
    return 0;
   }

   lengwords = fillWordArray(argv[1]);
   //printf("%d\n",lengwords ); should be 194

   //this is to test the hamming distance
    // char word1[] = "app";
     //char word2[] = "states";
    // printf("word %d\n",(int)strlen(word2));
    // hammingDist(word1, word2);
    getusr();
  //get word from user

}
