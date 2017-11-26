/*
  Jessie Manson
  Assignment 2
  12/8/2017
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int size = 1;
int len;
char under = '_';

void sTopZone(char num){
//printf("%c  ", num );
  if ((num != '1') && (num != '4')){
    //printf(" ");
    for (int i = 0; i < size; i++) {
      printf(" _ \t");
    }
    // for (int i = 0; i < size; i++) {
    //   printf(" ");
    // }
  }else{
    for (int i = 0; i < size; i++) {
      printf("   \t");
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
            //  if(i != 0 && i != size-1){
                //printf(" ");
              // }else{
                printf("| |\t");
              }
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
          }

  //  printf("  ");
  }

  void sBotZone(char num){
  // printf("B %d  ", num );
      for (int i = 0; i < size; i++) {
          if (num == '1' ){
              printf(" | \t");
            }else if (num == '4' || num == '7') {
              printf("  |\t");
            }else if (num == '0' || num == '6' || num == '8' ) {
              printf("|_|\t");
            }else if (num == '3' || num == '5' || num == '9') {
              printf(" _|\t");
            }else if (num == '2') {
              printf("|_ \t");
          }
      }
      //printf("");
    }
void aTopZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  //printf("%d\n",sizeof(wnum));
  for (int i = 0; i < len; i++) {
    //printf("%c\n", (int)wnum[i] );
    sTopZone(wnum [i]);
  }
  printf("\n");

}
void aMidZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  //printf("%d\n",sizeof(wnum));
  //printf("%d\n",len );
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
  //int wnum;
 //  if(argc < 2 || argc > 3){
 //    printf("Format of Command is as followed: \n  ./Assignment3 # size\n  Where the size is optional \n");
 //   return 0;
 //  }if(argc == 3){
 //   size = argv[2];
 // }
 int len = 0;
  char wnum [] = {'0','2','1','9','8','\0'};
  while (wnum[len] != '\0') {
    //length function
    //printf("len %d \n", len);
  //  printf("%c\n",wnum[len] );
    len++; //length

  }
  // printf("%d\n",(int)sizeof(wnum)-1);
  // printf("%d\n",len);
  // while
  // for (int i = 0; i < (sizeof(wnum)); i++) {
  //   printf("%c\n",wnum[i] );
  //   //sTopZone(wnum [i]);
  // }
  // if(wnum[0] <= 0){
  //   for (int i = 0; i < size; i++) {
  //     printf("__");
  //   }
  // }
//  printf("1\t1\n" );
  aTopZone(wnum,len); //all numbers
  //sTopZone(); //single number
   aMidZone(wnum,len);
  // aMidZone();
  //
  // sBotZone();
   aBotZone(wnum, len);

  // wnum = argv[1];

  return 0;
}
