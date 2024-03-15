/*
 * @Author: saury czh12581@126.com
 * @Date: 2024-03-15 12:11:24
 * @LastEditors: saury czh12581@126.com
 * @LastEditTime: 2024-03-15 21:03:00
 * @FilePath: \CodeBrainstorming\src\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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






