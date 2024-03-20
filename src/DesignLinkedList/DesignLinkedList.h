/*
 * @Author: saury czh12581@126.com
 * @Date: 2024-03-15 12:12:37
 * @LastEditors: saury czh12581@126.com
 * @LastEditTime: 2024-03-15 15:54:20
 * @FilePath: \CodeBrainstorming\src\DesignLinkedList\DesignLinkedList.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
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

MyLinkedList* removeNthFromEnd(MyLinkedList* head, int n);

MyLinkedList* removeNthFromEndNode(MyLinkedList* head, int n);

int testremoveNthFromEnd();

// Realization of linked list function
int DesignAndOperateALinkedList(void);


#endif /* DESIGNLINKEDLIST_H */

