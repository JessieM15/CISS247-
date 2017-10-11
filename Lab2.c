/*
 * Lab2.c
 * CSCI 247, Summer, 2017
 *
 * main() written by David Bover, July, 2017
 *
 * students get to complete the functions toDecimal() and fromDecimal()
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DECIMAL     10
#define MAX_BASE    36
#define WIDTH       20      // width of the string used to store the result

// function digitChar()
// returns the character for the digit with value in base
// parameters:
//      value, the decimal value of the digit
//      base, the decimal value of the number system base
// return:
//      character in the range '0'-'9' or 'A'-'Z'

char digitChar(int value, int base) {

    // check for valid range
    if (value < 0 || value >= base) {
        printf("invalid digit value %d for base %d\n", value, base);
        exit(1);
    }

    // check for range 0 to 9
    if (value >= 0 && value <= 9)
        return '0' + value;

    // check for range 10 to MAX_BASE -1
    else
        return 'A' + value - 10;

}

// function digitValue()
// returns the decimal value of a digit character
// digit must be in the range '0'-'9', 'a'-'z', or 'A'-'Z'
// digit value must be less than base
// parameters:
//      digit, the character whose value is to be returned
//      base, the number base, to check range
// return:
//      decimal value of digit

int digitValue(char digit, int base) {

    int value = base;

    if (digit >= '0' && digit <= '9')
        value = digit - '0';

    else if (digit >= 'a' && digit <= 'z')
        value = digit - 'a' + 10;

    else if (digit >= 'A' && digit <= 'Z')
        value = digit - 'A' + 10;

    if (value < base) return value;

    // an invalid digit
    printf("invalid digit %c for base %d\n", digit, base);
    exit(1);
    return value;
}


// function toDecimal()
// returns the decimal value of a number in a specified base
// parameters:
//      base, integer value of the number system to convert from
//      number, the number to be converted to decimal
// return:
//      the decimal value of number
// example:
//      toDecimal(16, "2E") returns 46

//power function
int powFunc(int base, int exponent, int num){
  int output = num;
  printf(" output %d base %d num %d exponent %d \n ", output,base, num, exponent );
  for (int i = 0; i < exponent; i++) {
  //  printf(" output 1 %d \n ", output );
    output *= base;
    printf(" output %d base %d num %d exponent %d \n ", output,base, num, exponent );
  }
  return output;
}

int toDecimal(int base, char *number){

  int len = 0;
  int numberToReturn = 0;
  int num = 0;
  //printf("%d\n",**number);
  while (number[len] != '\0') {
    //length function
    len++; //length
    printf("len %d \n", len);
  }
  int k =0;
  for(int exponent = len-1; exponent >= 0; exponent--){
  //  for (int k = 0; k < exponent; k++) { // k is to reference number eg num[k]
      num = digitValue(number[k],base);
      //printf(" num %d \n", num );
      numberToReturn += powFunc(base, exponent, num);
      printf(" num %d \n", numberToReturn );
      k++;
      //printf(" numberToReturn %d \n", num );
  //  }
    // numberToReturn +=  digitValue(number[j],base);
  }
  printf(" numberToReturn %d \n", numberToReturn);
  return  numberToReturn;
}


//opposite of powFunc to work backwards  
char divFunc(int base, int decimal, int exponent){
  char output = decimal;
  //printf(" output %d base %d num %d exponent %d \n ", output,base, num, exponent );
  for (int i = 0; i < exponent; i++) {
  //  printf(" output 1 %d \n ", output );
    output /= base;
    printf(" output %d base %d num %d exponent %d \n ", output,base, num, exponent );
  }
  return output;

}

// function fromDecimal()
// returns a string as the result of converting a decimal number to a specified base
// parameters:
//      base, the base of the number system to convert to
//      decimal, the decimal value to convert to
//      number, a string to contain the result
// return:
//      pointer to the string containing the result (parameter number)
// example:
//      char text[WIDTH];
//      fromDecimal(16, 46, text);
//      text contains the string "2E"

char *fromDecimal(int base, int decimal, char *number){
    char finalNum = 0;
    while (decimal[len] != '\0') {
      //length function
      len++; //length
      printf("len %d \n", len);
    }
    for (int i = len; i < len; i++) {

      num = digitChar(number[k],base);
    }

    return finalSum;
}

// function main()
// expects command-line arguments: base, number1, number2

int main(int count, char *word[]) {

    // check for the correct number of command-line arguments
    if (count < 4) {
        printf("Usage: ./Lab2 base num1 num2\n");
        return 0;
    }

    // get the number base and check for range 2 to 36
    //printf("Word[1] %s\n", word[1]);

    int base = toDecimal(DECIMAL, word[1]);
    printf("Base %d\n", base);

    if (base < 2 || base > MAX_BASE) {
        printf("Usage: ./Lab2 base num1 num2\n");
        printf("base must be in the range 2 to 36\n");
        return 0;
    }

    // get the decimal value of the two numbers to be added
    int num1 = toDecimal(base, word[2]);
    int num2 = toDecimal(base, word[3]);

    // calculate the sum of the two numbers
    int result = num1 + num2;

    // convert the decimal result back to the base of the numbers
    char text[WIDTH];
    char *answer = fromDecimal(base, result, text);

    // display the result
    printf("In base %d, %s + %s = %s\n", base, word[2], word[3], answer);

}
