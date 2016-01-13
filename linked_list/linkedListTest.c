#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void test_forEach_change_content_with_given_matching_function(){
  LinkedList linked_list = createList();
  int number = 10;
  add_to_list(&linked_list,&number);
  int number1 = 20;
  add_to_list(&linked_list,&number1);
  forEach(linked_list,increment);
  assert(*(int*)get_first_element(linked_list) == 11);
  assert(*(int*)get_last_element(linked_list) == 21);
};

void test_get_element_at_return_the_elemnt_at_specific_position(){
  LinkedList list = createList();
  int a = 1,b = 2,c = 3,d = 4;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  int value = *(int*)getElementAt(list,b);
  assert(value == 2);
};
void test_indexOf_return_the_index_of_the_specific_value(){
  LinkedList list = createList();
  int a = 1,b = 2,c = 3,d = 4;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  int index = indexOf(list,&c);
  assert(index == 3);
};
void test_indexOf_return_the_index_of_the_specific_value_as_1_if_it_is_not_found(){
  LinkedList list = createList();
  int a = 1,b = 2,c = 3,d = 4,no = 6;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  int index = indexOf(list,&no);
  assert(index == -1);
};
void test_deleteElementAt_delete_element_at_a_specific_position_and_return_it(){
  LinkedList list = createList();
  int a = 1,b = 2,c = 6,d = 4,e = 7,no = 3;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  add_to_list(&list,&e);
  int value = *(int*)deleteElementAt(&list,no);
  assert(value == 6);
};
void test_asArray_populate_the_array_we_passed_with_all_the_elements_of_the_list_we_passed_and_return_the_number_of_elememnts_added_to_the_array(){
  LinkedList list = createList();
  int a = 1,b = 2,c = 6,d = 4,e = 7,no = 3;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  add_to_list(&list,&e);
  void * array = (void *)calloc(3,8);
  int no_of_elements = asArray(list,array,no);
  assert(no_of_elements == 3);
};

void test_asArray_populate_the_array_we_passed_with_all_the_elements_of_the_list_we_passed_and_return_the_number_of_elememnts_added_to_the_array_as_the_length_of_list_if_the_array_length_is_greater(){
  LinkedList list = createList();
  int a = 1,b = 2,c = 6,d = 4,e = 7;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  add_to_list(&list,&e);
  void * array = (void *)calloc(6,8);
  int no_of_elements = asArray(list,array,6);
  assert(no_of_elements == 5);
};
