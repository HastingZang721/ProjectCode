#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//树的子结构
/*
 * 先判断是否具有一样的子树根节点的值；
 * 再判断是的包含和子树一样的结构
 *
 */
struct BinaryTreeNode {
    double m_dbValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

};

bool Equal(double num1, double num2) {
    if ((num1 - num2 > -0.000001) && (num1 - num2 < 0.000001))
        return true;
    else
        return false;

}

bool DoesTree1haveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2);

bool HasSubTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
//查询父亲树中是否含有有与 子树根节点 一样的节点
{
    bool result = false;
    if (pRoot1 != nullptr && pRoot2 != nullptr)//递归终止条件是：到达树1或者树2的叶节点
    {
        if (Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
            result = DoesTree1haveTree2(pRoot1, pRoot2);
        if (!result)
            result = HasSubTree(pRoot1->m_pLeft, pRoot2);
        if (!result)
            result = HasSubTree(pRoot1->m_pRight, pRoot2);

    }
    return result;


}

bool DoesTree1haveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
    //判断树1中以R为根节点的子树是不是和树2有一样的结构
    if (pRoot2 == nullptr)
        return true;//树2为空 ，返回true
    if (pRoot1== nullptr)
        return false;
    if(!Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))

        return false;
    return DoesTree1haveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft)&&
    DoesTree1haveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}