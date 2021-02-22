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
