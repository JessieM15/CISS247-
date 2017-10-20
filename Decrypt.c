// Jessie Manson
// CISS 247, Fall 2017
// Oct 20,20117
// Assignment 1

#include <stdio.h>
#include <string.h>

#define BYTE    8

//extracts two 28-bit keys from 4bytes
// void get_keys (char *twokeys, unsigned *key1, unsigned *key2){
//
//   int len, len1=0;
//   //printf("%s\n", twokeys);
//   len = strlen(twokeys);
//   len1 = len / 2;
//   char k1 [len1];
//   char k2 [len1];
//   //fill temp array with letters
//   for(int i = 0; i < len1; i++){
//     k1[i] = twokeys[i];
//     printf("%c", k1[i]);
//   }
//   //take temp array and fill with key1s
//   key1 = (k1[0]<<21)+(k1[1]<<14)+(k1[2]<<7)+(k1[3]);
//   //key 1 should equal 236485107
//   // int x = 0;
//   // x = 21;
//   // for (int i = 0; i < len1-1; i++) {
//   //   key1 += (k1[i]<<x);
//   //   x-=7;
//   //   //printf("\n%d",key1);
//   // }
//   // printf("\nkey1 %u\n",(unsigned) key1);
//
//   //fill key2 with letters
//   for(int i = len1; i < len; i++){
//     k2[i] = twokeys[i];
//     printf("%c", k2[i]);
//   }
//   key2 = (k2[4]<<21)+(k2[5]<<14)+(k2[6]<<7)+(k2[7]);
//   // key 2 should equal 251394404
//   // x = 21;
//   // for (int i = len1; i < len-1; i++) {
//   //   key2 += k2[i]<<x;
//   //   x-=7;
//   // }
//   //printf("\nkey2 %d\n",key2);
//   //
//
// }

//
// /*returns the integer value of a specified subsequence of 32 bitswidthis
// //the number of bits to be extractedindex * widthis the index of the
// //rightmost bit to extract
// */
unsigned int get_n_bits (unsigned *bits, int width, int index){
    //unsigned bits4 = 0;
    printf("width %u index %u\n",width, index );
    int start = width * (index + 1);
    printf("start %d\n",start );
    printf("test %d\n",(start-width) );

    for (int i = start; i >(start - width); i--) {
      printf("index %d\n",i );
      printf("index %d\n",bits[i] );
      bits += bits[i];
    }
    //printf("bits %d\n",bits );
    return bits;
}
//
//given a sequence of 7 bits, rotate 3 bits to the left
void rotate_left3(unsigned *bits){
  // make copy of the orginal
  // 1. shift 3 to the left and & with 127,
  // 2. copy shift right  4 then or (|) it with zeros
  // and then combine 1 and 2
  int bits2=74;
  int bits1 = 74;
  printf("bits2 %d bits1 %d\n",bits2 , bits1 );
  // int x = 3;
   bits2 = bits2 << 3;
   bits2 = bits2 & 127;
   printf("bits2 %d\n",bits2 );
   bits1 = bits1 >> 4;
   printf("bits1 %d\n",bits1 );

   bits= bits2 + bits1;
   printf("bits %d\n",bits );
}

// //shuffle the 7 nibbles according to the pattern
void shuffle_nibbles (unsigned *bits){
  printf("nibbles %d\n",bits );
  unsigned bits6, bits5, bits4, bits3, bits2, bits1, bits0 = 0;
  //unsigned 4bits = bits;
  int width = 4;
  for (int i = 0; i <= 6; i++) {
    if (i==6) {
          bits6 = get_n_bits(bits, width, i);
          printf("bits6 %d\n",bits6 );
    }else if (i==5) {
          bits5 = get_n_bits(bits, width, i);
          printf("bits5 %d\n",bits5 );
    }else if (i==4) {
          bits4 = get_n_bits(bits, width, i);
          printf("bits4 %d\n",bits4 );
    }else if (i==3) {
          bits3 = get_n_bits(bits, width, i);
          printf("bits3 %d\n",bits3 );
    }else if (i==2) {
          bits2 = get_n_bits(bits, width, i);
          printf("bits2 %d\n",bits2);
    }else if (i==1) {
          bits1 = get_n_bits(bits, width, i);
          printf("bits1 %d\n",bits1 );
    }else if (i==0) {
          bits0 = get_n_bits(bits, width, i);
          printf("bits0 %d\n",bits0);
        }
    }
    bits = bits3 + bits1 + bits2 + bits0 + bits4 + bits5 + bits6;
    //should be 123418445
    //printf("nibbles %d\n",bits );
}
//
// //decode a block of 28 bits
void decode_28bits (unsigned cipher, char *plain, unsigned key1, unsigned key2){
  //order of operations
    // get_keys(char *twokeys, unsigned *key1, unsigned *key2);
    // exor(); //with key 2 --
    // get_n_bits
    // shuffle_nibbles();
    // exor(); //with key 1
    // rotate_left3(bits);
    // decode_28bits(); // calls all the above functions.
    unsigned bits = 0;
    //xor with key 2
    //230433331
    bits = (key2^cipher);
    //printf("xor w key2 %d\n",bits );
    //shuffle_nibbles
     bits = 230433331;
     //shuffle_nibbles(bits);
     //output should be 123418445
    //xor with key1
    bits = (bits^key1);
    //printf("xor1 %d\n",bits );
    //output should be 155406014

    //rotate left 3
    rotate_left3(bits);

}


//main
int main(int argc, char *argv[]){

//order of operations
  // get_keys(char *twokeys, unsigned *key1, unsigned *key2);
  // exor(); //with key 2 --
  // get_n_bits
  // shuffle_nibbles();
  // exor(); //with key 1
  // rotate_left3(bits);
  // decode_28bits(); // calls all the above functions.

  // char line[8];
  // unsigned int bits;
  // char x;
  // //get the next 7 char of input(leaving space for null char)
  // while(fgets(line,8,stdin)){
  //
  //   //convert to a number
  //   x = sscanf(line,"%x", &bits);
     //printf("test");
  // }
//int cipher[29] = {1,1,0,1 ,1,0,1,1, 1,1,0,0 ,0,0,1,0, 0,0,1,0, 0,0,1,1, 0,0,1,1};

  unsigned cipher = 230433331; //decimal value of DBC2233
  unsigned key1 = 236485107;
  unsigned key2 = 251394404;
  unsigned bits = 0;
  char plain = 'a';
  //get_keys(argv[1],key1,key2);
  decode_28bits (cipher, plain, key1, key2);
}
