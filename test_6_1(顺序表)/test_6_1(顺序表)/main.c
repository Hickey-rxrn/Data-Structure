//
//  main.c
//  test_6_1(顺序表)
//
//  Created by 张辉 on 2019/11/9.
//  Copyright © 2019 可乐. All rights reserved.
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
#include "SeqList.h"
void TestSeqList1()
{
    SeqList s1;
    SeqListInit(&s1);
    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPushBack(&s1, 4);
    SeqListPopBack(&s1);
    SeqListPopFront(&s1);
    for(size_t i = 0; i < SeqListSize(&s1); ++i)
    {
        printf("%zu ", SeqListAt(&s1, i));
    }
    printf("\n");
    SeqListDestory(&s1);
}
void TestList2()
{
    SeqList s2;
    SeqListInit(&s2);
    SeqListPushBack(&s2, 1);
    SeqListPushBack(&s2, 2);
    SeqListPushBack(&s2, 3);
    SeqListPushBack(&s2, 4);
    SeqListInsert(&s2, 1, 20);
    SeqListInsert(&s2, 3, 30);
    for(size_t i = 0; i < SeqListSize(&s2); ++i)
    {
        printf("%zu ", SeqListAt(&s2, i));
    }
    printf("\n");
    SeqListErase(&s2, 1);
    SeqListErase(&s2, 2);
    for(size_t i = 0; i < SeqListSize(&s2); ++i)
    {
        printf("%zu ", SeqListAt(&s2, i));
    }
    printf("\n");
}
int main()
{
    //TestSeqList1();
    TestList2();
    return 0;
}
