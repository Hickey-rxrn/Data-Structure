//
//  Queue.c
//  test_7_18(栈和队列)
//
//  Created by 张辉 on 2019/7/20.
//  Copyright © 2019年 张辉. All rights reserved.
//

#include "Queue.h"


void QueueInit(Queue* pq)
{
    assert(pq);
    pq->_tail = NULL;
    pq->_front = NULL;
}
void QueueDestory(Queue* pq)
{
    
}
QueueNode* BuyQueueNode(QUDataType x)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->_data = x;
    node->_next = NULL;
    return node;
}
void QueuePush(Queue* pq,QUDataType x)
{
    assert(pq);
    QueueNode* newnode = BuyQueueNode(x);
    if(pq->_tail == NULL)
    {
        pq->_front = pq->_tail = newnode;
    }
    else
    {
        pq->_tail->_next = newnode;
        pq->_tail = newnode;
    }
}
void QueuePop(Queue* pq)
{
    assert(pq && pq->_front != NULL);
    QueueNode* next = pq->_front->_next;
    free(pq->_front);
    pq->_front = next;
    if(pq->_front == NULL)
        pq->_tail = NULL;
}
QUDataType QueueFront(Queue* pq)
{
    assert(pq && pq != NULL);
    return pq->_front->_data;
}
QUDataType QueueTail(Queue* pq)
{
    assert(pq && pq->_tail != NULL);
    return pq->_tail->_data;
}
size_t QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->_front == NULL;
}
int QueueSize(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->_front;
    int size = 0;
    while(cur)
    {
        ++size;
        cur = cur->_next;
    }
    return size;
}
void TestQueue()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    while(!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");
}
