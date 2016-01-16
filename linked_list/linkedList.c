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

////////////////indexOf///////////////////////////

int indexOf(LinkedList list, void * value) {
	Element *temp = list.first;
	for (int i = 0; i < list.length; ++i){
		if(temp->value == value)
			return i;
		temp = temp->next;
	}
	return -1;
};

///////////////////deleteElementAt////////////////

void * deleteElementAt(LinkedList *list, int position){
  Element * elem = list->first;
  void * del_elem;
  Element * prev_elem = (Element *)malloc(sizeof(Element));
  if(position<2){
    del_elem = elem->value;
    free(elem);
  };
  for (size_t i = 1; i <= position; i++) {
    if(position == i){
      del_elem = elem->value;
      free(elem);
      list->length --;
      prev_elem->next = elem->next;
    }
    prev_elem = elem;
    elem = elem->next;
  }
  return del_elem;
};

//////////////////////ASARRAY///////////////////

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

///////////////////FILTER///////////////////////
LinkedList filter(LinkedList list, MatchFunc *matcher,void *hint){
  LinkedList newList = createList();
  Element *elem = list.first;
  while(elem != NULL) {
    if(matcher(hint,elem->value))
      add_to_list(&newList,elem->value);
    elem = elem->next;
  }
  return newList;
};

/////////////////reverse/////////////////////

LinkedList reverse(LinkedList list){
  Element *elem = list.first;
  LinkedList rev_list = createList();
  int count = list.length;
  while (elem != NULL && count >= 1) {
    add_to_list(&rev_list,getElementAt(list,count));
    elem = elem->next;
    count --;
  }
  return rev_list;
};

/////////////MAP///////////////////////////


LinkedList map(LinkedList list, ConvertFunc match, void * hint){
  LinkedList new_list = createList();
  Element *elem = list.first;
  while (elem !=NULL) {
    void * destination = malloc(sizeof(void*));
    match(hint,elem->value,destination);
    if(*(int*)destination != 0){
      add_to_list(&new_list,destination);
    }
    elem = elem->next;
  }
return new_list;
};

//////////////////reducer///////////////////

void *reduce(LinkedList list, Reducer * match, void * hint, void *initialValue){
  Element *elem = list.first;
  while (elem !=NULL) {
    initialValue = match(hint,initialValue,elem->value);
    elem = elem->next;
  }
  return initialValue;
};
