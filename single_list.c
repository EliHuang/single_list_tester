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
** select method return a new sorted list
*/
SL_LIST sl_SelectSort(SL_LIST list)
{
   pSL_NODE pfirst, ptail;
   pSL_NODE ppremin, pmin;
   pSL_NODE pnode;

   pfirst = NULL;
   while (NULL != list)
   {
      /* find the min node */
      for (pnode = list, pmin = list; NULL != pnode->next; pnode = pnode->next)
      {
         if (pnode->next->data < pmin->data)
         {
            ppremin = pnode;
            pmin = pnode->next;
         }
      }

      /* create new list with min node */
      if (NULL == pfirst)
      {
         pfirst = pmin;
         ptail = pmin;
      }
      else
      {
         ptail->next = pmin;
         ptail = pmin;
      }

      /* remove the min node from the old list */
      if (pmin == list)
         list = list->next;
      else
         ppremin->next = pmin->next;      
      
   }

   if (NULL != pfirst)
      ptail->next = NULL;

   list = pfirst;
   return list;
   
}

/*
** bubble method return the sorted list
*/
SL_LIST sl_BubbleSort(SL_LIST list)
{
   pSL_NODE pend;
   pSL_NODE pcurmax, p1, p2;
   
#ifdef NON_HEADER_NODE
   /* add new node p1 to original list, list([list]) change to list([p1]->[list]) */
   p1 = (pSL_NODE) malloc(sizeof(SL_NODE));
   p1->next = list;
   list = p1;
#endif

/*
**    [Header *]--------->[L *]----------->[S *]--------->[ ]
**    [Header *]--------->[S *]----------->[L *]--------->[ ]
*/

   /* loop1: loop2 will set the largest node as the bottom of the list to create new end*/
   for (pend = NULL; pend != list; pend = pcurmax)
   {
      /* loop2: p1, pcurmax initialize to the new list beginning every bubble loop   *
        * pcurmax record the largest node which will be ignored in next loop1         */
      for (pcurmax = p1= list; p1->next->next != pend; p1 = p1->next)
      {
         if (p1->next->data > p1->next->next->data)
         {
            /* @1 save L's original next pointer */
            p2 = p1->next->next;
            /* @2 change L's current next pointer */
            p1->next->next = p2->next;
            /* @3 change S's current next pointer */
            p2->next = p1->next;
            /* @4 change p1's current next pointer */
            p1->next = p2;
            /* @5 change pcur to current large node */
            pcurmax = p1->next->next;
         }
      }
   }
#ifdef NON_HEADER_NODE
   p1 = list;
   list = list->next;
   free(p1);
   p1 = NULL;
#endif

   return list;
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

void sl_Print(SL_LIST list)  
{  
    pSL_NODE pnode = list->next;  
    printf("List->");  
    while(pnode != NULL)  
    {  
        printf("%d - >", pnode->data);  
        pnode= pnode->next;  
    }  
    printf("NULL\n");  
}  