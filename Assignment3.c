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
  if ((num != '1') && (num != '4') && (num != '-')){
    for (int i = 0; i < size; i++) {
      printf(" _ ");
    }
  }else{
    for (int i = 0; i < size; i++) {
      printf("   ");
    }
  }
}
void sMidZone(char num){
  if (num == '1' || num == '7'){
    for (int i = 0; i < size; i++) {
      printf("  |");
    }
  }else if (num == '0' ) {
    for (int i = 0; i < (size); i++) {
      printf("| |");
    }
  }else if (num == '2' || num == '3') {
    for (int i = 0; i < (size); i++) {
      printf(" _|");
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
}

void sBotZone(char num){
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
}
void aTopZone(char *wnum, int len){
  //for length of number
  //call sTopZone on every number
  //then print /n
  for (int i = 0; i < len; i++) {
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
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < size; j++) {
      sBotZone(wnum [i]);
      printf(" ");
    }
  }
  printf("\n");
}
void numCheck(char numC, int len){
  if ( ((numC == '-') && (len == 0)) || (isdigit(numC))) {
    /* code */
  }
//  if (isdigit(numC)){

else{
    printf("Number needs to be between 0-9 and the '-' sign can only be the first character \n");
    exit(EXIT_FAILURE);
  }
}
void calcsize(char *scale){
  if (scale[0] == '1' ) {
    size = 1;
  }else if (scale[0] == '2' ) {
    size = 2;
  }else if (scale[0] == '3' ) {
    size = 3;
  }else if (scale[0] == '4' ) {
    size = 4;
  }else if (scale[0] == '5') {
    size = 5;
  }else{
    printf("Size needs to be between 1 and 5 \n Size default is 1\n");
    exit(EXIT_FAILURE);
  }
}
int main(int argc, char *argv[]) {
  char scale [4];
  int size = 1;
  if(argc < 2 || argc > 3){
    printf("Format of Command is as followed: \n  ./Assignment3 # size\n  Where the size is optional \n");
    printf("EXAMPLES: \n ./Assignment3 1234 \n ./Assignment3 1234 2 \n");
    return 0;
  }if(argc == 3){
    strcpy(scale, argv[2]);
    calcsize(scale);
  }

  int len = 0;
  char wnum [80];
  strcpy(wnum, argv[1]);
  while (wnum[len] != '\0') {
    numCheck(wnum[len],len);
    //length function
    len++; //length
  }
  //a = for all numbers
  aTopZone(wnum,len);
  aMidZone(wnum,len);
  aBotZone(wnum,len);

  return 0;
}
