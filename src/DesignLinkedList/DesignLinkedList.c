/*
 * @Author: bill.chen
 * @Date: 2024-03-13 13:57:43
 * @LastEditTime: 2024-03-19 13:23:21
 * @LastEditors: bill.chen
 * @Description: 代码随想录
 * @FilePath: \CodeBrainstorming\src\DesignLinkedList\DesignLinkedList.c
 * 1344729759@qq.com
 */

#include <stdio.h>
#include <stdlib.h>
#include "DesignlinkedList.h"

/**
 * @description: 创建链表
 * @param {MyLinkedList} *head
 * @return {*}
 */
MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList *head=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->data=0;
    head->next=NULL;
    return head;
}


/**
 * @description: 获取链表指定位置的值
 * @param {MyLinkedList*} obj
 * @param {int} index
 * @param {  } return
 * @param {  } return
 * @param {return} temp
 * @return {*}
 */
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

/**
 * @description: 带有虚拟头结点头插法
 * @param {MyLinkedList*} obj
 * @param {int} val
 * @return {*}
 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    MyLinkedList *newhead = myLinkedListCreate();
    newhead->data=val;
    
    newhead->next=obj->next;//新节点指向首元
    obj->next=newhead;//虚拟头结点指向新节点
    return;
}

/**
 * @description: 带有虚拟头结点尾插法
 * @param {MyLinkedList*} obj
 * @param {int} val
 * @return {*}
 */
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

/**
 * @description: 带虚拟头结点，在链表指定位置插入新的值
 * @param {MyLinkedList*} obj
 * @param {int} index
 * @param {int} val
 * @param {  } return
 * @param {  } temp
 * @return {*}
 */
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

 
 /**
  * @description: 删除指定位置的值
  * @param {MyLinkedList*} obj
  * @param {int} index
  * @return {*}
  */
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


/**
 * @description: 释放链表内存
 * @param {MyLinkedList*} obj
 * @return {*}
 */
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

/**
 * @description: 链表翻转
 * @param {MyLinkedList*} head
 * @return {*}
 */
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


/**
 * @description: 删除带虚拟头结点链表的倒数第 n 个结点
 * @param {ListNode*} head
 * @param {int} n
 * @return {*}
 */
MyLinkedList* removeNthFromEnd(MyLinkedList* head, int n) {
    MyLinkedList* temp = head;
    if(temp==NULL) return head;
    int i = 0;
    while (temp->next!=NULL)
    {
        temp = temp->next;
        i++;
    }
    if(n>i||n<=0) return head;
    MyLinkedList* headNode = head;
    MyLinkedList* tailNode = head->next;
    int m = 0;
    while((tailNode!=NULL)&&(m < (i-n)))
    {
        headNode = tailNode;
        tailNode = tailNode->next;
        m++;
    }
    // if(m != (i-n)+1) return head;
    headNode->next = tailNode->next;
    tailNode = headNode;
    return head; 
}

/**
 * @description: 删除链表的倒数第n个节点
 * @param {MyLinkedList*} head
 * @param {int} n
 * @return {*}
 */
MyLinkedList* removeNthFromEndNode(MyLinkedList* head, int n) {
    MyLinkedList* temp = head;
    if(temp==NULL) return head;
    int i = 0;
    while (temp!=NULL)
    {
        temp = temp->next;
        i++;
    }
    if(n>i||n<=0) return head;
    MyLinkedList* headNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    headNode->data = 0;
    headNode->next = head;

    MyLinkedList* tailNode = headNode;
    MyLinkedList* dele = NULL;
    int m = 0;
    for(int m = 0; m<i-n; m++)//到要删除的前一个节点
    {
        tailNode = tailNode->next;
    }

    tailNode->next = tailNode->next->next;

    return headNode->next;
}

/**
 * @description: 无虚拟头结点倒数删除第n个测试
 * @param {MyLinkedList*} a
 * @return {*}
 */
int testremoveNthFromEnd()
{
    MyLinkedList* a = malloc(sizeof(MyLinkedList));
    MyLinkedList* b = malloc(sizeof(MyLinkedList));
    MyLinkedList* c = malloc(sizeof(MyLinkedList));   
    a->data = 1;
    b->data = 2;
    c->data = 3;
    a->next=b;
    b->next=c;
    c->next=NULL;
    removeNthFromEndNode(a, 1);
}


int DesignAndOperateALinkedList(void)
{
    MyLinkedList *list =(MyLinkedList *)malloc(sizeof(MyLinkedList));
    list->next=NULL;
    myLinkedListGet(list,0);
    myLinkedListAddAtHead(list,1);
    myLinkedListAddAtHead(list,2);
    myLinkedListAddAtTail(list,0);

    removeNthFromEnd(list,1);


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





