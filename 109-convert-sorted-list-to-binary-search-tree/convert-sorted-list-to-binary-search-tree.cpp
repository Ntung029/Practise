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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head)
    {
        ListNode* prev = nullptr;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // disconnect prev to slow
        if (prev && prev->next)
        {
            prev->next = nullptr;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // find mid of the list
        // head-> ...prev /-> mid /-> mid->next ...->end
        // disconnect
        // find mid left, find mid right

        if (nullptr == head) return nullptr;
        auto mid = this->findMid(head);
        auto node = new TreeNode(mid->val);
        if (head == mid) return node;
        node->left = this->sortedListToBST(head);
        node->right = this->sortedListToBST(mid->next);
        return node;
    }
};