/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /* 
    L1: a c
    L2: b c: 
    pointer1: a c then b: stop at intersection
    pointer2: b c then a: stop at intersection
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if ((!headA) || (!headB)) return nullptr;
        auto pA = headA;
        auto pB = headB;
        while (pA != pB)
        {
            if (!pA) pA = headB; else pA = pA->next;
            if (!pB) pB = headA; else pB = pB->next;
        }
        return pA;
    }

    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        if ((!headA) && (!headB)) return nullptr;
        auto pA = headA;
        auto pB = headB;
        while (pA != pB)
        {
            if (!pA) pA = headB; else pA = pA->next;
            if (!pB) pB = headA; else pB = pB->next;
        }
        return pA;
    }
};