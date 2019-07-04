#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>


using namespace std;
//链表中环的入口节点
//思路：设置快慢指针，先去寻找是否有环，寻找环中数量m，再让快指针现在链表中移动m步，
//接下来两指针相同速度间隔环的数量m移动，相遇节点便正好是环的入口
struct ListNode {
    int m_nValue;
    ListNode *m_pNext;

};

ListNode *MeetNode(ListNode *pHead)//寻找环，并定位到环中的某一节点

{
    if (pHead == nullptr)
        return nullptr;
    ListNode *pSlow = pHead->m_pNext;
    if (pSlow == nullptr)
        return nullptr;
    ListNode *pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow != nullptr) {
        if (pFast == pSlow)//二者在环中相遇
            return pFast;
        pSlow = pSlow->m_pNext;//快慢指针继续前进

        pFast = pFast->m_pNext;
        if (pFast != nullptr)
            pFast = pFast->m_pNext;


    }
    return nullptr;//说明无环

}

ListNode *EntryNodeOfLoop(ListNode *pHead) {
    ListNode *meetNode = MeetNode(pHead);
    if (meetNode == nullptr)
        return nullptr;//无环；


    int nodesLoop = 1;
    ListNode *pNode1 = meetNode;
    while (pNode1->m_pNext!=meetNode)//指针环内一圈来计算出环内节点数量
    {
        pNode1 = pNode1->m_pNext;
        ++nodesLoop;

    }

    //先移动pNode1,移动距离是nodesLoop(m)
    pNode1 = pHead;
    for (int i = 0; i < nodesLoop; ++i) {
        pNode1 = pNode1->m_pNext;
    }

    //再移动pNode2和pNode1;
    ListNode *pNode2 = pHead;

    while (pNode1 != pNode2) {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;//此时的相遇节点即是环的入口节点




}

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
   /* list[5].m_pNext = &list[3];*/
    list[5].m_pNext =NULL;
    //meetNode(list);
    if(EntryNodeOfLoop(list)== nullptr)
        cout<<"无环"<<endl;
    else
        cout<<"环的入口节点是"<<EntryNodeOfLoop(list)->m_nValue-1<<endl;


    return 0;
}


