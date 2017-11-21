/*
  Jessie Manson
  Assignment 2
  12/8/2017
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int size = 1;

void sTopZone(int num){
  //printf("sT %d  ", num );
  if (num != 1 || num != 4){
    for (int i = 0; i < size; i++) {
      printf(" _");
    }
  }
 printf("  ");
}
void sMidZone(int num){
  //printf("AM %d  ", num );
    for (int i = 0; i < size; i++) {
        if (num == 1 ){
            printf("|");
          }else if (num == 7) {
            printf(" |");
          }else if (num == 0 ) {
            printf("| |");
          }else if (num == 2 || num == 3) {
            printf("_|");
          }else if (num == 5 || num == 6 ) {
            printf("|_");
          }else if (num == 4 || num == 8 || num == 9) {
            printf("|_|");
          }
    }
    printf("  ");
  }
  void sBotZone(int num){
  // printf("B %d  ", num );
      for (int i = 0; i < size; i++) {
          if (num == 1 ){
              printf("|");
            }else if (num == 4 || num == 7) {
              printf("  |");
            }else if (num == 0 || num == 6 || num == 8 ) {
              printf("|_|");
            }else if (num == 3 || num == 5 || num == 9) {
              printf("_|");
            }else if (num == 2) {
              printf("|_");
          }
      }
      printf("  ");
    }
void aTopZone(int *wnum){
  //for length of number
  //call sTopZone on every number
  //then print /n
  //printf("%d\n",sizeof(wnum));
  for (int i = 0; i < (sizeof(wnum)); i++) {
    //printf("%d\n",wnum[i] );
    sTopZone((int)wnum [i]);
  }
  printf("\n");

}
void aMidZone(int *wnum){
  //for length of number
  //call sTopZone on every number
  //then print /n
  //printf("%d\n",sizeof(wnum));
  for (int i = 0; i < (sizeof(wnum)); i++) {
  //  printf("%d\n",wnum[i] );
    sMidZone((int)wnum [i]);
  }
  printf("\n");
}
void aBotZone(int *wnum){
  //for length of number
  //call sTopZone on every number
  //then print /n
  //printf("%d\n",sizeof(wnum));
  for (int i = 0; i < (sizeof(wnum)); i++) {
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
  int wnum [] = {0,1,2,3,4,5,6,7,8,9};
  printf("%d\n",(int)sizeof(wnum)-1);
  for (int i = 0; i < (sizeof(wnum)); i++) {
    printf("%d\n",wnum[i] );
    //sTopZone(wnum [i]);
  }
  // if(wnum[0] <= 0){
  //   for (int i = 0; i < size; i++) {
  //     printf("__");
  //   }
  // }
  aTopZone(wnum); //all numbers
  //sTopZone(); //single number
   aMidZone(wnum);
  // aMidZone();
  //
  // sBotZone();
   aBotZone(wnum);

  // wnum = argv[1];

  return 0;
}
