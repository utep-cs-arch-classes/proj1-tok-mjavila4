#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history(){
  List *list = (List*)malloc(sizeof(List)*1);
  list->root = (Item*)malloc(sizeof(Item));
  list->root->next = NULL;
  return list;
}

void add_history(List *list, char *str){
  int i = 0;

  Item *ptr = list->root;
  Item *temp = (Item*)malloc(sizeof(Item));

  temp->str = str;
  temp->next = NULL;

  while(ptr->next != NULL){
    ptr = ptr->next;
    i++;
  }
  temp->id = i;
  ptr->next = temp;
}

char *get_history(List *list, int id){
  Item *ptr = list->root->next;
  while(ptr->next != NULL){
    if(ptr->id == id){
      break;
    }
    ptr = ptr->next;
  }
  return ptr->str;
}

void print_history(List *list){
  Item *ptr = list->root->next;
  while(ptr != NULL){
    printf("%d: %s\n", ptr->id, ptr->str);
    ptr = ptr->next;
  }
}

void free_history(List *list){
  Item *ptr = list->root->next;
  Item *prev = list->root->next;
  while(ptr != NULL){
    prev = ptr;
    ptr = ptr->next;
    free(prev);
  }
  free(ptr);
  free(list->root);
  free(list);
}
