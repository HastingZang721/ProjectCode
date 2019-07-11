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
 *二叉搜索树的后序遍历序列
 * 思路： 后序遍历最后一个数字是根节点，前一部分都比根节点小，是根的左子树部分，
 * 后一部分比根节点大，是右子树部分
 *
 */

struct BinaryTreeNode {
    int data;
    BinaryTreeNode *leftchild;
    BinaryTreeNode *rightchild;


};


class Solution{
public:
    bool VerifyPostorderOfBTS(int sequence[],int length)
    {
        if(sequence==NULL||length<=0)
            return false;
        int root=sequence[length-1];//后序遍历最后一个数字是根节点
        int i=0;
        for(;i<length-1;++i)
        {
            if(sequence[i]>root)
                break;

        }
        //二叉搜索树中右子树的节点都大于根节点
        int j=i;
        for(;j<length-1;++j)
        {
            if(sequence[j]<root)
                return  false;



        }

        //递归判断左右子树也是不是符合
        //判断左子树是不是二叉搜索树
        bool left=true;
        if(i>0)
            left=VerifyPostorderOfBTS(sequence,i);

        bool right=true;
        if(i<length-1)//存在右子树
            right=VerifyPostorderOfBTS(sequence+i,length-1-i);

        return (left&&right)







    }
};
