#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#define TRUE 1
#define FALSE 0

typedef int BOOL; 

typedef struct single_list_node {
   int data;
   struct single_list_node *next;
}SL_NODE,*pSL_NODE, *SL_LIST;

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

#endif
