#include <stdio.h>
#include "tokenizer.h"

#define LIMIT 99

void main(){
  
  int i;
  char c;
  char input[LIMIT];

  for(i = 0; (c = getchar()) != '\n' && i < LIMIT; i++){
    input[i] = c;
  }
  input[i] = '\0';
  
}

int space_char(char c){
  if(c == ' ' || c == '\n' || c == '\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c == ' ' || c == '\n' || c == '\t'){
    return 0;
  }
  return 1;
}
