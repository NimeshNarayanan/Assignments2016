#include <stdlib.h>
#include "arrayUtil.h"

ArrayUtil create(int typeSize,int length){
  ArrayUtil arr;
  arr.base = (void *)calloc(length,typeSize);
  arr.typeSize = typeSize;
  arr.length = length;
  return arr;
}
