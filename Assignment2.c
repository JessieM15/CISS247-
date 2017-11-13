#define MAX_WORD_LEN 40
#define MAX_WORDS 110000

//declare array 110k long each with 40 characters
char wordlist[MAX_WORDS][MAX_WORD_LEN];
//Then you can access the ith word in the list as wordlist[i].
void fillWordArray(fullArray []){
  for (int i = 0; i < sizeof(fullArray); i++) {
   if(fullArray [i] == '\n'){
     
   }

  }
}

int main(int argc, char *argv[]) {

  if(sizeof(argv) < 2){
    printf("Format of Command is as followed : ");
    return 0;
  }else{


  }
  FILE *input = fopen(argv[1], “r”);
  fgets(wordlist[i], MAX_WORD_LEN, input);
}
