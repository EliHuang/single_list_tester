# single_list_tester
a single linked list implementation and test

gcc build

$make

$./single_list_test

2016-01-08

Functions list:

BOOL sl_Create(SL_LIST *plist, int size);

BOOL sl_Clear(SL_LIST *plist);

BOOL sl_Insert(SL_LIST list, int pos, int data);

BOOL Sl_Delete(SL_LIST list, int pos, int* pdata);

BOOL sl_Get(SL_LIST list, int pos, int* pdata);

BOOL sl_Set(SL_LIST list, int pos, int data);

BOOL sl_Find(SL_LIST list, int* pos, int data);

SL_LIST sl_SelectSort(SL_LIST list);

/*
**    [Header *]--------->[L *]----------->[S *]--------->[ ]
**  p1               p1->n         p1->n->n
**                                    @1 p2          p2->n
**                 @4              @3              @2      
**    [Header *]--------->[S *]----------->[L *]--------->[ ]
**   |-------------@5------------->|
**   |pcurmax                      |pcurmax
*/
SL_LIST sl_BubbleSort(SL_LIST list);

int sl_Size(SL_LIST list);

BOOL isSlEmpty(SL_LIST list);

BOOL isExistLookBackUp(SL_NODE *node);

void sl_Print(SL_LIST list);
