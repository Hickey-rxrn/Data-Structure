//
//  main.c
//  test_7_19(二叉树)
//
//  Created by 张辉 on 2019/7/19.
//  Copyright © 2019年 张辉. All rights reserved.
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}

#include "Heap.h"


void HeapInit(Heap* hp,HPDataType* a,int n)
{
    hp->_a = malloc(sizeof(HPDataType)*n);
    memcpy(hp->_a,a,sizeof(HPDataType)*n);
    hp->_size = n;
    hp->_capacity = n;
    
    //构建堆
    for(int i = (n-1-1)/2; i>=0; i--)
    {
        AdjustDown(hp->_a, hp->_size, i);
    }
}

int Swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    return 0;
}

void AdjustDown(HPDataType* a,size_t n,size_t partent)
{
    size_t child = partent*2+1;
    while(child<n)
    {
        //选出两个孩子中较小的那个孩子
        if(child+1 < n && a[child+1] < a[child])
            ++child;
        
        //孩子小于父亲，则交换
        if(a[child] < a[partent])
        {
            Swap(a[child],a[partent]);
            partent = child;
            child = partent*2+1;
        }
        else
        {
            break;
        }
    }
}
