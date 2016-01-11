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
// int add_to_list(LinkedList *,void *);
