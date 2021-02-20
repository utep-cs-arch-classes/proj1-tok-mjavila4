#include <stdio.h>
#include "tokenizer.h"

#define LIMIT 100
char arr[LIMIT];

void main(){

  int i = 0;

  for(char input_char; (input_char = getchar()) != '\n' && i < LIMIT; i++){

    arr[i] = input_char;
    putchar(input_char);

  }

  printf("\n");
  
}
