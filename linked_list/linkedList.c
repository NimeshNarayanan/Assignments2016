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
  if (linked_list->length == 0)
    linked_list->first = linked_list->last = e;
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
void *get_last_element(LinkedList list){
  return list.last->value;
};

void increment(void *value){
  *(int*)value+=1;
};
void forEach(LinkedList list, ElementProcessor e){
  Element *elem = list.first;
  for (size_t i = 0; i < list.length; i++) {
    e(elem->value);
    elem = elem->next;
  };
};

void * getElementAt(LinkedList list, int position ){
  Element *elem = list.first;
  void * value1 = NULL;
  for (size_t i = 1; i <= position; i++) {
    if(i == position)
      value1 = elem->value;
    elem = elem->next;
  }
  return value1;
};

int indexOf(LinkedList list, void * element){
  Element *elem = list.first;
  int index = -1;
  for (size_t i = 1; i <= list.length; i++) {
    if(element == elem->value)
      index = i;
    elem = elem->next;
  }
  return index;
};

void * deleteElementAt(LinkedList *list, int position){
  Element * elem = list->first;
  void * del_elem;
  Element * prev_elem = (Element *)malloc(sizeof(Element));
  if(position<2)free(list);
  for (size_t i = 1; i <= position; i++) {
    if(position == i){
      del_elem = elem->value;
      list->length --;
      prev_elem->next = elem->next;
    }
    prev_elem = elem;
    elem = elem->next;
  }
  return del_elem;
};

int asArray(LinkedList list, void **array, int maxElements){
  Element * elem = list.first;
  int count = 0;
  while(count < maxElements && elem !=NULL){
    *array = elem->value;
    count ++;
    array++;
    elem = elem->next;
  }
  return count;
};
