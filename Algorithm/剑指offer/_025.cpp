#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//合并两个排序的链表

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;

};

class Solution {
public :
    ListNode *MergeTwoList(ListNode *pLeft, ListNode *pRight) {
        if (pLeft == nullptr) {//边界值检测
            cout << "left list is NULL" << endl;
            return pRight;
        }
        else if(pRight== nullptr)
        {
            cout<<"right list is NUll"<<endl;
            return pLeft;

        }

        ListNode *head=NULL;
        if(pLeft->m_nValue<pRight->m_nValue)
        {
            head=pLeft;
            head->m_pNext=MergeTwoList(pLeft->m_pNext,pRight);
        }
        else
        {
            head=pRight;
            head->m_pNext=MergeTwoList(pLeft,pRight->m_pNext);

        }
        return head;
    }
};

int main(){
    ListNode left1[2],left2,right1[3];
    left1[0].m_nValue=3;
    left1[0].m_pNext=&left1[1];
    left1[1].m_nValue=5;
    left1[1].m_pNext=NULL;
    left2.m_nValue=3;
    left2.m_pNext=NULL;




    right1[0].m_nValue = 1;
    right1[0].m_pNext = &right1[1];
    right1[1].m_nValue = 2;
    right1[1].m_pNext = &right1[2];
    right1[2].m_nValue= 4;
    right1[2].m_pNext = NULL;
    Solution solu;
    ListNode* node;
    //node=solu.MergeTwoList(left1,right1);
    node=solu.MergeTwoList(&left2,right1);
    while(node!=NULL)
    {
        cout<<node->m_nValue<<" ";
        node=node->m_pNext;
    }
    cout<<endl;



    return 0;
}
