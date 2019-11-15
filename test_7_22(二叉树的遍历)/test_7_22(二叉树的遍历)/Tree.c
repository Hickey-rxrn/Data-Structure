//
//  Tree.c
//  test_7_22(二叉树的遍历)
//
//  Created by 张辉 on 2019/7/23.
//  Copyright © 2019年 张辉. All rights reserved.
//

#include "Tree.h"

BiTree BiTreeCreate1()
{
    char ch;
    BiTree T;
    scanf("%c",&ch);
    if(ch == '#')
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BTNode));
        T->data = ch;
        T->leftTree = BiTreeCreate1();
        T->rightTree = BiTreeCreate1();
    }
    return T;
}
void BiTreeVisit(BiTree T)
{
    printf("%c",T->data);
}
void PreOrder(BiTree T)
{
    if(T != NULL)
    {
        BiTreeVisit(T);
        PreOrder(T->leftTree);
        PreOrder(T->rightTree);
    }
}
void InOrder(BiTree T)
{
    if(T != NULL)
    {
        InOrder(T->leftTree);
        BiTreeVisit(T);
        InOrder(T->rightTree);
    }
}
void PostOrder(BiTree T)
{
    if(T != NULL)
    {
        PostOrder(T->leftTree);
        PostOrder(T->rightTree);
        BiTreeVisit(T);
    }

}
