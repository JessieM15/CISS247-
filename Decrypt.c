// Jessie Manson
// CISS 247, Fall 2017
// Oct 20,20117
// Assignment 1

#include <stdio.h>
#include <string.h>

#define BYTE    8

//extracts two 28-bit keys from 4bytes
void get_keys (char *twokeys, unsigned *key1, unsigned *key2){

  int len, len1,x = 0;
  printf("%s\n", twokeys);
  len = strlen(twokeys);
  len1 = len / 2;
  //printf("%d\n", len1);
  char k1 [len1];
  char k2 [len1];
  //fill temp array with letters
  for(int i = 0; i < len1; i++){
    k1[i] = twokeys[i];
    printf("%c", k1[i]);
  }
  //take temp array and fill with key1s
  key1= (k1[0]<<21)+(k1[1]<<14)+(k1[2]<<7)+(k1[3]);
  // x = 21;
  // for (int i = 0; i < len1-1; i++) {
  //   key1 += (k1[i]<<x);
  //   x-=7;
  //   printf("\n%d",key1);
  //
  // }
   printf("\n%d\n",key1);

  //fill key2 with letters
  for(int i = len1; i < len; i++){
    k2[i] = twokeys[i];
    printf("%c", k2[i]);
  }
  key2 = (k2[0]<<21)+(k2[1]<<14)+(k2[2]<<7)+(k2[3]);
  // x = 21;
  // for (int i = 0; i < len1-1; i++) {
  //   key2 += k1[i]<<x;
  //
  //   x-=7;
  // }
   printf("\n%d\n",key2);
  //

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
//
//
// void exor2(int *key2, int *cipher){
//  //int len = strlen(key1);
//  printf("\nxor2: ");
//  int bits[28];
//  for(int i=0; i<= 28; i++){
//    bits[i] = key2[i] ^ cipher[i];
//  }
//  for(int i = 0; i < 28; i++){
//    printf("%d ", bits[i] );
//  }
// printf("\n");
// }

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

  //getBits(cipher);
  unsigned key1 [BYTE];
  unsigned key2 [BYTE];
  get_keys(argv[1],key1,key2);
  //unsigned bits [strlen(cipher)];
  exor1(key1, cipher);
  // exor2(key2, cipher);

}
