//
//  Heap.h
//  test_7_19(二叉树)
//
//  Created by 张辉 on 2019/7/19.
//  Copyright © 2019年 张辉. All rights reserved.
//

#ifndef Heap_h
#define Heap_h


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int HPDataType;
typedef struct Heap{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;

void AdjustDown(HPDataType* a,size_t n,size_t partent);
void HeapInit(Heap* hp,HPDataType* a,int n);





#endif /* Heap_h */
