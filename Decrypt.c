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
  // char k1 [];
  // char k2 [];
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
    printf("%d\n", (int) k1[i]);

    int count = (int) k1[i];
    int j =0;
    //printf("%d\n",j );
    while(count != 0){
      //printf("%d\n",count%2 );
      if(count%2 == 0){
        printf("%d ",count%2 );
        key1[j]=0;
      }else {
        key1[j]=1;
        printf("%d ",key1[j] );
      }
      count = count/2;
      j++;
    }
   printf("\n");

  }


  // //fill key2 with letters
  // for(int i = len1+1; i <= len; i++){
  //   k2[i] = twokeys[i];
  // }
  // printf("%s\n", k2);
}

//
// /*returns the integer value of a specified subsequence of 32 bitswidthis
// //the number of bits to be extractedindex * widthis the index of the
// //rightmost bit to extract
// */
// unsigned int get_n_bits (unsigned bits, int width, int index){
//   char line[8];
//   //unsigned int bits;
//   char x;
//   //get the next 7 char of input(leaving space for null char)
//   while(fgets(line,8,stdin)){
//
//     //convert to a number
//     x = sscanf(line,"%x", &bits);
//     printf("%d\n", x );
//   }
//   return bits;
// }
//
// //given a sequence of 7 bits, rotate 3 bits to the left
// unsigned int rotate_left3(unsigned bits){
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

// int exor(int *keyBit, int *cipher){
//   int len = strlen(keyBit);
//   int newbits[len];
//   for(int i=0; i<= len; i++){
//     newbits[i] = keyBit[i] ^ cipher[i];
//   }
//  return newbits;
// }
//main
int main(int argc, char *keys[]){

//order of operations
  // get_keys(char *twokeys, unsigned *key1, unsigned *key2);
  //get_n_bits //
  // exor(); //with key 2 --
  // shuffle_nibbles();
  // exor(); //with key 1
  // rotate_left3();
  // decode_28bits();
  unsigned key1 [BYTE];
  unsigned key2 [BYTE];
  get_keys(keys[1],key1,key2);

}
