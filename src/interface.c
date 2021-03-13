#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define LIMIT 100

void main(){
  
  int i;
  char c;
  char *input = (char*)malloc(sizeof(char)*LIMIT);

  for(i = 0; (c = getchar()) != '\n' && i < LIMIT-1; i++){
    *(input+i) = c;
  }
  *(input+i) = '\0';

  char **tokens = tokenize(input);
  print_tokens(tokens);
  
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
  int i;
  for(i = 0; *(str+i) != '\0'; i++){
    if(space_char(*(str+i))){break;}
  }
  return str+i;
}

int count_words(char *str){
  char *end = str;
  char *start;
  int i;
  for(i = 0; (start = word_start(end)) != 0; i++){
    end = word_end(start);
  }
  return i;
}

char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc(sizeof(char)*len+1);
  int i;
  for(i = 0; i<len; i++){
    *(copy+i) = *(inStr+i);
  }
  *(copy+i) = '\0';
  return copy;
}

char **tokenize(char* str){
  int word_count = count_words(str);
  int i,j;
  char **tokens = (char**)malloc(sizeof(char*)*word_count+1);
  char *end = str;
  char *start;

  for(i = 0; i < word_count; i++){

    start = word_start(end);
    end = word_end(start);

    for(j = 0; start+j != end; j++){}
    tokens[i] = copy_str(start,j);
    
  }

  tokens[i] = 0;

  return tokens;
  
}

void print_tokens(char **tokens){
  for(int i = 0; tokens[i] != 0; i++){
    printf("Token %d: %s\n",i,tokens[i]);
  }
}

void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens[i]);
  free(tokens);
}
