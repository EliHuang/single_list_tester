#include "stdio.h"
#include "single_list.h"

#define LIST_SIZE_DEFAULT (3)

int main(void)
{
   SL_LIST list;
   int LIST_SIZE;
   int data;
   int position;
   int size;
   int i;

   printf("\nInput the required single list size:\n");
   scanf("%d", &LIST_SIZE);
   LIST_SIZE = (LIST_SIZE <= 0) ? LIST_SIZE_DEFAULT : LIST_SIZE;
   //create list with header node
   sl_Create(&list, LIST_SIZE);
   printf("\nCreate single list size is %d\n",size = sl_Size(list));
   for (i = 1; i <= LIST_SIZE; i++)
   {
      if (sl_Get(list, i, &data))
         printf("initial list, get position %d element data is: %d\n", i, data);
   }

   //set list elements
   printf("\n");
   for (i = 1; i <= LIST_SIZE; i++)
   {
      sl_Set(list, i, i);
   }
   for (i = 1; i <= LIST_SIZE; i++)
   {
      if (sl_Get(list, i, &data))
         printf("set list, get position %d element data is: %d\n", i, data);
   }

   //delete list element
   printf("\nChoose position(1-N) to delete:\n");
   scanf("%d", &position);
   if (sl_Delete(list, position, &data))
      printf("delete the position %d with data %d, size change to %d\n", position, data, sl_Size(list));
   for (i = 1; i <= sl_Size(list); i++)
   {
      if (sl_Get(list, i, &data))
         printf("delete list, get position %d element data is: %d\n", i, data);
   }

   //insert list element
   printf("\nChoose position(1-N) to insert:\n");
   scanf("%d", &position);
   printf("\nSet data(int) to insert:\n");
   scanf("%d", &data);
   
   if (sl_Insert(list, position, data))
      printf("insert the position %d with data %d, size change to %d\n", position, data, sl_Size(list));
   for (i = 1; i <= sl_Size(list); i++)
   {
      if (sl_Get(list, i, &data))
         printf("insert list, get position %d element data is: %d\n", i, data);
   }

   //find list element
   printf("\nInput data(int) to find:\n");
   scanf("%d", &data);
   if (sl_Find(list, &position, data))
      printf("find the data %d in position %d\n", data, position);
   else
      printf("can't find data %d in the list\n", data);

   //check loop
   printf("\nCheck list isExistLookBackup: %d\n", isExistLookBackUp(list));
   printf("\nInput enable(0/1) list loop in the list:\n");
   int en_loop = 0;
   scanf("%d", &en_loop);
   if (en_loop)
   {
      (*list).next->next = (*list).next; 
      printf("\nMake list has loop isExistLookBackup: %d\n", isExistLookBackUp(list));
      return 0;
   }

   //is empty
   printf("\nCheck list isEmpty:\n");
   size = sl_Size(list);
   while (size--)
   {
      if (sl_Delete(list, 1, &data))
         printf("delete the position 1 with data %d, size change to %d, isEmpty %d\n", data, sl_Size(list), isSlEmpty(list));
     
   }
   
   //list clear
   printf("\nClear the list: %d\n", sl_Clear(&list));
   if (list == NULL)
      printf("the list has been clear.\n");
   

}



