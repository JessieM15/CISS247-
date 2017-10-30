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
  unsigned e = (f<<1);  //left 1 to get rid of exp
           e = (e>>22); //shift exp to right 22
  unsigned m = (f<<9);  //shift up to clear out exp and sign then
           m = (m>>9);  //shift back down
  return 0;

}
// Given a parameter f, this function will compute –f.If f is Nan,
// the function should simply return f.
int float_bitsfloat_negate(float_bits f){
  // or with 1000000, to flip the sign?
  // return f *(-1);
  unsigned x = (1 >> 31);
  return f & x;

}
// Given a parameter f, this function will compute|f|.
// If f is Nan, the function should simply return f.
int float_bitsfloat_absval(float_bits f){
  // and with 0 in sign position, to make a positive?

}

//Given a parameter f, this function will compute 2*f.
//If f is Nan, the function should simply return f.
unsigned float_bitsfloat_twice(float_bits f){
  printf("%f\n",(f<<1) );
  return f << 1;
}
// Given a parameter f, this function will compute 0.5*f.
// If f is Nan, the function should simply return f.
unsigned float_bitsfloat_half(float_bits f){
  return f >> 1;
}
void main(int count, char *word[]) {
    printf("%d\n",float_bitsfloat_twice(5));
    printf("%f\n",(float)float_bitsfloat_twice(5.2));
    printf("%f\n",(float)float_bitsfloat_half(5.0));
    printf("%d\n",float_bitsfloat_half(5));
    printf("%f\n",(float)float_bitsfloat_negate(5));
    printf("%f\n",(float)float_bitsfloat_negate(5.2));
    printf("%f\n", (float) float_class(0));
}
