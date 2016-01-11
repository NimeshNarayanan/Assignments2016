#include <stdio.h>
#include "linkedList.h"
#include "assert.h"

void test_create_list_create_an_empty_LinkedList_structure(){
  LinkedList link_list = createList();
  assert(link_list.first == NULL);
  assert(link_list.last == NULL);
};
