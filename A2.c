int main(int argc, char *argv[]) {
  
    char wordlist[MAX_WORDS][MAX_WORD_LEN];
    
    FILE *input = fopen(argv[1], "r");
    
    
    for (int i = 0; i < sizeof(input); i++) {
      fgets(wordlist[i], MAX_WORD_LEN, input);

    }
  char word[MAX_WORD_LEN];
  fgets(word, MAX_WORD_LEN, stdin);

}
