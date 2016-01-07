typedef struct ArrayUtil{
  void *base;
  int typeSize;
  int length;
}ArrayUtil;
typedef int (MatchFunc)(void *, void *);
typedef void (ConvertFunc)(void *, void *, void *);
void * findFirst(ArrayUtil, MatchFunc *, void *);
void * findLast(ArrayUtil, MatchFunc *, void *);
ArrayUtil create(int,int);
int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil resize(ArrayUtil,int);
void insertElement(ArrayUtil *,void *);
int findIndex(ArrayUtil, void *);
void dispose(ArrayUtil);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int isEven(void *, void *);
int isDivisible(void* hint, void* item);
int filter(ArrayUtil, MatchFunc *, void * , void ** , int );
void change_to_odd(void *, void *, void *);
void map(ArrayUtil, ArrayUtil, ConvertFunc *, void *);
void addOne(void*, void*);
void add_given_value(void*, void*);
typedef void (OperationFunc)(void*, void*);
void forEach(ArrayUtil, OperationFunc*, void*);
void isGreater(void *, void *, void *);
typedef void (ReducerFunc)(void*, void*, void*);
void* reduce(ArrayUtil, ReducerFunc*, void*, void*);
