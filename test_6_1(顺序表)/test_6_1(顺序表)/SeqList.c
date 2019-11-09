//
//  SeqList.c
//  test_6_1(顺序表)
//
//  Created by 张辉 on 2019/11/9.
//  Copyright © 2019 可乐. All rights reserved.
//

#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
    assert(ps);
    ps->_array = NULL;
    ps->_size = 0;
    ps->_capacity = 0;
}
void SeqListDestory(SeqList* ps)
{
    assert(ps);
    if(ps->_array)
    {
        free(ps->_array);
        ps->_array = NULL;
        ps->_capacity = ps->_size = 0;
    }
}
// 增容
void SeqListCheckCapacity(SeqList* ps)
{
    assert(ps);
    if(ps->_size == ps->_capacity)
    {
        size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
        ps->_array = realloc(ps->_array,newcapacity);
        assert(ps->_array);
        ps->_capacity = newcapacity;
    }
}
void SeqListPushBack(SeqList* ps,DataType x)
{
//    SeqListCheckCapacity(ps);
//    assert(ps);
//    ps->_array[ps->_size] = x;
//    ps->_size++;
    //复用
    SeqListInsert(ps, ps->_size, x);

}
void SeqListPushFront(SeqList* ps,DataType x)
{
//    assert(ps);
//    SeqListCheckCapacity(ps);
//    size_t end = ps->_size;
//    while(end >= 0)
//    {
//        ps->_array[end] = ps->_array[end - 1];
//        --end;
//    }
//    ps->_array[0] = x;
//    ps->_size++;
    SeqListInsert(ps, 0, x);
}
void SeqListPopBack(SeqList* ps)
{
//    assert(ps && ps->_size > 0);
//    --ps->_size;
    //复用
    SeqListErase(ps, ps->_size - 1);
}
void SeqListPopFront(SeqList* ps)
{
//    assert(ps);
//    size_t start = 1;
//    while(start < ps->_size)
//    {
//        ps->_array[start - 1] = ps->_array[start];
//        ++start;
//    }
//    --ps->_size;
    SeqListErase(ps, 0);
}
void SeqListInsert(SeqList* ps,size_t pos,DataType x)
{
    assert(ps && pos <= ps->_size);
    SeqListCheckCapacity(ps);
//    size_t end = ps->_size - 1;
//    while(end >= (int)pos)
//    {
//        ps->_array[end + 1] = ps->_array[end];
//        --end;
//    }
    size_t end = ps->_size;
    while(end > pos)
    {
        ps->_array[end] = ps->_array[end - 1];
        --end;
    }
    ps->_array[pos] = x;
    ps->_size++;
}
void SeqListErase(SeqList* ps,size_t pos)
{
    assert(ps && pos < ps->_size);
//    size_t start = pos;
//    while(start < ps->_size - 1)
//    {
//        ps->_array[start] = ps->_array[start + 1];
//        ++start;
//    }
    size_t start = pos + 1;
    while(start < ps->_size)
    {
        ps->_array[start - 1] = ps->_array[start];
        ++start;
    }
    ps->_size--;
}
size_t SeqListSize(SeqList* ps)
{
    assert(ps);
    return ps->_size;
}
size_t SeqListFind(SeqList* ps,DataType x)
{
    assert(ps);
    for(size_t i = 0; i < ps->_size; ++i)
    {
        if(x == ps->_array[i])
        {
            return i;
        }
    }
    return -1;
}
size_t SeqListAt(SeqList* ps, size_t pos)
{
    assert(ps);
    return ps->_array[pos];
}

