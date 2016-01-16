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

////////////////////add_to_list////////////////

void test_add_to_list_receive_reference_to_some_data_and_add_it_to_the_end_of_the_list(){
  LinkedList linked_list = createList();
  int number = 10;
  add_to_list(&linked_list,&number);
  int value = *(int*)linked_list.first->value;
  assert(value == 10);
};
void test_send_character_data_as_a_reference_and_add_it_to_the_end_of_the_list(){
  LinkedList linked_list = createList();
  char value = 'a';
  add_to_list(&linked_list,&value);
  char character = *(char*)linked_list.first->value;
  assert(character == 'a');
};
void test_send_float_data_as_a_reference_and_add_it_to_the_end_of_the_list(){
  LinkedList linked_list = createList();
  float value = 1.8,no=1.8;
  add_to_list(&linked_list,&value);
  float number = *(float*)linked_list.first->value;
  assert(number == no);
};

/////////////////////get_first_element /////////////////

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
  assert(index == 2);
};
void test_indexOf_return_the_index_of_the_specific_value_as_1_if_it_is_not_found(){
  LinkedList list = createList();
  int no = 6;
  int arr[4]={1,2,3,4};
  for (size_t i = 0; i < 4; i++) {
    add_to_list(&list,&arr[i]);
  }
  int index = indexOf(list,&no);
  assert(index == -1);
};
void test_deleteElementAt_delete_element_at_a_specific_position_and_return_it(){
  LinkedList list = createList();
  int no = 3;
  int arr[5]={1,2,6,4,7};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  int value = *(int*)deleteElementAt(&list,no);
  assert(value == 6);
};

///////////asArray//////////////

void test_asArray_populate_the_array_we_passed_with_all_the_elements_of_the_list_we_passed_and_return_the_number_of_elememnts_added_to_the_array(){
  LinkedList list = createList();
  int no = 3;
  int arr[5]={1,2,6,4,7};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  void * array = (void *)calloc(3,8);
  int no_of_elements = asArray(list,array,no);
  assert(no_of_elements == 3);
};

void test_asArray_populate_the_array_we_passed_with_all_the_elements_of_the_list_we_passed_and_return_the_number_of_elememnts_added_to_the_array_as_the_length_of_list_if_the_array_length_is_greater(){
  LinkedList list = createList();
  int arr[5]={1,2,6,4,7};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  void * array = (void *)calloc(6,8);
  int no_of_elements = asArray(list,array,6);
  assert(no_of_elements == 5);
};
void test_asArray_populate_the_array_we_passed_with_all_the_elements_of_character_list_we_passed_and_return_the_number_of_elememnts_added_to_the_array_as_the_length_of_list_if_the_array_length_is_greater(){
  LinkedList list = createList();
  char arr[5]={'a','b','c','d','e'};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  void * array = (void *)calloc(6,8);
  int no_of_elements = asArray(list,array,6);
  assert(no_of_elements == 5);
};
void test_asArray_populate_the_array_we_passed_with_all_the_elements_of_float_number_list_we_passed_and_return_the_number_of_elememnts_added_to_the_array_as_the_length_of_list_if_the_array_length_is_greater(){
  LinkedList list = createList();
  float arr[5]={1.2,2.2,3.3,4.1,9.2};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  void * array = (void *)calloc(6,8);
  int no_of_elements = asArray(list,array,6);
  assert(no_of_elements == 5);
};

////////filter//////////
int isOdd(void* hint, void* item){
  // printf("it is here.------\n" );
  if(*(int*)item % 2 != 0 )
    return 1;
  return 0;
};
int isDivisible(void* hint, void* item){
  if(*(int*)item % *(int*)hint == 0 )
    return 1;
  return 0;
};
int isCapitalLetter(void* hint, void* Item){
  if(*(char*)Item <91 && *(char*)Item>64)
    return 1;
  return 0;
};
int isLessThanFive(void* hint, void* item){
  // printf("it is here.------\n" );
  if(*(int*)item < 5 )
    return 1;
  return 0;
};


void test_filter_will_filter_the_original_list_and_return_a_new_LinkedList_that_consists_only_of_references_to_data_that_satisfy_the_isodd_condition(){
  LinkedList list = createList();
  int arr[5]={1,2,3,4,7};
  int expected[3] = {1,3,7};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = filter(list,isOdd,NULL);
  Element *head = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(*(int*)head->value == expected[i]);
    head = head->next;
  }
};

void test_filter_will_filter_the_original_list_of_float_mnumbers_and_return_a_new_LinkedList_that_consists_only_of_references_to_data_that_satisfy_the_isLessThanFive_condition(){
  LinkedList list = createList();
  float arr[5]={1.2,2.3,6.2,7.4,8.7};
  float expected[3]={6.2,7.4,8.7};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = filter(list,isLessThanFive,NULL);
  Element *head = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(*(float*)head->value == expected[i]);
    head = head->next;
  }
};

void test_filter_will_filter_the_original_list_and_return_a_new_LinkedList_that_consists_only_of_references_to_data_that_satisfy_the_is_divisible_condition(){
  LinkedList list = createList();
  int arr[5]={1,2,6,4,7};
  int hint = 2;
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = filter(list,isDivisible,&hint);
  int head = *(int*)filtered_list.first->value;
  int tail = *(int*)filtered_list.last->value;
  assert(head == 2);
  assert(tail == 4);
};

