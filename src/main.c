/*
 * @Author: bill.chen
 * @Date: 2024-03-15 12:11:24
 * @LastEditTime: 2024-03-18 15:05:52
 * @LastEditors: bill.chen
 * @Description: 代码随想录
 * @FilePath: \CodeBrainstorming\src\main.c
 * 1344729759@qq.com
 */



#include <stdio.h>
#include <stdlib.h>
#include "DesignLinkedList.h"





int main()
{
    MyLinkedList *list =(MyLinkedList *)malloc(sizeof(MyLinkedList));
    list->next=NULL;
    myLinkedListGet(list,0);
    myLinkedListAddAtHead(list,1);
    myLinkedListAddAtHead(list,2);
    myLinkedListAddAtTail(list,0);
    myLinkedListGet(list,2);
    myLinkedListGet(list,4);
    myLinkedListAddAtIndex(list,0,1);
    myLinkedListAddAtIndex(list,4,6);
    myLinkedListAddAtIndex(list,7,9);
    myLinkedListDeleteAtIndex(list,0);
    myLinkedListDeleteAtIndex(list,4);
    myLinkedListDeleteAtIndex(list,5);
    myLinkedListDeleteAtIndex(list,3);
    myLinkedListDeleteAtIndex(list,2);
    myLinkedListDeleteAtIndex(list,1);
    myLinkedListDeleteAtIndex(list,0);
    myLinkedListDeleteAtIndex(list,0);
    printf("list.data:%d\n",list->data);
    printf("list.next:%d\n",list->next);
    printf("list:%d\n",list);
     
    int DesignAndOperateALinkedList();
    return 0;
}






