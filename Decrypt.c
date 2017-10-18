// Jessie Manson
// CISS 247, Fall 2017
// Oct 20,20117
// Assignment 1

#include <stdio.h>
#include <string.h>

#define BYTE    8

//extracts two 28-bit keys from 4bytes
void get_keys (char *twokeys, unsigned *key1, unsigned *key2){
  int len, len1 = 0;
  printf("%s\n", twokeys);
  len = strlen(twokeys);
  len1 = len / 2;
  char k1 [len1];
  char k2 [len1];
  //fill key1 with letters
  for(int i = 0; i < len1; i++){
    k1[i] = twokeys[i];
  }

  printf("%s\n", k1);
  //convert k1 to binary
  for (int i = 0; i < strlen(k1); i++) {
    //print ascii
    int count = (int) k1[i];
    int j = BYTE-2;
    while(count != 0){
      if(count%2 == 0){
        key1[j]=0;
      }else {
        key1[j]=1;
      }
      count = count/2;
      j--;
    }
    // for(int i = 0; i < BYTE-1; i++){
    //   printf("%d ", key1[i] );
    // }
    for(int i = 0; i < BYTE-1; i++){
      printf("%d ", key1[i] );
    }
printf("\n");
  }

  //fill key2 with letters
  for(int i = len1; i < len; i++){
    k2[i] = twokeys[i];
    printf("%c ", k2[i]);
  }
  printf("\n");

  //convert k2 to binary
  for (int i = len1; i < len; i++) {
    //print ascii
    //printf("%d\n", (int) k2[i]);

    int count = (int) k2[i];
    int j = BYTE-2;

    while(count != 0){
      if(count%2 == 0){
        key2[j]=0;
      }else {
        key2[j]=1;
      }
      count = count/2;
      j--;
    }

    for(int i = 0; i < BYTE-1; i++){
      printf("%d ", key2[i] );
    }
    printf("\n");
  }
}

//
// /*returns the integer value of a specified subsequence of 32 bitswidthis
// //the number of bits to be extractedindex * widthis the index of the
// //rightmost bit to extract
// */
// unsigned int get_n_bits (unsigned bits, int width, int index){
//
// }
//
//given a sequence of 7 bits, rotate 3 bits to the left
// void rotate_left3(unsigned *bits){
//     bits = bits << 3;
//     //for(int i = 0; i < 28; i++){
//       printf("%d ", bits);
//     //}
//
// }
//
// //shuffle the 7 nibbles according to the pattern
// void shuffle_nibbles (unsigned *bits){
//
// }
//
// //decode a block of 28 bits
// void decode_28bits (unsigned cipher,char *plain,unsigned key1,unsigned key2){
//
// }

 void exor1(int *key1, int *cipher){
  //int len = strlen(key1);
  printf("\nxor1: ");
  int bits[28];
  for(int i=0; i<= 28; i++){
    bits[i] = key1[i] ^ cipher[i];
  }
  for(int i = 0; i < 28; i++){
    printf("%d ", bits[i] );
  }
printf("\n");
}


void exor2(int *key2, int *cipher){
 //int len = strlen(key1);
 printf("\nxor2: ");
 int bits[28];
 for(int i=0; i<= 28; i++){
   bits[i] = key2[i] ^ cipher[i];
 }
 for(int i = 0; i < 28; i++){
   printf("%d ", bits[i] );
 }
printf("\n");
}

//main
int main(int argc, char *argv[]){

//order of operations
  // get_keys(char *twokeys, unsigned *key1, unsigned *key2);
  // exor(); //with key 2 --
  // get_n_bits
  // shuffle_nibbles();
  // exor(); //with key 1
  // bits = rotate_left3(bits);
  // decode_28bits();

  // char line[8];
  // unsigned int bits;
  // char x;
  // //get the next 7 char of input(leaving space for null char)
  // while(fgets(line,8,stdin)){
  //
  //   //convert to a number
  //   x = sscanf(line,"%x", &bits);
  //   printf("%d\n", x );
  // }
  int cipher[29] = {1,1,0,1 ,1,0,1,1, 1,1,0,0 ,0,0,1,0, 0,0,1,0, 0,0,1,1, 0,0,1,1};
  //getBits(cipher);
  unsigned key1 [BYTE];
  unsigned key2 [BYTE];
  get_keys(argv[1],key1,key2);
  //unsigned bits [strlen(cipher)];
  exor1(key1, cipher);
  exor2(key2, cipher);

}
