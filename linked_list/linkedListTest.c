#include <stdio.h>
#include <string.h>
#include "linkedList.h"
#include "assert.h"

void test_create_list_create_an_empty_LinkedList_structure(){
  LinkedList link_list = createList();
  assert(link_list.first == NULL);
  assert(link_list.last == NULL);
};
void test_add_to_list_receive_reference_to_some_data_and_add_it_to_the_end_of_the_list(){
  LinkedList linked_list = createList();
  int number = 10;
  add_to_list(&linked_list,&number);
  int value = *(int*)linked_list.first->value;
  assert(value == 10);
};

void test_get_first_element_return_first_element_from_the_list(){
LinkedList linked_list = createList();
int number = 10;
add_to_list(&linked_list,&number);
int number1 = 20;
add_to_list(&linked_list,&number1);
int value = *(int*)get_first_element(linked_list);
assert(value == 10);
};

void test_get_last_element_return_last_element_from_the_list(){
LinkedList linked_list = createList();
int number = 10;
add_to_list(&linked_list,&number);
int number1 = 20;
add_to_list(&linked_list,&number1);
int value = *(int*)get_last_element(linked_list);
assert(value == 20);
};
int main(void) {
  test_create_list_create_an_empty_LinkedList_structure();
  test_add_to_list_receive_reference_to_some_data_and_add_it_to_the_end_of_the_list();
  test_get_first_element_return_first_element_from_the_list();
  test_get_last_element_return_last_element_from_the_list();
  return 0;
}
