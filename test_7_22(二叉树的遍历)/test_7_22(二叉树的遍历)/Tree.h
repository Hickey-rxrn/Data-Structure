//
//  Tree.h
//  test_7_22(二叉树的遍历)
//
//  Created by 张辉 on 2019/7/23.
//  Copyright © 2019年 张辉. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdlib.h>
#pragma once

typedef char BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* leftTree;
    struct BinaryTreeNode* rightTree;
    
}BTNode,*BiTree;


void BiTreeCreate(BiTree T);
BiTree BiTreeCreate1(void);
void BiTreeVisit(BiTree T);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);






#endif /* Tree_h */
