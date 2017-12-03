/*
  Jessie Manson
  Assignment 2
  12/8/2017
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int size = 1;
int len;
char under = '_';

void sTopZone(char num){
//printf("%c  ", num );
  if ((num != '1') && (num != '4') && (num != '-')){
    //printf(" ");
    for (int i = 0; i < size; i++) {
      printf(" _ ");
    }
    // for (int i = 0; i < size; i++) {
    //   printf(" ");
    // }
  }else{
    for (int i = 0; i < size; i++) {
      printf("   ");
    }
  }

 //printf("  ");
}
void sMidZone(char num){
  //printf("AM %d  ", num );

        if (num == '1' || num == '7'){
            // for (int i = 0; i < (size-1); i++) {
            //   printf(" ");
            // }
            for (int i = 0; i < size; i++) {
              printf("  |");
            }

          }else if (num == '0' ) {
            for (int i = 0; i < (size); i++) {
            //  if(i != 0 && i != size-1){
                //printf(" ");
              // }else{
                printf("| |");
              }
          }else if (num == '2' || num == '3') {
            for (int i = 0; i < (size); i++) {
              // need 2 foor loops to keep track of spaces
              // if(i != (size-1)){
              //     printf("|\n");
              //   // }else{
                printf(" _|");
              //   // }
              // }
            }
          }else if (num == '5' || num == '6' ) {
            printf("|_ ");
          }else if (num == '4' || num == '8' || num == '9') {
            printf("|_|");
          }else{
            for (int i = 0; i < size; i++) {
              printf(" __");
            }
          }

  //  printf("  ");
  }

  void sBotZone(char num){
  // printf("B %d  ", num );
      for (int i = 0; i < size; i++) {
          if (num == '1' ){
              printf("  |");
            }else if (num == '4' || num == '7') {
              printf("  |");
            }else if (num == '0' || num == '6' || num == '8' ) {
              printf("|_|");
            }else if (num == '3' || num == '5' || num == '9') {
              printf(" _|");
            }else if (num == '2') {
              printf("|_ ");

        }else{
          for (int i = 0; i < size; i++) {
            printf("   ");
          }
        }
      }
      //printf("");
    }
void aTopZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  for (int i = 0; i < len; i++) {
    //printf("%c\n", (int)wnum[i] );
    for (int j = 0; j < size; j++) {
      sTopZone(wnum [i]);
      printf(" ");
    }
  }
  printf("\n");

}
void aMidZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  for (int i = 0; i < len; i++) {
  //  printf("%d\n",wnum[i] );
  for (int j = 0; j < size; j++) {
    sMidZone(wnum [i]);
    printf(" ");
  }

  }
  printf("\n");
}
void aBotZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  //printf("%d\n",sizeof(wnum));
  for (int i = 0; i < len; i++) {
  //  printf("%d\n",wnum[i] );
  for (int j = 0; j < size; j++) {
    sBotZone(wnum [i]);
    printf(" ");
  }

  }
  printf("\n");
}
int main(int argc, char *argv[]) {
 //  int wnum;
 int size = 1;
  if(argc < 2 || argc > 3){
    printf("Format of Command is as followed: \n  ./Assignment3 # size\n  Where the size is optional \n");
    printf("EXAMPLES: \n ./Assignment3 1234 \n ./Assignment3 1234 2 \n");
   return 0;
  }if(argc == 3){
   size = (int)argv[2];
 }

 int len = 0;
  char wnum [] = {'0','2','0','9','0','9','0','\0'};
//  printf("%s\n",argv[1]);
  char temp[4];
  strcpy(wnum, argv[1]);
  while (wnum[len] != '\0') {
    //length function
    //printf("len %d \n", len);
    len++; //length
  }
  //a = for all numbers
   aTopZone(wnum,len);
   aMidZone(wnum,len);
   aBotZone(wnum,len);

  return 0;
}
