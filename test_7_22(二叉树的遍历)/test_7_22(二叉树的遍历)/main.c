//
//  main.c
//  test_7_22(二叉树的遍历)
//
//  Created by 张辉 on 2019/7/23.
//  Copyright © 2019年 张辉. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}

int main()
{
    BiTree T;
    printf("please input the tree node:\n");
    T = BiTreeCreate1();
    printf("the PreOrder node:\n");
    PreOrder(T);
    printf("\nthe InOrder node:\n");
    InOrder(T);
    printf("\nthe PostOrder node:\n");
    PostOrder(T);
    //printf("\nthe LevelOrder node:\n");
   // LevelOrder(T);
    printf("\n");
    return 0;
}