void test_filter_will_filter_the_original_alphabetical_list_and_return_a_new_LinkedList_that_consists_only_of_references_to_data_that_satisfy_the_iscapitalLetter_condition(){
  LinkedList list = createList();
  char arr[5]={'A','D','j','K','o'};
  char expected[3] = {'A','D','K'};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = filter(list,isCapitalLetter,NULL);
  Element *head = filtered_list.first;
  // int tail = *(int*)filtered_list.last->value;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(*(char*)head->value == expected[i]);
    head = head->next;
  }
};
/////////////////reverse//////////////////////////////

void test_reverse_This_function_will_take_a_LinkedList_as_an_argument_and_return_a_LinkedList_with_the_order_of_the_elements_of_the_source_LinkedList_reversed(){
  LinkedList list = createList();
  int arr[5]={1,2,6,4,7};
  int array[5]={7,4,6,2,1};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = reverse(list);
  Element *elem = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(*(int*)elem->value == array[i]);
    elem = elem->next;
  }
};
void test_reverse_This_function_will_take_a_LinkedList_of_characters_as_an_argument_and_return_a_LinkedList_with_the_order_of_the_elements_of_the_source_LinkedList_reversed(){
  LinkedList list = createList();
  char arr[5]={'a','s','d','f','g'};
  char array[5]={'g','f','d','s','a'};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = reverse(list);
  Element *elem = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(*(char*)elem->value == array[i]);
    elem = elem->next;
  }
};
void test_reverse_This_function_will_take_a_LinkedList_of_floated_no_as_an_argument_and_return_a_LinkedList_with_the_order_of_the_elements_of_the_source_LinkedList_reversed(){
  LinkedList list = createList();
  float arr[5]={1.2,2.1,6.3,4.4,7.5};
  float array[5]={7.5,4.4,6.3,2.1,1.2};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = reverse(list);
  Element *elem = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(*(float*)elem->value == array[i]);
    elem = elem->next;
  }
};
/////////////////////////MAP///////////////////////////
void change_to_even(void* hint, void* sourceItem, void* destinationItem){
  int value = *(int*)sourceItem;
  if(value % 2 == 0)
    *(int*)destinationItem = value;
  else
    *(int*)destinationItem = value+1;
};
void isDivisibleby(void* hint, void* sourceItem, void* destinationItem){
  int value = *(int*)sourceItem;
  if(value % *(int*)hint == 0)
    *(int*)destinationItem = value;
};
void changeToCapital(void* hint, void* sourceItem, void* destinationItem){
  if(*(char*)sourceItem <91 && *(char*)sourceItem>64)
    *(int*)destinationItem = *(char*)sourceItem;
  else if(*(char*)sourceItem >96 && *(char*)sourceItem<123)
    *(int*)destinationItem = *(int*)sourceItem-32;
};

void test_map_function_receive_one_linked_list_and_map_to_a_function_it_will_create_new_list_return_it(){
  LinkedList list = createList();
  int arr[5]={1,3,6,5,9};
  // int hint = 2;
  int array[5]={2,4,6,6,10};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = map(list,change_to_even,NULL);
  Element * elem = filtered_list.first;
  for (size_t i = 0; i < 5; i++) {
    assert(array[i] == *(int*)elem->value);
    elem = elem->next;
  }
};
void test_map_function_receive_one_linked_list_and_map_to_function_isDivisilble_and_it_will_create_new_list_with_the_elements_matching_the_criteria_return_it(){
  LinkedList list = createList();
  int arr[5]={4,3,6,5,10};
  int hint = 2;
  int array[5]={4,6,10};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = map(list,isDivisibleby,&hint);
  Element * elem = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(array[i] == *(int*)elem->value);
    elem = elem->next;
  }
};

void test_map_function_receive_one_linked_list_and_map_to_function_isCapital_and_it_will_create_new_list_with_the_elements_matching_the_criteria_return_it(){
  LinkedList list = createList();
  int arr[5]={'A','b','C','f','R'};
  int hint = 2;
  int array[5]={'A','B','C','F','R'};
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  LinkedList filtered_list = map(list,changeToCapital,&hint);
  Element * elem = filtered_list.first;
  for (size_t i = 0; i < filtered_list.length; i++) {
    assert(array[i] == *(int*)elem->value);
    elem = elem->next;
  }
};

//////////////////// Reduce //////////////////////////////
void *getGreaterNo(void* hint, void* previousItem, void* item){
  if(*(int*)previousItem >*(int*)item)
    return previousItem;
  return item;
};
void *getGreaterCharacter(void* hint, void* previousItem, void* item){
  if(*(char*)previousItem >*(char*)item)
    return previousItem;
  return item;
};


void test_reduce_reduce_the_given_list_and_return_the_value_it_satisfy_the_maching_criteria(){
  LinkedList list = createList();
  int arr[5]={1,3,6,5,9};
  int initialValue = 0;
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  int value = *(int*)reduce(list,getGreaterNo,NULL,&initialValue);
  assert(value == 9);
};
void test_reduce_the_given_list_of_characters_and_return_the_value_it_satisfy_the_maching_criteria(){
  LinkedList list = createList();
  char arr[5]={'a','A','p','q','Z'};
  char initialValue = 'a';
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  char value = *(char*)reduce(list,getGreaterCharacter,NULL,&initialValue);
  assert(value == 'q');
};
void test_reduce_the_given_list_of_float_numbers_and_return_the_value_it_satisfy_the_maching_criteria(){
  LinkedList list = createList();
  float arr[5]={1.3,3.3,6.9,9.9,9.8};
  float initialValue = 0,no = 9.9;
  for (size_t i = 0; i < 5; i++) {
    add_to_list(&list,&arr[i]);
  }
  float value = *(float*)reduce(list,getGreaterNo,NULL,&initialValue);
  assert(value == no);
  };
