#include <stdio.h>
#include <assert.h>
#include "arrayUtil.h"

void test_give_array_with_typeSize_length(){
  ArrayUtil array;
  array = create(8,5);
  assert(array.typeSize == 8);
  assert(array.length == 5);
};
int main(void){
  test_give_array_with_typeSize_length();
};
