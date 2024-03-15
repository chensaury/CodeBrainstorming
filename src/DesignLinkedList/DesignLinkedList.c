/*
 * @Author: saury czh12581@126.com
 * @Date: 2024-03-13 13:57:43
 * @LastEditors: saury czh12581@126.com
 * @LastEditTime: 2024-03-15 12:23:19
 * @FilePath: \CodeBrainstorming\src\DesignLinkedList\DesignLinkedList.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>
#include <stdlib.h>
#include "DesignlinkedList.h"

MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList *head=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->data=0;
    head->next=NULL;
    return head;
}

//获取指定位置的值
int myLinkedListGet(MyLinkedList* obj, int index)
{   
    MyLinkedList *temp = obj->next;//带有虚拟头结点，首元定义为.next
    if(index<0)
    {
        printf("err: %d\n", -1);
        return -1;
    }
    for(int i=0; i<index; i++)
    {
        if(temp!=NULL)
        {
            temp = temp->next;
        }
        else
        {
            printf("err: %d\n", -1);
            return -1;
        }   
    }
    if(temp!=NULL)
    {
        printf("temp: %d\n", temp->data);
        return temp->data;
    }
    else
    {
        printf("err: %d\n", -1);
        return -1;
    }
}

//带有虚拟头结点头插法
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    MyLinkedList *newhead = myLinkedListCreate();
    newhead->data=val;
    
    newhead->next=obj->next;//新节点指向首元
    obj->next=newhead;//虚拟头结点指向新节点
    return;
}

//带有虚拟头结点尾插法
void myLinkedListAddAtTail(MyLinkedList* obj, int val) 
{
    MyLinkedList* temp = obj;
    MyLinkedList* newnode = myLinkedListCreate();
    newnode->data= val;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
   // free(temp);
    return ;
}

//带虚拟头结点，在链表指定位置插入新的值
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
    if(obj == NULL || index <= 0)  // 如果链表为空或索引小于0
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList* newhead = myLinkedListCreate();
    newhead->data = val;
    int i = 0 ;
    MyLinkedList* temp = obj;
    // while(temp->next!=NULL){
    //     if(i<index){
    //         temp=temp->next;
    //         i++;
    //     }
    //     else{
    //         break;
    //     }
    // }
    // if(i!=index) return;
    for(i = 0; temp->next != NULL && i < index; i++) // 循环直到达到指定位置的前一个节点,并判断指定位置是否为空
    {
        temp = temp->next;
    }
    if(i != index) 
    {
        // (temp == NULL || i != index - 1) 如果到达链表末尾或者索引位置不正确，则直接返回
        return; 
        // 如果索引位置不正确，则直接返回
    }
    newhead->next = temp->next; // 将新节点的 next 指向原来的节点
    temp->next = newhead; // 将前一个节点的 next 指向新节点
    return;
}

 //删除指定位置的值
 void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
 {
    MyLinkedList *temp = obj->next;
    if((obj==NULL) || (obj->next==NULL) || index<0) return;
    // 如果要删除的是头结点
    MyLinkedList *pre = obj;
    int i = 0;
    while(temp->next!=NULL&& i<index)  //循环赋值查找，找到后退出循环
    {
        pre=temp; //存储上一次的值
        temp=temp->next; //赋新值，如果满足条件，退出
        i++;
    }
    if(i!=index)// 如果要删除的节点不存在
    {
        return;
    }
    pre->next=temp->next;//删除节点
 }

//释放链表内存
void myLinkedListFree(MyLinkedList* obj) 
{
    if (obj == NULL)
        return ;
    MyLinkedList* current = obj->next;
    MyLinkedList* temp = myLinkedListCreate();
    while (current != NULL) 
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(obj); // 释放虚拟头结点的内存
}

MyLinkedList* reverseList(MyLinkedList* head) {
    MyLinkedList *temp = head;
    MyLinkedList *outlist = NULL;
    while (temp != NULL)
    {
        MyLinkedList *temporarynode = temp->next; //临时节点
        temp->next = outlist; //指向输出
        outlist = temp;
        temp = temporarynode;
    }
    return outlist;  
}



int DesignAndOperateALinkedList(void)
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


    MyLinkedList *a1= malloc(sizeof(MyLinkedList));
    MyLinkedList *a2= malloc(sizeof(MyLinkedList));
    MyLinkedList *a3= malloc(sizeof(MyLinkedList));
    a1->data=1;
    a2->data=2;
    a3->data=3;
    a1->next=a2;
    a2->next=a3;
    a3->next=NULL;
    a1 = reverseList(a1);
    return 0;
}





