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

void sTopZone(char num){
  //printf("%c  ", num );
  if ((num != '1') && (num != '4') && (num != '-')){
    printf(" ");
    for (int i = 0; i < size; i++) {
      printf("_");
    }
    printf(" ");

  }

  else{
    for (int i = 0; i < size; i++) {
      printf(" ");
    }
  }

  //printf("  ");
}
void sMidZone(char num){
  //printf("AM %d  ", num );

        if (num == '1' || num == '7'){
            for (int i = 0; i < (size-1); i++) {
              printf(" ");
            }
            for (int i = 0; i < size; i++) {
              printf(" | \t");
            }

          }else if (num == '0' ) {
            for (int i = 0; i < (size); i++) {
              printf("|");
              for (int j = 0; j < size; j++) {
                /* print spaces */
                printf(" ");
              }
              printf("|");
             if(i != size-1){
               // for (int j = 0; j < size-1; j++) {
               //   /* print spaces */
                 printf(" \t");
               // }
              }

            }
              printf("\t");
          }else if (num == '2' || num == '3') {
            for (int i = 0; i < (size); i++) {
              // need 2 foor loops to keep track of spaces
              // if(i != (size-1)){
              //     printf("|\n");
              //   // }else{
                printf(" _|\t");
              //   // }
              // }
            }
          }else if (num == '5' || num == '6' ) {
            printf("|_\t");
          }else if (num == '4' || num == '8' || num == '9') {
            printf("|_|\t");
          }else{
            for (int i = 0; i < size; i++) {
              printf(" __\t");
            }
          }

  //  printf("  ");
  }

  void sBotZone(char num){
  // printf("B %d  ", num );
          if (num == '1' ){
              printf(" | \t");
            }else if (num == '4' || num == '7') {
              printf("  |\t");

            }else if (num == '0' || num == '6' || num == '8' ) {
              for (int i = 0; i < size; i++) {
                printf("|");
                if(i == (size-1)){
                  //printf("|");
                  for (int k = 0; k < size; k++) {
                    printf("_");
                  }
                  printf("|");
                  break;
                }
                for (int j = 0; j < size; j++) {
                  printf(" ");
                }
                printf("|\n" );
              }
                printf("\t");

            }else if (num == '3' || num == '5' || num == '9') {
              printf(" _|\t");
            }else if (num == '2') {
              printf("|_ \t");

        }else{
          for (int i = 0; i < size; i++) {
            printf("   \t");
          }
        }
      }
      //printf("");

void aTopZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < size; j++) {
      sTopZone(wnum [i]);
      printf("\t");
    }
    //printf("%c\n", (int)wnum[i] );

  }
  printf("\n");

}
void aMidZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  for (int i = 0; i < len; i++) {
  //  printf("%d\n",wnum[i] );
    sMidZone(wnum [i]);
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
    sBotZone(wnum [i]);
  }
  printf("\n");
}
int main(int argc, char *argv[]) {
 //  int wnum;
  size = 3;
  if(argc < 2 || argc > 3){
    printf("Format of Command is as followed: \n  ./Assignment3 # size\n  Where the size is optional \n");
    printf("EXAMPLES: \n ./Assignment3 1234 \n ./Assignment3 1234 2 \n");
   return 0;
  }
  if(argc == 3){
   size = (int)argv[2];
   printf("%s\n",argv[2] );
   printf("%d\n",size );
   if (size > 5 && size < 1){
     printf("Whoops size must be between 0 and 5. \n");
    }
 }

 int len = 0;
  char wnum [] = {'0','0','\0'};
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
