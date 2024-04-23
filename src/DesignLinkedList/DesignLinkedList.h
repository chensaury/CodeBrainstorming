/*** 
 * @Author: bill.chen
 * @Date: 2024-03-15 12:12:37
 * @LastEditTime: 2024-04-20 14:47:30
 * @LastEditors: bill.chen
 * @Description: 代码随想录
 * @FilePath: \CodeBrainstorming\src\DesignLinkedList\DesignLinkedList.h
 * @1344729759@qq.com
 */
#ifndef DESIGNLINKEDLIST_H
#define DESIGNLINKEDLIST_H

// Define the structure for a node in the linked list
typedef struct LinkedList {
    int data;
    struct LinkedList* next;
} MyLinkedList;

// Function to create an empty linked list
MyLinkedList* myLinkedListCreate();

// Function to get the value at the specified index in the linked list
int myLinkedListGet(MyLinkedList* obj, int index);

// Function to add a new node with given value at the head of the linked list
void myLinkedListAddAtHead(MyLinkedList* obj, int val);

// Function to add a new node with given value at the end of the linked list
void myLinkedListAddAtTail(MyLinkedList* obj, int val);

// Function to add a new node with given value at the specified index in the linked list
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);

// Function to delete the node at the specified index in the linked list
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);

// Function to free the memory allocated for the linked list
void myLinkedListFree(MyLinkedList* obj);

//Reverse the linked list.
MyLinkedList* reverseList(MyLinkedList* head);

//Delete The County Node Of The Linked List
MyLinkedList* removeNthFromEnd(MyLinkedList* head, int n);

//Delete The County Node Of The Linked List
MyLinkedList* removeNthFromEndNode(MyLinkedList* head, int n);

//无虚拟头结点倒数删除第n个测试
int testremoveNthFromEnd();

//链表相交
MyLinkedList *getIntersectionNode(MyLinkedList *headA, MyLinkedList *headB);

// Realization of linked list function
int DesignAndOperateALinkedList(void);

#endif /* DESIGNLINKEDLIST_H */

