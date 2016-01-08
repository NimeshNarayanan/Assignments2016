#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_Create_creates_array_with_given_typeSize_and_length(){
  ArrayUtil array;
  array = create(8,5);
  assert(array.typeSize == 8);
  assert(array.length == 5);
  dispose(array);
};
void test_areEqual_campare_given_arrays_and_return_one_or_zero(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil arr2 = create(8,4);
  assert(areEqual(arr1,arr2) == 1);
  dispose(arr1);
};
void test_areEqual_campare_given_deferent_arrays_and_return_zero(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil arr2 = create(8,8);
  assert(areEqual(arr1,arr2) == 0);
  dispose(arr1);
};
void test_resize_resize_given_array_by_given_size_is_less_than_it_size_and_return_resized_array(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil resized_array = resize(arr1,2);
  assert(resized_array.length == 2);
  dispose(arr1);
};
void test_resize_resize_given_array_by_given_size_is_greater_than_it_size_and_return_resized_array(){
  ArrayUtil arr1 = create(8,4);
  ArrayUtil resized_array = resize(arr1,6);
  assert(resized_array.length == 6);
  dispose(arr1);
};
void test_find_index_returns_the_index_of_given_element(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);

  int element = 2;
  int intex = findIndex(util,&element);
  assert(intex == 1);
  dispose(util);

};
void test_findIndex_returns_minus_one_for_index_of_given_element_if_the_element_not_in_the_array(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);
  // int *base = util.base;
  //
  // for (int i = 0; i < util.length; i++) {
  //   printf("============ %d\n",base[i] );
  // }
  int element = 5;
  int intex = findIndex(util,&element);
  assert(intex == -1);
  dispose(util);
};
void test_dispose_free_the_memory_allocated_for_array(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);
  dispose(util);
  // printf("in dispose\n");

};
void test_findFirst_return_first_element_which_matches(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  int hint = 2;
  insertElement(&util,elements);
  int *element = findFirst(util,isEven,NULL);
  // printf("%p %p\n",util.base, element );
  assert(*element == 2);
  dispose(util);
  // printf("in firsr find first\n");

};
void test_findFirst_return_first_divisible_element_which_matches_from_the_array(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  int hint = 2;
  insertElement(&util,elements);
  int *element = findFirst(util,isDivisible,&hint);
  // printf("%p %d\n",util.base, *element );
  assert(*element == 2);
  // printf("test_findFirst_return_first_divisible_element_which_matches_from_the_array\n\n");
  dispose(util);
};
void test_findFirst_return_null_when_non_matches_element_given(){
  ArrayUtil util = create(4,4);
  int elements[] ={8,2,10,4};
  int hint = 3;
  insertElement(&util,elements);
  int *element = findFirst(util,isDivisible,&hint);
  assert(element == NULL);
  dispose(util);
  // printf("test_findFirst_return_null_when_non_matches_element_given\n");

};
void test_findFirst_return_null_element_not_matches(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,3,3,5};
  insertElement(&util,elements);
  int *element = findFirst(util,isEven,NULL);
  assert(element == NULL);
  dispose(util);
};
void test_findLast_return_first_element_which_matches(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);
  int *element = findLast(util,isEven,NULL);
  assert(*element == 4);
  dispose(util);
};
void test_findLast_return_null_element_not_matches(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,5,3,9};
  insertElement(&util,elements);
  void *element = findLast(util,isEven,NULL);
  assert(element == NULL);
  dispose(util);
};

void test_count_return_the_count_of_match_of_elements(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,2,3,4};
  insertElement(&util,elements);
  int elem_count = count(util,isEven,NULL);
  assert(elem_count == 2);
};
void test_count_return_the_count_zero_when_no_match_of_elements_found(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,5,3,7};
  insertElement(&util,elements);
  int elem_count = count(util,isEven,NULL);
  assert(elem_count == 0);
};
void test_filter_filter_the_given_array_depends_on_the_matches_and_returns(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,4,2,6};
  insertElement(&util,elements);
  int expected_array[3]={4,2,6};
  ArrayUtil util1 = create(8,3);
  int count = filter(util,isEven,NULL,util1.base,util1.length);
  int **ut = util1.base;
  for (int i = 0; i < count; i++) {
    // printf("============ %d\n",**ut++ );
    assert(**(ut+i) == expected_array[i]);
  }
};
void test_filter_filter_the_given_array_depends_on_the_matches_and_returns_0(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,3,5,7};
  insertElement(&util,elements);
  void *util1[3];
  int count = filter(util,isEven,NULL,util1,util.length);
  assert(count == 0);
};

