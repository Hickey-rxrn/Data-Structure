//
//  Stack.h
//  test_7_18(栈和队列)
//
//  Created by 张辉 on 2019/7/19.
//  Copyright © 2019年 张辉. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;
typedef struct Stack
{
    STDataType* _array;
    size_t _top;     //栈顶
    size_t _capacity;   //容量
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps,STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
size_t StackSize(Stack* ps);
void TestStack(void);






#endif /* Stack_h */
