//
//  list.c
//  test_7_13
//
//  Created by 张辉 on 2019/7/16.
//  Copyright © 2019年 张辉. All rights reserved.
//

#include "List.h"


void ListInit(List* plt)   //链表初始化
{
    assert(plt);
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->_next = head;
    head->_prev = head;
    plt->_head = head;
}


ListNode* BuyListNode(LTDataType x)   // 创建一个节点
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->_next = NULL;
    node->_prev = NULL;
    node->_data = x;
    return node;
}
void ListDestory(List* plt)   //链表的销毁
{
    assert(plt);
    ListNode* head = plt->_head;
    ListNode* cur = head->_next;
    while(cur != head)
    {
        ListNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    plt->_head = NULL;
}
void ListPushBack(List* plt,LTDataType x)  //尾插
{
    assert(plt);
    
    ListNode* head = plt->_head;
    ListNode* tail = head->_prev;
    ListNode* newnode = BuyListNode(x);
    
    // head    ==== tail  newnode
    tail->_next = newnode;
    newnode->_prev = tail;
    
    head->_prev = newnode;
    newnode->_next = head;
    
    //ListInsert(plt->_head, x);
}
void ListPopBack(List* plt)     //尾删
{
    assert(plt);
    ListNode* head = plt->_head;
    assert(head->_next != head);
    ListNode* tail = head->_prev;
    ListNode* prev = tail->_prev;
    free(tail);
    prev->_next = head;
    head->_prev = prev;
   // ListErase(head->_prev);
}
void ListPushFront(List* plt,LTDataType x)   //头插
{
    assert(plt);
    ListNode* head = plt->_head;
    ListNode* first = head->_next;
    ListNode* newnode = BuyListNode(x);
    head->_next = newnode;
    newnode->_prev = head;
    newnode->_next = first;
    first->_prev = newnode;
    //ListInsert(plt->_head->_next, x);
}
void ListPopFront(List* plt)    //头删
{
    assert(plt);
    ListNode* head = plt->_head;
    assert(head->_next != head);
    ListNode* first = head->_next;
    ListNode* second = first->_next;
    free(first);
    head->_next = second;
    second->_prev = head;
    //ListErase(head->_next);
}
ListNode* ListFind(List* plt, LTDataType x)   //寻找链表中某节点
{
    assert(plt);
    ListNode* head = plt->_head;
    ListNode* cur = head->_next;
    while(cur != head)
    {
        if(cur->_data == x)
        {
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)// 在pos的前面进行插入
{
    assert(pos);
    ListNode* prev = pos->_prev;
    ListNode* newnode = BuyListNode(x);
    
    //prev newnode pos
    
    prev->_next = newnode;
    newnode->_prev = prev;
    newnode->_next = pos;
    pos->_prev = newnode;
}
void ListErase(ListNode* pos)// 删除pos位置的节点
{
    ListNode* prev = pos->_prev;
    ListNode* next = pos->_next;
    free(pos);
    prev->_next = next;
    next->_prev = prev;
}
void ListPrint(List* plt)    //打印链表
{
    assert(plt);
    ListNode* head = plt->_head;
    ListNode* cur = head->_next;
    
    printf("head");
    while (cur != head)
    {
        printf("<=>%d", cur->_data);
        cur = cur->_next;
    }
    printf("\n");
}
void ListTest()
{
    List lt;
    ListInit(&lt);
    ListPushBack(&lt,1);
    ListPushBack(&lt,2);
    ListPushBack(&lt,3);
    ListPushBack(&lt,4);
    ListPushBack(&lt,5);
    ListPrint(&lt);
    ListPopFront(&lt);
    ListPopBack(&lt);
    ListPrint(&lt);
    ListPushFront(&lt, 9);
    ListPrint(&lt);
}
