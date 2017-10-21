// Jessie Manson
// CISS 247, Fall 2017
// Oct 20,20117
// Assignment 1

#include <stdio.h>
#include <string.h>

#define BYTE    8

//extracts two 28-bit keys from 4bytes
void get_keys (char *twokeys, unsigned *key1, unsigned *key2){

  int len, len1=0;
  //printf("%s\n", twokeys);
  len = strlen(twokeys);
  len1 = len / 2;
  char k1 [len1];
  char k2 [len1];
  //fill temp array with letters
  for(int i = 0; i < len1; i++){
    k1[i] = twokeys[i];
    //printf("%c", k1[i]);
  }
  //take temp array and fill with key1s
  //key1 = (k1[0]<<21)+(k1[1]<<14)+(k1[2]<<7)+(k1[3]);
  //key 1 should equal 236485107
  int x = 0;
  x = 21;
  for (int i = 0; i < len1-1; i++) {
    key1 += (k1[i]<<x);
    x-=7;
    printf("\n%d",key1);
  }

  printf("key1 %u\n",(unsigned) key1);

  //fill key2 with letters
  for(int i = len1; i < len; i++){
    k2[i] = twokeys[i];
    //printf("%c", k2[i]);
  }
  //key2 = (k2[4]<<21)+(k2[5]<<14)+(k2[6]<<7)+(k2[7]);
  //key 2 should equal 251394404
  x = 21;
  for (int i = len1; i < len-1; i++) {
    key2 += k2[i]<<x;
    x-=7;
  }
  printf("key2 %d\n",key2);
  //

}

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
  //  printf("test %d\n",(start-width) );
    int nb [width];
    int count = 0;
    for (int i = start; i >(start - width); i--) {
      //printf("index %d\n",i );
      printf("index %d\n",&bits[i] );

      nb[count] = &bits[i];
      count++;
    }
    for(int i = 0; i < width-1; i++){
      printf("%d ", nb[i] );
    }
    //printf("bits %d\n",bits );
    return nb;
}
//
//given a sequence of 7 bits, rotate 3 bits to the left
void rotate_left3(unsigned *bits){
  // make copy of the orginal
  // 1. shift 3 to the left and & with 127,
  // 2. copy shift right  4 then or (|) it with zeros
  // and then combine 1 and 2
  unsigned bits2=bits;

   bits2 = bits2 << 3;
   bits2 = bits2 & 127;

   bits = (int) bits >> 4;

   bits= bits2 +(int) bits;

}

// //shuffle the 7 nibbles according to the pattern
void shuffle_nibbles (unsigned *bits){
  printf("nibbles start of shuffle %d\n",bits );
  unsigned bits6, bits5, bits4, bits3, bits2, bits1, bits0 = 0;
  unsigned int pbits [7] = {bits, bits, bits, bits, bits, bits, bits};
  for (int i = 28; i > 0; i--) {
        if(i>24){
          pbits[3] += &bits[i];
        }else if (i>=23 && i<=20) {
          pbits[1] += &bits[i];
        }else if (i>=19 && i<=16) {
          pbits[2] += &bits[i];
        }else if (i>=15 && i<=12) {
          pbits[0] += &bits[i];
        }else if (i>=11 && i<=8) {
          pbits[4] += &bits[i];
        }else if (i>=7 && i<=4) {
          pbits[5] += &bits[i];
        }else if (i>4 && i<=0) {
          pbits[6] += &bits[i];
        }
      }
    bits = pbits[6] + pbits[5] + pbits[4] + pbits[3] + pbits[2] + pbits[1] + pbits[0];
    //should be 123418445
    printf("nibbles end of nibbles %d\n",bits );
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
    printf("xor w key2 %d\n",bits );
    //shuffle_nibbles
     //bits = 230433331;
     //printf("test \n");
     shuffle_nibbles(bits);
     //output should be 123418445
     //bits= 123418445;
    //xor with key1
    bits = (bits^key1);
    printf("xor w key1 %d\n",bits );
    //output should be 155406014

    //rotate left 3
    //Note: need to call get_n_bits to shuffle by seven
        //Maybe create another method to do this??
      rotate_left3(bits);

}

//main
int main(int argc, char *argv[]){

  char plain = 'a';
  char line[8];
  //unsigned int bits;
  char x;
  unsigned cipher = 230433331; //decimal value of DBC2233
  unsigned key1 = 236485107;
  unsigned key2 = 251394404;
  unsigned bits = 0;
    get_keys(argv[1],key1,key2);
  //get the next 7 char of input(leaving space for null char)
  while(fgets(line,8,stdin)){

    //convert to a number
     if(line[0] == '\n'){
       sscanf(line,"%x", &bits);
       decode_28bits (cipher, plain, key1, key2);
     }
  }
}
