#include <stdlib.h>
#include <stdio.h>
#include "arrayUtil.h"
#include <string.h>

ArrayUtil create(int typeSize,int length){
  ArrayUtil arr;
  arr.base = (void *)calloc(length,typeSize);
  arr.typeSize = typeSize;
  arr.length = length;
  return arr;
};
int areEqual(ArrayUtil arr,ArrayUtil arr1){
  int status = 0;
  if(arr.length == arr1.length && arr.typeSize == arr1.typeSize){
    char *base1 = (char *)arr.base;
    char *base2 = (char *)arr1.base;
    for (size_t i = 0; i < arr.length*arr.typeSize; i++) {
      if(base1[i] != base2[i]) return 0;
    };
    return 1;
  };
  return 0;
};
ArrayUtil resize(ArrayUtil arr,int length){
  arr.base = (void *)realloc(arr.base,length);
  arr.length = length;
  return arr;
};

void insertElement(ArrayUtil * util,void * elements){
  void *base = util->base;
  for (int i = 0; i < util->length; i++) {
      memcpy(base+(util->typeSize*i), elements+(util->typeSize*i), util->typeSize);
  }
}
int findIndex(ArrayUtil util, void * element){
  void *base = util.base;
  for (int i = 0; i < util.length-1; i++) {
    if(memcmp(base+(util.typeSize*i), element, util.typeSize)==0)
      return i;
  }
  return -1;
};

void dispose(ArrayUtil util){
  free(util.base);
};


void *findFirst(ArrayUtil util, MatchFunc *match, void *hint){
  void * base = util.base;
  for (int i = 0; i < util.length-1; i++, base+=util.typeSize) {
    if(match(hint,base)==1){
      return base;
    }
  }
  return NULL;
};
void *findLast(ArrayUtil util, MatchFunc *match, void *hint){
  void * base = util.base;
  void *element;
  for (int i = 0; i < util.length-1; i++, base+=util.typeSize)
    if(match(hint,base)==1) element = base;
  return(element)?element:NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
  void * base = util.base;
  int count = 0;
  for (int i = 0; i < util.length-1; i++, base+=util.typeSize)
    if(match(hint,base)==1) count++;
  return count;
};
