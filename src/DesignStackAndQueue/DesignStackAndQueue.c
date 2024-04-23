/*
 * @Author: bill.chen
 * @Date: 2024-03-13 13:57:43
 * @LastEditTime: 2024-04-23 11:24:16
 * @LastEditors: bill.chen
 * @Description: 代码随想录
 * @FilePath: \CodeBrainstorming\src\DesignStackAndQueue\DesignStackAndQueue.c
 * 1344729759@qq.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DesignStackAndQueue.h"

/**
 * @description: 创建一个新的栈
 * @param {int} capacity
 * @return {*}
 */
Mystack* creatstack(int capacity)
{
    Mystack* newstack =(Mystack*)malloc(sizeof(Mystack));
    newstack->arr = (int*)malloc(sizeof(int)*capacity);
    newstack->top = -1;
    newstack->size = capacity;
    return newstack;
}

/**
 * @description: 查看栈顶元素值
 * @param {Mystack*} tempstack
 * @return {*}栈顶元素的值，如果栈为空则返回-1
 */
int peekstack(Mystack* tempstack) {
    if (tempstack->top >= 0) 
    {
        return tempstack->arr[tempstack->top];
    } 
    else 
    {
        return -1; // 明确返回-1表示栈为空
    }
}

/**
 * @description: 入栈
 * @param {int} tempdata
 * @param {Mystack*} tempstack
 * @return {*}
 */
void pushstack(int tempdata, Mystack* tempstack)
{
    if(tempstack->top < tempstack->size)
    {
        tempstack->top+=1;
        tempstack->arr[tempstack->top]=tempdata;
        printf("tempstack->arr:%d\n",tempstack->arr[tempstack->top]);
    }
    else
    {
        printf("stack overflow\n");
    }
}

/**
 * @description: 出栈
 * @param {Mystack*} tempstack
 * @return {*}弹出的栈顶元素，如果栈为空则返回-1
 */
int popstack(Mystack* tempstack) {
    if (tempstack->top >= 0) 
    {
        int popped = tempstack->arr[tempstack->top];
        tempstack->top--;
        return popped;
    } 
    else 
    {
        return -1; // 明确返回-1表示栈为空
    }
}

bool Stack_is_empty_or_no(Mystack* tempstack)
{
    if (tempstack->top == -1)
    {
        printf("stack is empty\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void freestack(Mystack* tempstack)
{
    free(tempstack->arr);
    free(tempstack);
}



/**
 * @description: 创建一个新的队
 * @param {MyQueue*} newqueue
 * @return {*}
 */
MyQueue* myQueueCreate() 
{
    MyQueue* newqueue = (MyQueue*) malloc(sizeof(MyQueue));
    newqueue->stackin = creatstack(3);
    newqueue->stackout = creatstack(3);
    return newqueue;
}

/**
 * @description: 入队
 * @param {MyQueue*} obj
 * @param {int} x
 * @return {*}
 */
void myQueuePush(MyQueue* obj, int x) 
{
    pushstack(x,obj->stackin);
}

/**
 * @description: 出队
 * @param {MyQueue*} obj
 * @param {  } else
 * @return {*}
 */
int myQueuePop(MyQueue* obj)
{ 
    if(!Stack_is_empty_or_no(obj->stackout))
    {
        while(Stack_is_empty_or_no(obj->stackin))
        {
            pushstack(popstack(obj->stackin),obj->stackout);
        }
    }
    else
    {
        printf("Stackout is not empty\n");
    }
    return popstack(obj->stackout);
}


/**
 * @description: 队顶元素
 * @param {MyQueue*} obj
 * @param {  } else
 * @return {*}
 */
int myQueuePeek(MyQueue* obj) 
{
    if(Stack_is_empty_or_no(obj->stackout))
    {
        // 如果stackout不为空，直接返回栈顶元素
        return peekstack(obj->stackout);
    }
    else
    {
        // 如果stackout为空，将stackin中的元素移动到stackout
        while(Stack_is_empty_or_no(obj->stackin))
        {
            pushstack(popstack(obj->stackin),obj->stackout);
        }
        printf("Stackout is not empty\n");
    }
    // 此时stackout不为空，返回栈顶元素
    return peekstack(obj->stackout);
}

bool myQueueEmpty(MyQueue* obj) 
{
    if(Stack_is_empty_or_no(obj->stackout)||Stack_is_empty_or_no(obj->stackin))
    {
        printf("MyQueue_is_ont_empty\n");
        return 1;
    }
    else
    {
        printf("MyQueue_is_empty\n");
        return 0;
    }
}

void myQueueFree(MyQueue* obj) 
{
    freestack(obj->stackin);
    freestack(obj->stackout);
    free(obj);
}

/**
 * 设计并操作队列和栈的示例函数。
 * 演示如何创建队列，向队列中添加元素，
 * 查看队首元素，移除队首元素，并检查队列是否为空。
 * 最后，释放队列占用的资源。
 * @param {void} 无参数
 * @return {int} 函数返回0表示成功执行
 */
int DesignAndOperateQueuestack(void)
{
    MyQueue* q = myQueueCreate();
    myQueuePush(q, 1);
    myQueuePush(q, 2);
    myQueuePush(q, 3);

    printf("%d\n", myQueuePop(q)); // 应输出 1
    printf("%d\n", myQueuePeek(q)); // 应输出 2
    printf("%d\n", myQueueEmpty(q)); // 应输出 0 (false)

    // 增加更多测试
    myQueuePush(q, 4);
    printf("%d\n", myQueuePop(q)); // 应输出 2
    printf("%d\n", myQueuePeek(q)); // 应输出 3
    printf("%d\n", myQueueEmpty(q)); // 应输出 0 (false)

    myQueuePush(q, 5);
    myQueuePush(q, 6);
    printf("%d\n", myQueuePop(q)); // 应输出 3
    printf("%d\n", myQueuePop(q)); // 应输出 4
    printf("%d\n", myQueueEmpty(q)); // 应输出 0 (false)

    // 确保队列完全清空
    while (!myQueueEmpty(q)) {
        myQueuePop(q);
    }
    printf("%d\n", myQueueEmpty(q)); // 应输出 1 (true)

    myQueueFree(q);
    return 0;
}



/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/





