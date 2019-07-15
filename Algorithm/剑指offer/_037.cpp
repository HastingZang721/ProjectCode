#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<istream>


#include <queue>

using namespace std;

/*
 *序列化二叉树
 * 将二叉树转化成一个前序遍历和中序遍历
 *
 */

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* left;
    BinaryTreeNode* Right;

};

//序列化
void Serialize(BinaryTreeNode* pRoot,ostream& stream)//还需要输出流
{
    if(pRoot== nullptr)
    {
        stream<<"$,";
        return ;

    }

    stream<<pRoot->m_nValue<<',';
    Serialize(pRoot->left,stream);
    Serialize(pRoot->Right,stream);

}

//反序列化
void Deserialize(BinaryTreeNode** pRoot,istream& stream)
{
    int number;
    if(ReadStream(stream,&number))//从流中读出一个数字或者字符$
        
    {
        *pRoot=new BinaryTreeNode();
        (*pRoot)->m_nValue=number;
        (*pRoot)->left= nullptr;
        (*pRoot)->Right= nullptr;
        
        Deserialize(&(*pRoot)->left,stream);
        Deserialize(&(*pRoot)->Right,stream);
        
        
    }
}