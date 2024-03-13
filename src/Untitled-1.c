/*
 * @Author: saury czh12581@126.com
 * @Date: 2024-02-29 09:54:39
 * @LastEditors: saury czh12581@126.com
 * @LastEditTime: 2024-03-13 12:50:59
 * @FilePath: \d_code\src\Untitled-1.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>
#include <stdlib.h>


// 定义链表节点结构体
struct Node {
    int data;           // 节点数据
    struct Node* next;  // 指向下一个节点的指针
};

struct Node *NEWlistnode(int index)
{
        struct Node *head=malloc(sizeof(struct Node));
        head->data=index;
        head->next=NULL;

        return head;
}

// int creat_node()
// {
//     int arr[5]={1,2,3,4,5,};
//     // struct Node *head =malloc(sizeof(struct Node));
//     struct Node *head =NEWlistnode(0);
//     for(int i=0; i<5; i++)
//     {
//         struct Node *p=malloc(sizeof(struct Node));
//         p->next=head;
//         p->data=arr[i];
//         head = p;
//     }
//     return 0;
// }

int creat_new_node(struct Node **head,int data)
{
    // struct Node *head =malloc(sizeof(struct Node));
    struct Node *newnode =NEWlistnode(data);  //新建一个节点
    if(*head==NULL)        //如果传进来的节点是空的，把新建的赋值给它，在第一次有效
    {
        *head = newnode;
        return 0;
    }
    // struct Node *creat=*head; //创建一个中间缓冲区
    // while(creat->next !=NULL)  //判断指向下一个的next是否为空
    // {
    //     creat=creat->next;  //循环赋值直到creat为最新的节点
    // }
    // creat->next=newnode; //指向新创建的节点
    // return 0;

    // struct Node *p= malloc(sizeof(struct Node));
    // p->next=
    newnode->next=(*head);
    (*head)= newnode;

}

void delate_node(struct Node *head,int data)
{
    struct Node *temp = head;
    // 如果要删除的是头结点
    while(head!=NULL&&head->data==data)
    {
        head=temp->next;
        free(temp);
    }
    // 如果要删除的不是头结点
    struct Node *pre;
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

    //return head;
}





int main(){
    struct Node *head =NULL;
    creat_new_node(&head,1);
    creat_new_node(&head,2);
    creat_new_node(&head,3);
    // delate_node(head,3);
    
    delate_node(head,2);
    creat_new_node(&head,4);
}





// typedef struct Node1
// {
//     int data1;
//     struct Node1* next1;
// }NODE1;
//     NODE1 U;
//     U.data1 =0;

// struct Node2
// {
//     int data2;
//     struct Node2* next2;
// };
//     struct Node2 u2;
//     u2.data2 =0;

//     typedef struct Node2 NODE2;
//     NODE2 u3;
//     u3.data2 =0;


// typedef struct ListNodeT
// {
//     int val;
//     struct ListNodeT *next;
// }ListNode; 



// // 创建一个新节点
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("内存分配失败\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // 在链表末尾插入节点
// void append(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }
//     struct Node* current = *head;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     current->next = newNode;
// }

// // 删除指定值的节点
// void deleteNode(struct Node** head, int key) {
//     struct Node* temp = *head, *prev;

//     // 如果要删除的节点是头节点
//     if (temp != NULL && temp->data == key) {
//         *head = temp->next;
//         free(temp);
//         return;
//     }

//     // 找到要删除节点的前一个节点
//     while (temp != NULL && temp->data != key) {
//         prev = temp;
//         temp = temp->next;
//     }

//     // 如果找不到要删除的节点
//     if (temp == NULL) {
//         printf("未找到要删除的节点\n");
//         return;
//     }

//     // 删除节点
//     prev->next = temp->next;
//     free(temp);
// }

// // 打印链表中的所有节点
// void printList(struct Node* head) {
//     while (head != NULL) {
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// int main() {
//     // 初始化头节点
//     struct Node* head = NULL;

//     // 在链表末尾插入节点
//     append(&head, 1);
//     append(&head, 2);
//     append(&head, 3);
//     append(&head, 4);

//     // 打印链表
//     printf("链表内容: ");
//     printList(head);

//     // 删除节点
//     deleteNode(&head, 3);

//     // 再次打印链表
//     printf("删除节点后的链表内容: ");
//     printList(head);

//     return 0;
// }

























// enum color
// {
//     red,
//     green = 3,
//     blue
// }Color;
// #define max 100

// int sum(int x, int y);


// //c++ standard 链表定义
// // struct ListNode
// // {
// //     int val;
// //     ListNode *next;
// //     ListNode(int x) : val(x), next(NULL);{}
// // };

// typedef struct ListNodeT
// {
//     int val;
//     struct ListNodeT *next;
// }ListNode; 


// int main()
// {

//     int i = 12;
//     int *a;
//     int** b;
//     a=&i;
    







//     // int arr[4][10]=
//     // {
//     //     { , , , ,*,*, , , , },
//     //     {*,*,*,*,*,*,*,*,*,*},
//     //     { , , ,*, , ,*, , , },
//     //     { , , ,*, , ,*, , , },
//     // };
//     // for(int i=0; i<4;i++) 
//     // {
//     //     for(int j=0; j<10;j++)
//     //     {
//     //         printf("%d ",arr[i][j]);
//     //     }
//     //     printf("\n");
//     // }

//     // printf("     **     \n");
//     // printf("************\n");
//     // printf("   *    *   \n");
//     // printf("   *    *   \n");


//     // Color = red;

//     // const int n = 0;
//     // int arr[9]={0};
//     // int a = max;

//     // printf("%d\n",red);
//     // printf("%d\n",green);
//     // printf("%d\n",blue);

//     // char arr1[] = "abcde";
//     // char arr2[] = {'a', 'b', 'c', 'd', 'e','\0'};
//     // printf("%s\n",arr1);
//     // printf("%s\n",arr2);
//     // printf("%d\n",strlen("c:\tabc\678\tabc.a"));


//     // int num1 = 0;
//     // int num2 = 0;
//     // scanf("%d,%d",&num1,&num2);
//     // // int sum = 0;
//     // // sum = num1 + num2;
    
//     // printf("sum =%d\n",sum(num1, num2));
    
//     // printf("%zu\n",sizeof(char));
//     // printf("%zu\n",sizeof(short));
//     // printf("%zu\n",sizeof(int));
//     // printf("%zu\n",sizeof(long));
//     // printf("%zu\n",sizeof(long long));
//     // printf("%zu\n",sizeof(float));

//     return 0;

// }

// // int sum(int x, int y)
// // {
// //     int a = x + y;
// //     return a;
// // }


