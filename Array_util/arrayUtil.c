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

int isEven(void *hint,void *item){
  if(*(int*)item % 2 == 0)
    return 1;
  return 0;
};
int isDivisible(void * hint, void * item){
  if(*(int*)item % *(int*)hint == 0)
    return 1;
  return 0;
};

int areEqual(ArrayUtil arr,ArrayUtil arr1){
  if(arr.length == arr1.length && arr.typeSize == arr1.typeSize){
    return memcmp(arr.base, arr1.base, arr.typeSize*arr.length)==0;
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
  for (int i = 0; i < util.length; i++) {
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
  for (int i = 0; i < util.length; i++, base+=util.typeSize) {
    if(match(hint,base)==1){
      return base;
    }
  }
  return NULL;
};
void *findLast(ArrayUtil util, MatchFunc *match, void *hint){
  for (int i = util.length-1; i >= 0  ; i--){
    void * base = util.base+(i*util.typeSize);
    if(match(hint,base)==1)
      return base;
  }
  return NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
  void * base = util.base;
  int count = 0;
  for (int i = 0; i < util.length; i++, base+=util.typeSize)
    if(match(hint,base)==1)
      count++;
  return count;
};
////////filter////////////////
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
  int lenght = 0;
  for (int i = 0; i < util.length; i++){
    void * base = util.base+(i*util.typeSize);
    if(match(hint,base)==1){
      destination[lenght] = base;
      lenght++;
    }
    if(lenght == maxItems)return lenght;
  }
  return lenght;
};

///////////////map/////////////
void change_to_odd(void* hint, void* sourceItem, void* destinationItem){
  if(*(int*)sourceItem %2 ==0)
    *(int*)destinationItem = (*(int*)sourceItem)+1;
  else
    *(int *)destinationItem = *(int *)sourceItem;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
  void *src_base = source.base;
  void *dest_base = destination.base;
  for (size_t i = 0; i < source.length; i++) {
    convert(NULL,src_base,dest_base);
    src_base+=source.typeSize;
    dest_base+=source.typeSize;
  }
};

////////////foreach///////////////

void addOne(void* hint, void* item){
  *(int*)item += 1;
};

void add_given_value(void* hint, void* item){
  *(int*)item += *(int*)hint;
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
  void *base = util.base;
  for (size_t i = 0; i < util.length; i++) {
    operation(hint,base);
    base+=util.typeSize;
  };
};

///////////reduce///////////////
void isGreater(void* hint, void* previousItem, void* item){
  if(*(int *)previousItem < *(int *)item)
    *(int *)previousItem = *(int *)item;
};

void *reduce(ArrayUtil util, ReducerFunc * reducer, void * hint, void * intialValue){
  void *base = util.base;
  void *previousvalue = (void *)calloc(1,util.typeSize);
  previousvalue = intialValue;
  for (size_t i = 0; i <util.length ; i++) {
    reducer(hint,previousvalue,base+(util.typeSize*i));
  }
  return previousvalue;
};
