#define MAX_WORD_LEN 40
#define MAX_WORDS 110000
char wordlist[MAX_WORDS][MAX_WORD_LEN];

void fillWordArray(fullArray []){
  for (int i = 0; i < sizeof(fullArray); i++) {
    /* code */
  }

}

int main(int argc, char *argv[]) {

  FILE *input = fopen(argv[1], “r”);
  //. . .
  fgets(wordlist[i], MAX_WORD_LEN, input);
  char word[MAX_WORD_LEN];
  fgets(word, MAX_WORD_LEN, stdin);
}
