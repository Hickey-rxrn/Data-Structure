//
//  SeqList.h
//  test_6_1(顺序表)
//
//  Created by 张辉 on 2019/11/9.
//  Copyright © 2019 可乐. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h


#pragma once
#include <stdio.h>
#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int DataType;

typedef struct SeqList
{
    DataType* _array;
    size_t _size;
    size_t _capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPopBack(SeqList* ps);
void SeqListPushBack(SeqList* ps,DataType x);
void SeqListPushFront(SeqList* ps,DataType x);
void SeqListPopFront(SeqList* ps);
void SeqListInsert(SeqList* ps,size_t pos,DataType x);
void SeqListErase(SeqList* ps,size_t pos);
size_t SeqListSize(SeqList* ps);
size_t SeqListFind(SeqList* ps,DataType x);
size_t SeqListAt(SeqList* ps, size_t pos);
#endif /* SeqList_h */
