#include <iostream>
#include<cstdio>
#include<stdio.h>

//找到中序遍历的下一个节点
 typedef struct BinaryTreeNode
{
    int data;
    BinaryTreeNode* lchild;
    BinaryTreeNode* rchild;
    BinaryTreeNode* parent;

}BTN;//定义结构体对象BinaryTreeNode/BTN

BTN * GetNext(BinaryTreeNode* pNode)
{
    if(pNode==nullptr)
        return nullptr;
    BTN* pNext=nullptr;
    if(pNode->rchild!= nullptr)//当前该节点具有右子树,则下一节点是右子树的最左子节点
    {
        BTN* pRight=pNode->rchild;
        while(pRight->lchild!= nullptr)//当前节点的右子树有左节点
            pRight=pRight->lchild;
        pNext=pRight;


    }
    else if(pNode->parent!= nullptr)
    {
        BTN* pCurrent=pNode;
        BTN* pParent=pNode->parent;
        while(pParent!= nullptr&&pCurrent==pParent->lchild)//该节点是其父节点的左子树
        {
            pCurrent=pParent;
            pParent=pNode->parent;

        }
        pNext=pParent;//中序遍历的下一个节点是父节点
        
    }
    return pNext;


}