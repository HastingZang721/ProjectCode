#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>

using namespace std;
//删除链表中重复的节点
//计数法


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x = 0)
            :
            val(x), next(NULL) {
    }
};

class Solution_2 {
public:
    ListNode *deleteDupliation(ListNode *pHead) {
        ListNode L(-1);
        ListNode *newNode = &L;//newNode 指向tail
        ListNode *preNode = NULL;
        ListNode *pNode = pHead;
        int count;
        while (pNode != NULL) {
            preNode = pNode;
            pNode = pNode->next;
            count = 0;


            //对preNode 与pNode 相等的情况进行计数
            while (pNode && pNode->val == preNode->val) {
                pNode = pNode->next;
                count++;


            }
            if (count == 0) {
                //若无重复
                //则将不重复的数字节点接到链表的末尾
                //将preNode 连接到newNode（tail） 的末尾
                newNode->next = preNode;
                newNode = preNode;//并将preNode节点设置为新的尾节点



            }


        }
        newNode->next = NULL;
        return L.next;//返回头部节点
    }
};


int main() {
    Solution_2 solu;

    ListNode list[7];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 3;
    list[3].next = &list[4];

    list[4].val = 4;
    list[4].next = &list[5];

    list[5].val = 4;
    list[5].next = &list[6];

    list[6].val = 5;
    list[6].next = NULL;


    ListNode *node = solu.deleteDupliation(list);

    while (node != NULL) {
        cout << node->val << " -=> ";
        node = node->next;
    }
    return 0;
