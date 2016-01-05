typedef struct ArrayUtil{
  int *base;
  int typeSize;
  int length;
}ArrayUtil;

 ArrayUtil create(int,int);
 int areEqual(ArrayUtil,ArrayUtil);
 ArrayUtil resize(ArrayUtil,int);
 void insertElement(ArrayUtil *,void *);
 int findIndex(ArrayUtil, void *);
 void dispose(ArrayUtil);
