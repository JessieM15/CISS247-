/*
 * Lab4
 * CSCI 247, Fall, 2017
 *
 * Jessie Manson
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned float_bits;
/* Write a function to identify the class of
   floating-point number represented by a float_bits parameter:
   This function must return:
   -negative integer, if the floating-point number is a “special”(±∞, or NaN).
   -zero, if the floating-point number is denormalized.
   -positive integer, if the floating-point number is normalized.
*/
int float_class(float_bits f){
  //isolate exponent
  unsigned e = (f<<1);  //left 1 to get rid of sign
           e = (e>>22); //shift exp to right 22
      //getting each bit
  unsigned e1 = (e << 7);
  unsigned e2 = (e << 6) +(e >> 1);
  unsigned e3 = (e << 5) +(e >> 2);
  unsigned e4 = (e << 4) +(e >> 3);
  unsigned e5 = (e << 3) +(e >> 4);
  unsigned e6 = (e << 2) +(e >> 5);
  unsigned e7 = (e << 1) +(e >> 6);
  unsigned e8 = (e >> 7);

  //add together to get 0 or 8 or 1-7
  unsigned x = e1 + e2 + e3 + e4 + e5 + e6 + e7 + e8;
  //shift to top of item
  return x << 24;

}
// Given a parameter f, this function will compute –f.If f is Nan,
// the function should simply return f.
int float_bitsfloat_negate(float_bits f){
  // or with 1000000, to flip the signbit
  unsigned x = ((1) << 31);
  return (f | x);

}
// Given a parameter f, this function will compute|f|.
// If f is Nan, the function should simply return f.
int float_bitsfloat_absval(float_bits f){
  // and with 0 in sign position, to make a positive?
  unsigned x;
  x = f << 1;
  x = x >> 1;
  return  x;
}

//Given a parameter f, this function will compute 2*f.
//If f is Nan, the function should simply return f.
int float_bitsfloat_twice(float_bits f){
  unsigned x = f >> 31;
  x = x << 31;

  return x + (f << 1);
  return f << 1;
}
// Given a parameter f, this function will compute 0.5*f.
// If f is Nan, the function should simply return f.
int float_bitsfloat_half(float_bits f){
  // unsigned x = f >> 31;
  // x = x << 31;

  return  (f >> 1);
}
int main(int count, char *word[]) {
  unsigned fp = 829510255; //00110001011100010101001001101111
  unsigned fn = 2976993903; //10110001011100010101001001101111

  printf("F is positive: %u\n", fp);
  printf("neg %u\n",float_bitsfloat_negate(fp));  //2976993903
  printf("abs %u\n",float_bitsfloat_absval(fp)); //829510255
  printf("dob %u\n",float_bitsfloat_twice(fp)); //1659020510
  printf("haf %u\n",float_bitsfloat_half(fp));  //414755127

  printf("F is negative: %u\n", fn);
  printf("neg %u\n",float_bitsfloat_negate(fn)); //2976993903
  printf("abs %u\n",float_bitsfloat_absval(fn)); //829510255
  printf("dob %u\n",float_bitsfloat_twice(fn));  //3806504158
  printf("haf %u\n",float_bitsfloat_half(fn));   //1488496951

  printf("Float class zero: %u\n", float_class(10)); //zero
  printf("Float class positive: %u\n", float_class(130652573)); //normalized - return positive - 3170893824
  printf("Float class negative: %u\n", float_class(2144480651)); //denormalized - return neg - 4110417920

    return 0;
}

