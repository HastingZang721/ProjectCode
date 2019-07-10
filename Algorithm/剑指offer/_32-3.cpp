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
 *之字型打印出二叉树
 * 两个棧
 * 当打印某一层节点时，将下一层的子节点保存在相应的棧
 * if（当前奇数层）：先保存左子节点再保存右子节点(因为下一层偶数层是先打印出右子节点的)
 * else:先保存右子节点再打印左子节点
 *
 */

struct BinaryTreeNode {
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;


};


void zhiPrint(BinaryTreeNode *pRoot) {
    if (pRoot == NULL)
        return;
    std::stack<BinaryTreeNode *> levels[2];
    int current = 0;
    int next = 1;
    levels[current].push(pRoot);
    while (!levels[0].empty() || !levels[1].empty()) {
        BinaryTreeNode *pNode = levels[current].top();
        levels[current].pop();
        cout << pNode->data;
        if (current == 0) {//当前层是奇数层
            if (pNode->left != nullptr)
                levels[next].push(pNode->left);
            if (pNode->right != nullptr)
                levels[next].push(pNode->right);

        }
        else //偶数层current==1
            {
            if (pNode->right != nullptr) {
                levels[next].push(pNode->right);


            }
            if(pNode->left!= nullptr)
            {
                levels[next].push(pNode->left);
            }
        }

        if(levels[current].empty())//当一层所有的节点都已经打印完时，交换这两个棧并继续打印下一层
        {
            current=1-current;
            next=1-next;

        }
    }


