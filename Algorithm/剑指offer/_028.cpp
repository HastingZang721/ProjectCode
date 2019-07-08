#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


using namespace std;
//对称的二叉树

/*两个树 树1的镜像就是树2 ，则树1 和树2 就是对称的
 * Mirror(pRoot1)==Tree2
 *
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

    bool isSymmetrical(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
    {
        if(pRoot1 == nullptr && pRoot2 == nullptr)
            return true;

        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        if(pRoot1->m_nValue != pRoot2->m_nValue)
            return false;
        return isSymmetrical(pRoot1->m_pLeft,pRoot2->m_pRight)&&
        isSymmetrical(pRoot1->m_pRight,pRoot2->m_pLeft);
        
    }
};


