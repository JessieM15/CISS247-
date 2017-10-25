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
/* Write a function to return 1 if all the odd-numbered
bits in an integer are set to 1, and return 0 otherwise.
int func4(int x);

For example,
func4(0xFFFFFFFD) should return 0, func4(0xAAAAAAAA) should return 1
*/
void func4(int a){

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
    int x = 127;
    int y = 127;
    int ans,mask1,mask2, mask3;

    x = x << a;
    printf("a %d\n", x);
    mask1 = ~0;//<<a;

    printf("mask1 %d\n", mask1);

    y = ~(y << b);
    printf("b %d\n", y);
    mask2 = ~(~0<<b);
    printf("mask2 %d\n", mask2);

    mask3 = ~(1<<a);
    printf("mask3 %d\n", mask3);

    ans = x & y;
    printf("ans %d\n", ans);

    mask1 = mask1 & mask3;
    printf("mask1 %d\n", mask1);

    ans = ~(mask1 | mask2);
    printf("ans %d\n", ans);
}


int main(int count, char *word[]) {
    //func1(4,5);
    //func2(4,5);
    func4(5);
    func5(5,3);
}
