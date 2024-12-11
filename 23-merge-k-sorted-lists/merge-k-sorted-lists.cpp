/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findMin(vector<ListNode*>& lists) {
        int ret = INT32_MAX;
        int ii = -1;
        for (int i = 0; i< lists.size(); i++)
        {
            if ((lists[i]) && (lists[i]->val < ret))
            {
                ii = i;
                ret = lists[i]->val;
            }
        }
        return ii;
    }
    
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(0);
        ListNode* curr = root;
        while (true)
        {
            int i = findMin(lists);
            if (i == -1) break;
            curr->next = lists[i];
            lists[i] = lists[i]->next;
            curr = curr -> next;
            
        }
        return root->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists){
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> qu(comp);
        for (auto l:lists)
        {
            if (l) qu.push(l);
        }

        auto root = new ListNode(0);
        auto curr = root;
        while (!qu.empty())
        {
            curr->next = qu.top();
            qu.pop();
            curr = curr->next;
            if (curr->next)
            {
                qu.push(curr->next);
            }
        }
        return root->next;
    }
};