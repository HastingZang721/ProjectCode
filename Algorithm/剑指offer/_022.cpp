e<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//链表倒数第K个节点
//思路： 倒数第K个节点，即正数第n-(k-1)
struct ListNode {
public:

    int m_nValue;
    ListNode *m_pNext;

};

class Solution {
public:
    ListNode *FindKthFromEnd(ListNode *p, unsigned int k) {
        if (p == nullptr || k == 0)//边界值检测
            return nullptr;
        ListNode *pAhead = p;
        ListNode *pBehind = nullptr;//双指针 初始化，两指针相差k-1；
        for (unsigned int i = 0; i < k - 1; i++)
            if (pAhead->m_pNext != nullptr)//未扫描到结尾
                pAhead = pAhead->m_pNext;
            else {
                return nullptr;

            }
        pBehind = p;
        while (pAhead->m_pNext != nullptr)//当pAhead指向末尾时，pBehind 正好指向倒数第K个节点
        {
            pAhead = pAhead->m_pNext;
            pBehind = pBehind->m_pNext;


        }
        return  pBehind;

    }

};

int main() {
    ListNode list[6];
    list[0].m_nValue = 1;
    list[0].m_pNext = &list[1];
    list[1].m_nValue = 2;
    list[1].m_pNext = &list[2];
    list[2].m_nValue = 3;
    list[2].m_pNext = &list[3];
    list[3].m_nValue = 4;
    list[3].m_pNext = &list[4];
    list[4].m_nValue = 5;
    list[4].m_pNext = &list[5];
    list[5].m_nValue = 6;
    list[5].m_pNext =NULL;

    Solution solu;
    cout<<solu.FindKthFromEnd(list,2)->m_nValue;
    return 0;

}