void test_filter_filter_the_given_array_depends_on_divisible_matches_and_returns_count(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,4,2,6};
  insertElement(&util,elements);
  int expected_array[3]={4,2,6};
  ArrayUtil util1 = create(8,3);
  int hint = 2;
  int count = filter(util,isDivisible,&hint,util1.base,util1.length);
  int **ut = util1.base;
  for (int i = 0; i < count; i++) {
    // printf("============ %d\n",**ut++ );
    assert(**(ut+i) == expected_array[i]);
  }
};
void test_filter_filter_the_given_array_depends_on_divisible_matches_and_returns_0(){
  ArrayUtil util = create(4,4);
  int elements[] ={1,3,5,7};
  insertElement(&util,elements);
  void *util1[3];
  int hint = 2;
  int count = filter(util,isDivisible,&hint,util1,util.length);
  assert(count == 0);
};
///////////map////////
void test_map_maps_source_to_destination_using_the_provided_convert_function(){
  ArrayUtil source = create(4,5);
  ArrayUtil destination = create(4,5);
  ArrayUtil expected_array = create(4,5);
  int arr[] ={1,7,9,7,1};
  insertElement(&expected_array,arr);
  int elements[] ={1,6,8,7,1};
  insertElement(&source,elements);
  map(source,destination,change_to_odd,NULL);
  int *dest = destination.base;
  int *expect = expected_array.base;
  // for (size_t i = 0; i < destination.length; i++) {
  //   printf("%d  ==  %d\n",dest[i], expect[i] );
  // }
  assert(areEqual(expected_array,destination)==1);

};

void test_forEach_performs_operation_on_all_items_in_the_array(){
  ArrayUtil source = create(4,5);
  int elements[] ={1,6,8,7,1};
  insertElement(&source,elements);
  ArrayUtil expected_array = create(4,5);
  int arr[] ={2,7,9,8,2};
  insertElement(&expected_array,arr);

  forEach(source,addOne,NULL);
  int *dest = source.base;
  int *expect = expected_array.base;
  // for (size_t i = 0; i < source.length; i++) {
  //   printf("%d  ==  %d\n",dest[i], expect[i] );
  // }
  assert(areEqual(expected_array,source)==1);
};

void test_forEach_performs_operation_on_all_items_in_the_array_with_given_value(){
  ArrayUtil source = create(4,5);
  int elements[] ={1,6,8,7,1};
  insertElement(&source,elements);
  ArrayUtil expected_array = create(4,5);
  int arr[] ={3,8,10,9,3};
  insertElement(&expected_array,arr);
  int no = 2;
  forEach(source,add_given_value,&no);
  int *dest = source.base;
  int *expect = expected_array.base;
  // for (size_t i = 0; i < source.length; i++) {
  //   printf("%d  ==  %d\n",dest[i], expect[i] );
  // }
  assert(areEqual(expected_array,source)==1);
};

/////////reduce//////////////
void test_reduce_returns_the_reduces_array_by_a_condition_and_return_the_answer(){
  ArrayUtil util = create(4,5);
  int elements[] ={1,6,8,7,4};
  insertElement(&util,elements);
  int initialValue = 0;
  int value = *(int*)reduce(util,isGreater,NULL,&initialValue);
  assert(value == 8);
};

void test_reduce_returns_the_initialValue__by_a_condition_if_there_is_no_matching_element(){
  ArrayUtil util = create(4,5);
  int elements[] ={1,6,8,7,4};
  insertElement(&util,elements);
  int initialValue = 9;
  int value = *(int*)reduce(util,isGreater,NULL,&initialValue);
  assert(value == 9);
};

int main(void){
  test_Create_creates_array_with_given_typeSize_and_length();
  test_areEqual_campare_given_arrays_and_return_one_or_zero();
  test_areEqual_campare_given_deferent_arrays_and_return_zero();
  test_resize_resize_given_array_by_given_size_is_less_than_it_size_and_return_resized_array();
  test_resize_resize_given_array_by_given_size_is_greater_than_it_size_and_return_resized_array();
  test_find_index_returns_the_index_of_given_element();
  test_findIndex_returns_minus_one_for_index_of_given_element_if_the_element_not_in_the_array();
  test_dispose_free_the_memory_allocated_for_array();
  test_findFirst_return_first_element_which_matches();
  test_findFirst_return_first_divisible_element_which_matches_from_the_array();
  test_findFirst_return_null_element_not_matches();
  test_findLast_return_first_element_which_matches();
  test_findLast_return_null_element_not_matches();
  test_count_return_the_count_of_match_of_elements();
  test_count_return_the_count_zero_when_no_match_of_elements_found();
  test_findFirst_return_null_when_non_matches_element_given();
  test_filter_filter_the_given_array_depends_on_the_matches_and_returns();
  test_filter_filter_the_given_array_depends_on_the_matches_and_returns_0();
  test_filter_filter_the_given_array_depends_on_divisible_matches_and_returns_count();
  test_filter_filter_the_given_array_depends_on_divisible_matches_and_returns_0();
  test_map_maps_source_to_destination_using_the_provided_convert_function();
  test_forEach_performs_operation_on_all_items_in_the_array();
  test_forEach_performs_operation_on_all_items_in_the_array_with_given_value();
  test_reduce_returns_the_reduces_array_by_a_condition_and_return_the_answer();
  test_reduce_returns_the_initialValue__by_a_condition_if_there_is_no_matching_element();
  return 0;
}
