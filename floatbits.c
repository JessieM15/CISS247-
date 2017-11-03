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
  return f << 1;
}
// Given a parameter f, this function will compute 0.5*f.
// If f is Nan, the function should simply return f.
int float_bitsfloat_half(float_bits f){
  unsigned x = f >> 31;
  x = x << 31;

  return f >> 1;
}
int main(int count, char *word[]) {
  unsigned f = 1073741824;
  //f = 2143289344;
  printf("Float Class expected output\n", );
  printf("%u\n", float_class(2143289344));
     printf("dob %u\n",float_bitsfloat_twice(f));
    // printf("%u\n",float_bitsfloat_twice(5453657.2));
    // printf("%u\n",float_bitsfloat_twice(5453656457.2));
    // printf("%u\n",float_bitsfloat_twice(54536566543257.2));
    //
    printf("haf %u\n",float_bitsfloat_half(f));
    // printf("%u\n",float_bitsfloat_half(5453657.2));
    // printf("%u\n",float_bitsfloat_half(5453656457.2));
    // printf("%u\n",float_bitsfloat_half(54536566543257.2));

     printf("neg %u\n",float_bitsfloat_negate(f));
    // printf("| %u\n",float_bitsfloat_negate(5));
    // printf("| %u\n",float_bitsfloat_negate(-5678));
    // printf("| %u\n",float_bitsfloat_negate(5678));

    printf("abs %u\n",float_bitsfloat_absval(f));
    // printf("| %u\n",float_bitsfloat_absval(5));
    // printf("| %u\n",float_bitsfloat_absval(-5678));
    // printf("| %u\n",float_bitsfloat_absval(5678));

     printf("%u\n", float_class(8));
     printf("%u\n", float_class(2345676543));
    return 0;
}

