/*
 * Lab3.c
 * CSCI 247, Fall, 2017
 *
 * Jessie Manson
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Write a functionto compute the bit-wise AND of two
// integers, using only the ~and |operators.
// int func1(int x, int y);
// For example, func1(5, 6) equals 4.  (0101 & 0110 = 0100).

void func1(int a, int b){
  int x = 0;
  a = ~a;
  b = ~b;

  x = a | b;

  x = ~x;
  printf("%d\n",x );

}
// Write a function to compute the bit-wise exclusive-or
// of two integers, using onlythe~ and &operators.
// int func2(int x, int y);
// For example, func2(4, 5)equals1.  (0100 ^ 0101 = 0001).
//Not 'a' then & them together

void func2(int a, int b){

  int x = 0;

  a = ~a;

  x = a & b;
  printf("%d\n",x );

}
/*Write a function to return a bit
-
mask with all 1's between lowbit and highbit, inclusive.
Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31.
 If lowbit > highbit, then mask should be all 0's.
int func5(int highbit, int lowbit);
For example,
func5(5, 3);
should return 56 (0x38 = 00111000
*/
// shift the bits so only ones between a and b
void func5(int a, int b){
    int x = 128;
    int y = 128;
    int ans;

    x = x >> a;
    y = y << b;

    ans = x | y;

    printf("%d\n", x);
}


int main(int count, char *word[]) {
    func1(4,5);
    func2(4,5);
    func5(5,3);
}
