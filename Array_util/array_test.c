#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_Create_creates_array_with_given_typeSize_and_length(){
  ArrayUtil array;
  array = create(8,5);
  assert(array.typeSize == 8);
  assert(array.length == 5);
};
void test_areEqual_campare_given_arrays_and_return_one_or_zero(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil arr2 = create(8,4);
  assert(areEqual(arr1,arr2) == 1);

};
void test_areEqual_campare_given_deferent_arrays_and_return_zero(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil arr2 = create(8,8);
  assert(areEqual(arr1,arr2) == 0);

};
void test_resize_resize_given_array_by_given_size_is_less_than_it_size_and_return_resized_array(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil resized_array = resize(arr1,2);
  assert(resized_array.length == 2);
}
void test_resize_resize_given_array_by_given_size_is_greater_than_it_size_and_return_resized_array(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil resized_array = resize(arr1,6);
  assert(resized_array.length == 10);
}
void test_find_index_returns_the_index_of_given_element(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);
  int element = 2;
  int intex = findIndex(util,&element);
  assert(intex == 1);
};
void test_findIndex_returns_minus_one_for_index_of_given_element_if_the_element_not_in_the_array(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);
  int element = 5;
  int intex = findIndex(util,&element);
  assert(intex == -1);
};
void test_dispose_free_the_memory_allocated_for_array(){
  ArrayUtil util = create(4,4);
  assert(util.base[0]!= 1);
};

int main(void){
test_Create_creates_array_with_given_typeSize_and_length();
test_areEqual_campare_given_arrays_and_return_one_or_zero();
test_resize_resize_given_array_by_given_size_is_less_than_it_size_and_return_resized_array();
test_find_index_returns_the_index_of_given_element();
test_findIndex_returns_minus_one_for_index_of_given_element_if_the_element_not_in_the_array();
test_dispose_free_the_memory_allocated_for_array();
return 0;
};
