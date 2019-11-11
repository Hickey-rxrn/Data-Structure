//
//  Queue.h
//  test_7_18(栈和队列)
//
//  Created by 张辉 on 2019/7/20.
//  Copyright © 2019年 张辉. All rights reserved.
//

#ifndef Queue_h
#define Queue_h


#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int QUDataType;
typedef struct QueueNode
{
    struct QueueNode* _next;
    QUDataType _data;
}QueueNode;

typedef struct Queue
{
    QueueNode* _front;
    QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq,QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueTail(Queue* pq);
size_t QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void TestQueue(void);

#endif /* Queue_h */
