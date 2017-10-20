#include <stdio.h>
#include <string.h>
#include <math.h>
#define NIBBLE 4
#define BYTE 8
#define SEPTET 7

// Prints out the bits of any integer
// Main purpose is for testing
void printBits(unsigned int num, int size) {
  unsigned int maxPow = 1<<(size*8-1);
  int i=0;
  for (;i<size*8;++i) {
    printf("%u ", num&maxPow ? 1 : 0);
    num = num<<1;
  }
}

// Zeroes out any bits except for the numOfBits being used
unsigned int zeroBits(unsigned bits, int power, int numOfBits) {

  int i = 0;

  for(i = 32; i >= power; i--) {
    if((bits & (unsigned)(pow(2, i))) != 0) {
      bits -= pow(2, i);
    }
  }

  for(i = 0; i < power-numOfBits; i++) {
    if((bits & (unsigned)(pow(2, i))) != 0) {
      bits -= pow(2, i);
    }
  }

  return bits;

}

// Extracts two 28-bit keys from 4 bytes
void get_keys (char *twokeys, unsigned int *key1, unsigned int *key2) {

  *key1 = (twokeys[0]<<21) + (twokeys[1]<<14) + (twokeys[2]<<7) + (twokeys[3]);
  *key2 = (twokeys[4]<<21) + (twokeys[5]<<14) + (twokeys[6]<<7) + (twokeys[7]);

}

// Returns the integer value of a specified subsequence of 32 bits
// width is the number of bits to be extracted
// index * width is the index of the rightmost bit to extract
unsigned int get_n_bits (unsigned bits, int width, int power) {

  int i = 0;
  int powCount = 6;
  int arrayCount = 1;
  unsigned int toReturn = 0;
  int bitArray[8];
  bitArray[0] = 0;

  for(i = power - 1; i >= power - width; i--) {
    if((bits & (unsigned int)(pow(2, i))) != 0) {
      bitArray[arrayCount] = (int)pow(2, powCount);
    } else {
      bitArray[arrayCount] = 0;
    }
    arrayCount++;
    powCount--;
  }

  for(i = 0; i < 8; i++) {
    toReturn += bitArray[i];
  }

  return toReturn;

}


// Given a sequence of 7 bits, rotate 3 bits to the left
unsigned int rotate_left3 (unsigned bits, int power) {

  unsigned int temp = bits;
  int i = 0;

  temp = zeroBits(temp, power, SEPTET);

  temp = (temp<<3)|(temp>>4);

  temp = zeroBits(temp, power, SEPTET);

  for(i = power-1; i >= power - SEPTET; i--) {
    if((bits & (unsigned)(pow(2, i))) != 0) {
      bits -= pow(2, i);
    }
  }

  bits = bits | temp;

	return bits;

}

// shuffle the 7 nibbles according to the pattern
unsigned int shuffle_nibbles (unsigned bits) {

  unsigned int nibbles[6] = {bits, bits, bits, bits, bits, bits};
  int i = 0;
  int shifter = 4;

  bits = zeroBits(bits, 4, NIBBLE);

  bits = bits<<24;

  for(i = 0; i <= 5; i++) {
    nibbles[i] = zeroBits(nibbles[i], shifter * 2, NIBBLE);
    shifter += 2;
  }

  nibbles[0] = nibbles[0]<<16;
  nibbles[1] = nibbles[1]<<8;
  nibbles[2] = nibbles[2]>>12;
  nibbles[3] = nibbles[3]>>8;
  nibbles[4] = nibbles[4]>>16;
  nibbles[5] = nibbles[5]>>12;

  for(i = 0; i <= 5; i++) {
    bits = bits | nibbles[i];
  }

  return bits;

}

// decode a block of 28 bits
void decode_28bits (unsigned int cipher, char *plain, unsigned int key1, unsigned int key2) {

  int i = 0;

  cipher = cipher ^ key2;

  cipher = shuffle_nibbles(cipher);

  cipher = cipher ^ key1;

  for(i = 1; i <= 4; i++) {
    cipher = rotate_left3(cipher, (i * 7));
  }

  for(i = 1; i <= 4; i++) {
    plain[i-1] = get_n_bits(cipher, SEPTET, (i * 7));
  }

  for(i = 0; i < 4; i++) {
    if(plain[i] == '\0') {
      plain[i] = ' ';
    }
  }

  plain = strrev(plain);

}

int main(int argc, char *argv[]) {

	char line[8];
	unsigned int bits = 0;
	unsigned int key1, key2;
	char plain[10000];
  char *str = argv[1];
  int length = 0;

  if(argc < 2) {printf("Not enough arguments!\n"); return 0;}
  if(argc > 2) {printf("Too many arguments!\n"); return 0;}
  while(str[length] != '\0') length++;

  if(length != 8) {
    puts("Key must be 8 characters long");
    return 0;
  }

	get_keys(argv[1], &key1, &key2);


	while (fgets(line, 8, stdin)) {

    if(line[0] == '\n') continue;

		sscanf(line, "%x", &bits);

		decode_28bits (bits, plain, key1, key2);

    printf("%s", plain);

	}
  return 1;
}
