typedef struct LinkedList{
  struct element *first;
  struct element *last;
  int length;
}LinkedList;

typedef struct element{
  void *value;
  struct element *next;
}Element;

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void increment(void *);
typedef void (*ElementProcessor)(void *);
void forEach(LinkedList, ElementProcessor);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);
typedef int (MatchFunc)(void*, void* );
LinkedList filter(LinkedList, MatchFunc, void * );
LinkedList reverse(LinkedList);
typedef void (ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);
LinkedList map(LinkedList, ConvertFunc, void * );
typedef void *(Reducer)(void* , void* , void* );
void * reduce(LinkedList, Reducer *, void *, void *);
