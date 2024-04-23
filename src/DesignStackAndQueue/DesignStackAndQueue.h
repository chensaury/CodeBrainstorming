/*** 
 * @Author: bill.chen
 * @Date: 2024-04-20 14:45:42
 * @LastEditTime: 2024-04-23 09:20:10
 * @LastEditors: bill.chen
 * @Description: 代码随想录
 * @FilePath: \CodeBrainstorming\src\DesignStackAndQueue\DesignStackAndQueue.h
 * @1344729759@qq.com
 */

#ifndef DESIGNSTACKANDQUEUE_H
#define DESIGNSTACKANDQUEUE_H

#include <stdbool.h>

typedef struct {
    int* arr;
    int top;
    int size;
} Mystack;

typedef struct {
    Mystack* stackin;
    Mystack* stackout;
} MyQueue;


MyQueue* myQueueCreate() ;

void myQueuePush(MyQueue* obj, int x) ;

int myQueuePop(MyQueue* obj) ;

int myQueuePeek(MyQueue* obj) ;

bool myQueueEmpty(MyQueue* obj) ;

void myQueueFree(MyQueue* obj) ;

int DesignAndOperateQueuestack(void);

#endif /* DESIGNLINKEDLIST_H */

