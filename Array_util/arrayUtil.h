typedef struct ArrayUtil{
  int *base;
  int typeSize;
  int length;
}ArrayUtil;
typedef int (MatchFunc)(void *, void *);
void * findFirst(ArrayUtil, MatchFunc *, void *);
void * findLast(ArrayUtil, MatchFunc *, void *);
ArrayUtil create(int,int);
int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil resize(ArrayUtil,int);
void insertElement(ArrayUtil *,void *);
int findIndex(ArrayUtil, void *);
void dispose(ArrayUtil);
int count(ArrayUtil util, MatchFunc* match, void* hint);
// int isEven(void *, void *);
// int isDivisible(void* hint, void* item);
