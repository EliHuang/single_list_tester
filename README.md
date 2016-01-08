# **single linked list demo**
single linked list implementation and test<br> 
单链表实现与测试

##Compile and Run:

gcc build <br>
$ make <br>
$ ./single_list_test <br>


##Functions list:

```c
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
```
##Reference Blog
[C语言一个单链表的实现](http://blog.csdn.net/hopeyouknow/article/details/6677974)<br>
[链表的排序](http://blog.csdn.net/northplayboy/article/details/552388)<br>
