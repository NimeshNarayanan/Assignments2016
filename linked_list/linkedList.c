#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

LinkedList createList(void){
  LinkedList link_list;
  link_list.first = link_list.last = NULL;
  link_list.length = 0;
  return link_list;
};

int add_to_list(LinkedList * linked_list,void *value){
  Element *e = (Element *)malloc(sizeof(Element));
  e->value = value;
  e->next = NULL;
  if (linked_list->length == 0) {
    linked_list->first = linked_list->last = e;
  }
  else{
    linked_list->last->next = e;
    linked_list->last = e;
  }
  linked_list->length++;
  return 0;
};

void *get_first_element(LinkedList list){
  return list.first->value;
};
