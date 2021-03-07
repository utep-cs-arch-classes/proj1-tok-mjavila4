#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define LIMIT 100

void main(){
  
  int i;
  char c;
  char *input = (char*)malloc(LIMIT);

  for(i = 0; (c = getchar()) != '\n' && i < LIMIT-1; i++){
    *(input+i) = c;
  }
  
  *(input+99) = '\0';

  printf("%s\n", input);

  printf("%s\n", copy_str(input, 5));
  
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

char *word_start(char *str){
  for(int i = 0; *(str+i) != '\0'; i++){
    if(non_space_char(*(str+i))){
      return str+i;
    }
  }
  return 0;
}

char *word_end(char *str){
  for(int i = 0; *(str+i) != '\0'; i++){
    if(space_char(*(str+i))){
      return str+i;
    }
  }
  return 0;
}

int count_words(char *str){
  int i = 0;
  char *start;

  for(i = 0; str && (start = word_start(str)) != 0; i++){
    str = word_end(start);
  }
  return i;
}

char *copy_str(char *inStr, short len){
  int i;
  char *copy = (char*)malloc(len+1);

  for(i = 0; i<len; i++){
    *(copy+i) = *(inStr+i);
  }
  *(copy+i) = '\0';
  return copy;
}











