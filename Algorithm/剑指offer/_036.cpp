#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include <queue>

using namespace std;

/*
 *将输入的二叉搜索数转换成一个排序的双向链表
 *
 * 二叉排序树的左节点的值 < 根结点的值 < 右子节点的值，其中序遍历就是一个排序好的信息串
 */

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* left;
    BinaryTreeNode* Right;

};

class SOlution{
public:
    void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeinList);
    BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree);

};

BinaryTreeNode* SOlution::Convert(BinaryTreeNode *pRootOfTree) {
    BinaryTreeNode* pLastNodeinList= nullptr;//用于指向已经转换好的链表中最后一个节点（值最大的节点）//中序遍历中指向前一个节点的指针
    ConvertNode(pRootOfTree,&pLastNodeinList);

    //返回头节点
    BinaryTreeNode* pHeadOfList=pLastNodeinList;
    while(pHeadOfList!= nullptr&&pHeadOfList->left!=nullptr)
        pHeadOfList=pHeadOfList->left;
    return pHeadOfList;
}

void SOlution::ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeinList) {//递归的将PNode为根的二叉排序树专户才能成双向链表]
    if(pNode== nullptr)
        return ;
    BinaryTreeNode* pCurrent=pNode;//pCUrrent 想指向当前的根节点
    if(pCurrent->left!= nullptr)
        ConvertNode(pCurrent->left,pLastNodeinList);

    pCurrent->left=*pLastNodeinList;//将左子树的最大值与当前根节点相连接
    if(pLastNodeinList!= nullptr)
        (*pLastNodeinList)->Right=pCurrent;

    *pLastNodeinList=pCurrent;//此时根节点就是链表上最大值

    if(pCurrent->Right!= nullptr)//中序遍历
        ConvertNode(pCurrent->Right,pLastNodeinList);


}

