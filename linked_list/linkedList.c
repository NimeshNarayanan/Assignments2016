#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
  LinkedList link_list;
  link_list.first = link_list.last = NULL;
  link_list.length = 0;
  return link_list;
};

// int add_to_list(LinkedList *,void *);
