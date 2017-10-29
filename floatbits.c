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
int float_class(float_bits f);


//Given a parameter f, this function will compute –f.If f is Nan,
//the function should simply return f.
int float_bitsfloat_negate(float_bits f){
  // or with 1000000, to flip the sign?
  return f * (-1);

}
// Given a parameter f, this function will compute|f|.
// If f is Nan, the function should simply return f.
int float_bitsfloat_absval(float_bits f){
  // and with 0 in sign position, to make a positive?
}

//Given a parameter f, this function will compute 2*f.
//If f is Nan, the function should simply return f.
unsigned float_bitsfloat_twice(float_bits f){
  return f << 1;
}
// Given a parameter f, this function will compute 0.5*f.
// If f is Nan, the function should simply return f.
unsigned float_bitsfloat_half(float_bits f){
  return f >> 1;
}
void main(int count, char *word[]) {
    printf("%d\n",float_bitsfloat_twice(5.0));
    printf("%d\n",float_bitsfloat_twice(5.2));
    printf("%d\n",float_bitsfloat_half(5));
    printf("%d\n",float_bitsfloat_half(5.2));
    printf("%d\n",float_bitsfloat_negate(5));

}
