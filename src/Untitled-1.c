/*
 * @Author: saury czh12581@126.com
 * @Date: 2024-02-29 09:54:39
 * @LastEditors: saury czh12581@126.com
 * @LastEditTime: 2024-03-14 21:03:58
 * @FilePath: \d_code\src\Untitled-1.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    int data;
    struct LinkedList* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList *head=malloc(sizeof(MyLinkedList));
    head->data=0;
    head->next=NULL;
    return head;
}



int myLinkedListGet(MyLinkedList* obj, int index)
{   
    if(index<0)
    {
        return -1;
    }
    for(int i=0; i<index; i++)
    {
        if(obj!=NULL)
        {
            obj = obj->next;
        }
        else
        {
            return -1;
        }   
    }
    if(obj!=NULL)
    {
        return obj->data;
    }
    else
    {
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

// /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
// void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
// 	if (index <= 0) {
// 		myLinkedListAddAtHead(obj, val);
// 	}

// 	int now = 0;
// 	MyLinkedList *nowList = obj->next;
// 	while (nowList->next != NULL) {
// 		if (now == index - 1) {
// 			break;
// 		}
// 		nowList = nowList->next;
// 		now++;
// 	}

// 	if (index - 1 != now) {
// 		return;
// 	}

// 	MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
// 	Node->data = val;
// 	Node->next = nowList->next;
// 	nowList->next = Node;
// }






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
    for(i = 0; temp != NULL && i < index; i++) // 循环直到达到指定位置的前一个节点,并判断指定位置是否为空
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


// void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
// {
//     MyLinkedList* new = malloc(sizeof(MyLinkedList));
//     new->data = val;
//     if(index < 0 || (obj) == NULL) return;
//     // 如果插入的值位于队首
//     if(index == 0) {
//         new->next = (obj->next);
//         (obj->next) = new;
//         return;
//     }
//     // // 如果插入的值不位于队首
//     // MyLinkedList* temp = obj;
//     // MyLinkedList* pre = obj;  
//     // for(int i = 0; i < index; i++) {
//     //     pre = temp;
//     //     temp = temp->next;   
//     //     if(temp == NULL) {
//     //         break; // 防止访问空指针
//     //     }
//     // } 
//     // pre->next = new;
//     // new->next = temp;
// }

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    MyLinkedList *temp = obj;
    // 如果要删除的是头结点
    while(obj!=NULL&&obj->data==index)
    {
        obj=temp->next;
        free(temp);
    }
    // 如果要删除的不是头结点
    MyLinkedList *pre = NULL;
    while(temp!=NULL&&temp->data!=index)  //循环赋值查找，找到后退出循环
    {
        pre=temp; //存储上一次的值
        temp=temp->next; //赋新值，如果满足条件，退出
    }
    pre->next=temp->next;//删除节点
    free(temp);
// 如果要删除的节点不存在
    if(temp==NULL)
    {
        return;
    }
}

void myLinkedListFree(MyLinkedList* obj) {}









MyLinkedList *NEWlistnode(int index)
{
        MyLinkedList *head=malloc(sizeof(MyLinkedList));
        head->data=index;
        head->next=NULL;

        return head;
}


void delate_node(MyLinkedList *head,int data)
{
    MyLinkedList *temp = head;
    // 如果要删除的是头结点
    while(head!=NULL&&head->data==data)
    {
        head=temp->next;
        free(temp);
    }
    // 如果要删除的不是头结点
    MyLinkedList *pre;
    while(temp!=NULL&&temp->data!=data)  //循环赋值查找，找到后退出循环
    {
        pre=temp; //存储上一次的值
        temp=temp->next; //赋新值，如果满足条件，退出
    }
    pre->next=temp->next;//删除节点
    free(temp);
// 如果要删除的节点不存在
    if(temp==NULL)
    {
        return;
    }

    // return head;
}





int main(){
    MyLinkedList *list =(MyLinkedList *)malloc(sizeof(MyLinkedList));
    list->next=NULL;
    myLinkedListAddAtHead(list,1);
    myLinkedListAddAtHead(list,2);
    myLinkedListAddAtTail(list,0);
    myLinkedListAddAtIndex(list,0,1);
    myLinkedListAddAtIndex(list,4,6);
    myLinkedListAddAtIndex(list,7,9);
    // delate_node(head,3);
    // MyLinkedList *nhead= malloc(sizeof(MyLinkedList));
    // nhead->next=head;
    // myLinkedListAddAtIndex(head,0,1);
     //delate_node(head,4);
    // creat_new_node(&head,4);
}





