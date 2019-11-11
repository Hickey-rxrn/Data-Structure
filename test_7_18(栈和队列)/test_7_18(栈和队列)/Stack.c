//
//  Stack.c
//  test_7_18(栈和队列)
//
//  Created by 张辉 on 2019/7/19.
//  Copyright © 2019年 张辉. All rights reserved.
//

#include "Stack.h"


void StackInit(Stack* ps)
{
    assert(ps);
    ps->_array =NULL;
    ps->_top = 0;
    ps->_capacity = 0;
}
void StackDestory(Stack* ps)
{
    assert(ps);
    if(ps->_array != NULL)
    {
        free(ps->_array);
        ps->_array = NULL;
        ps->_top = 0;
        ps->_capacity = 0;
    }
}
void StackPush(Stack* ps,STDataType x)
{
    assert(ps);
    if(ps->_top == ps->_capacity)
    {
     size_t newcapacity = ps->_capacity==0 ? 2 : ps->_capacity * 2;
        ps->_array = (STDataType*)realloc(ps->_array,newcapacity*sizeof(STDataType));
        ps->_capacity = newcapacity;
    }
    ps->_array[ps->_top] = x;
    ps->_top ++;
}
void StackPop(Stack* ps)
{
    assert(ps && ps->_top > 0);
    --ps->_top;
}
STDataType StackTop(Stack* ps)
{
    assert(ps && ps->_top > 0);
    return ps->_array[ps->_top-1];
}
int StackEmpty(Stack* ps)
{
    assert(ps);
    return ps->_top == 0;
}
size_t StackSize(Stack* ps)
{
    assert(ps);
    
    return ps->_top;
}

void TestStack()
{
    Stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackPush(&s, 3);
    StackPush(&s, 4);
    while(!StackEmpty(&s))
    {
        printf("%d ",StackTop(&s));
        StackPop(&s);
    }
    StackDestory(&s);
    printf("\n");
}
