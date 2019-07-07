#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


using namespace std;
//二叉树的镜像
/*
 * 其实就是交换非叶子节点的值
 *
 */
struct BinaryTreeNode {
    double m_dbValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

};
template <class T>
void swap(T &x,T &y)

{
    T temp=x;
    x=y;
    y=temp;



}

//解法1 递归
class SOlution1{
public:
    void Mirror(BinaryTreeNode* pRoot)
    {
        if(pRoot==NULL)
            return ;
        swap(pRoot->m_pLeft,pRoot->m_pRight);
        Mirror(pRoot->m_pLeft);
        Mirror(pRoot->m_pRight);

    }
};

//解法2 中序遍历非递归
class Solution
{
public:
    void MirrorIn(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return NULL;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        //  开始遍历整个二叉树
        while(node != NULL || nstack.empty() != true)
        {
            // 不输出当前根节点，但是递归直至当前根节点node的最左端
            while(node != NULL)
            {
                nstack.push(node);
                node = node->left;
            }

            //  此时栈顶的元素是当前最左元素
            //  它应该被输出
            if(nstack.empty( ) != true)
            {
                node = nstack.top( );

                //  将原来的输出改为交换左右子树即可
                if(node->left != NULL || node->right != NULL)
                {
                    swap(node->left, node->right);
                }

                nstack.pop( );
                //  中序遍历输出根后，向右转向
                //  此时由于左右子树交换，因此原来的右子树是其左子树，向左转向
                node = node->left;
            }
        }
    }

};





