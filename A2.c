int main(int argc, char *argv[]) {
  // need to take input and make it all lower cases
  // so can later be compared

  //  if(strlen(argv) < 2){
  //    printf("Format of Command is as followed : ./Assignment2 wordlist.txt ");
  //    return 0;
  //  }

    char wordlist[MAX_WORDS][MAX_WORD_LEN];
    
    FILE *input = fopen(argv[1], "r");
    
    
    for (int i = 0; i < sizeof(input); i++) {
      fgets(wordlist[i], MAX_WORD_LEN, input);

    }

//  }
  //get word from user
  char word[MAX_WORD_LEN];
  fgets(word, MAX_WORD_LEN, stdin);

  //fillWordArray( wordlist);
}
