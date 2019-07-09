lude<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include<deque>
using namespace std;

/*
 * 层次遍历二叉树
 * 一个队列，加入根元素，当需要出队的时候访问它
 *
 *
 */

struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;


};

void LevelOrder(BinaryTreeNode* pRoot)
{
    if(pRoot==NULL)
        return;
    std::deque<BinaryTreeNode*>deque1Tree;
    deque1Tree.push_back(pRoot);
    while(deque1Tree.size()!=NULL)

    {
        BinaryTreeNode* pNode=deque1Tree.front();//取对头元素
        deque1Tree.pop_front();//出对头
        cout<<pNode->data<<endl;
        if(pNode->left)
            deque1Tree.push_back(pNode->left);
        if(pNode->right)
            deque1Tree.push_back(pNode->right);
        
        


    }
}

