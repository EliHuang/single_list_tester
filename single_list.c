#include "single_list.h"
#include "malloc.h"

/*
** p_list: pointer to a single list, get header of the list
** size: counter of following node elements exculde the header
*/
BOOL sl_Create(SL_LIST *plist, int size)
{
   pSL_NODE rnode, pnode = NULL;
   int i;
   //header pointer of list, keep unchange 
   *plist = (SL_LIST) malloc(sizeof(SL_NODE));
   if (plist == NULL)
      return FALSE;

   (*plist)->next = NULL;
   rnode = *plist;

   for (i = 0; i < size; i++)
   {
      pnode = (pSL_NODE) malloc(sizeof(SL_NODE));
      if (pnode == NULL)
         return FALSE;
      pnode->data = 0;
      //pnode->next = (*plist)->next;
      //(*plist)->next = pnode;
      rnode->next = pnode;
      rnode = pnode; 
   }
   pnode->next = NULL;
   return TRUE;
}

/*
** pos: node number with valid data
*/
BOOL sl_Insert(SL_LIST list, int pos, int data)
{
   pSL_NODE pnode, inode;
   int cnt = 0;
   //header
   pnode = list;

   while (pnode != NULL && cnt < pos - 1)
   {
      pnode = pnode->next;
      cnt++;
   }
   if (pnode == NULL || cnt > pos -1)
   {
      printf("the insert position %d out of the list range %d!\n", pos, sl_Size(list));
      return FALSE;
   }
   
   inode = (pSL_NODE) malloc(sizeof(SL_NODE));
   if (inode != NULL)
   {
      inode->data = data;
      inode->next = pnode->next;
      pnode->next = inode;
      return TRUE; 
   }
   else
      return FALSE;
}

/*
** pos: node number with valid data
*/
BOOL sl_Delete(SL_LIST list, int pos, int* pdata)
{
   pSL_NODE pnode, dnode;
   int cnt = 0;
   
   //header node
   pnode = list;
   //find the node before the request node
   while (pnode != NULL && cnt < pos - 1)
   {
      pnode = pnode->next;
      cnt++;
   }
   if( pnode == NULL || pnode->next == NULL || cnt > pos - 1)
   {
      printf("the delete position %d is out of the list range %d!\n", pos, sl_Size(list));
      return FALSE;
   }

   dnode = pnode->next;
   pnode->next = dnode->next;
   if (pdata != NULL)
      *pdata = dnode->data;
   free(dnode);

   return TRUE;
}

/*
** pos: node number with valid data
*/
BOOL sl_Get(SL_LIST list, int pos, int *pdata)
{
   pSL_NODE pnode;
   int cnt = 0;
   pnode = list;

   while (pnode != NULL && cnt < pos)
   {
      pnode = pnode->next;
      cnt++;
   }
   if (pnode == NULL)
   {
      printf("Get postion %d is out of the range with list size %d!\n", pos + 1, sl_Size(list));
      return FALSE;
   }

   *pdata = pnode->data;
   return TRUE;
}

/*
** pos: node number with valid data
*/
BOOL sl_Set(SL_LIST list, int pos, int data)
{
   pSL_NODE pnode;
   int cnt = 0;
   //header
   pnode = list;

   while (pnode != NULL && cnt < pos)
   {
      pnode = pnode->next;
      cnt++;
   }
   if (pnode == NULL || cnt > pos)
   {
      printf("the set position is out of the list range!\n");
      return FALSE;
   }

   pnode->data = data;
   return TRUE;
}

/*
** pos: node number with valid data
*/
BOOL sl_Find(SL_LIST list, int *pos, int data)
{
   pSL_NODE pnode;
   int cnt = 0;
   pnode = list;

   while (pnode != NULL && pnode->data != data)
   {
      pnode = pnode->next;
      cnt++;
      if (pnode != NULL && pnode->data == data)
      {
         *pos = cnt;
         return TRUE;
      }
   }
   return FALSE;
}

/*
** return the length without counting header node
*/
int sl_Size(SL_LIST list)
{
   pSL_NODE pnode;
   int cnt = 0;
   //header
   pnode = list;

   while (pnode->next != NULL)
   {
      pnode = pnode->next;
      cnt++;
   }
   return cnt;
}

BOOL sl_Clear(SL_LIST *plist)
{
   pSL_NODE cnode, pnode;
   cnode = *plist;
   while (cnode != NULL)
   {
      pnode = cnode->next;
      free(cnode);
      cnode = pnode;
   }
   *plist = NULL;
   return TRUE;
}

BOOL isSlEmpty(SL_LIST list)
{
   pSL_NODE pnode;
   pnode = list;
   if (pnode->next == NULL)
      return TRUE;
   return FALSE;
}

BOOL isExistLookBackUp(SL_LIST list)
{
   if (list == NULL || list->next == NULL)
      return;
   pSL_NODE first = list;
   pSL_NODE second = list->next;

   while(TRUE)
   {
      if (second == NULL || second->next == NULL)
         break;

      if (first == second)
         return TRUE;

      first = first->next;
      second = second->next->next;
   }
   
   return FALSE;
}
