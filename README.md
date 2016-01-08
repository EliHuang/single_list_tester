# single_list_tester
single linked list implementation and test
单链表实现与测试

Compile and Run:

gcc build

$make

$./single_list_test


Functions list:

BOOL sl_Create(SL_LIST *plist, int size);

BOOL sl_Clear(SL_LIST *plist);

BOOL sl_Insert(SL_LIST list, int pos, int data);

BOOL Sl_Delete(SL_LIST list, int pos, int* pdata);

BOOL sl_Get(SL_LIST list, int pos, int* pdata);

BOOL sl_Set(SL_LIST list, int pos, int data);

BOOL sl_Find(SL_LIST list, int* pos, int data);

SL_LIST sl_SelectSort(SL_LIST list);

SL_LIST sl_BubbleSort(SL_LIST list);

int sl_Size(SL_LIST list);

BOOL isSlEmpty(SL_LIST list);

BOOL isExistLookBackUp(SL_NODE *node);

void sl_Print(SL_LIST list);
