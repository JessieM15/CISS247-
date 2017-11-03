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
   floating-point number represented by a float_bitsparameter:
   This function must return:
   -negative integer, if the floating-point number is a “special”(±∞, or NaN).
   -zero, if the floating-point number is denormalized.
   -positive integer, if the floating-point number is normalized.
*/
int float_class(float_bits f){
  int var = f >> 23;
  return var + (var<<8) + (var<<16) + (var<<20);
  unsigned e = (f<<1);  //left 1 to get rid of exp
           e = (e>>22); //shift exp to right 22
  unsigned m = (f<<9);  //shift up to clear out exp and sign then
           m = (m>>9);  //shift back down
  return 0;

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
  return f >> 1;
}
int main(int count, char *word[]) {
  unsigned f = 1073741824;
  //f =   2143289344;
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

    // printf("%u\n", float_class(0));
    // printf("%u\n", float_class(2345676543));
    return 0;
}
