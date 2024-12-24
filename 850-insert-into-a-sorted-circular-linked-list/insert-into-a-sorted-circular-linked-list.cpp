/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (nullptr == head)
        {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        auto ret = head;

        auto prev = head;
        auto curr = head->next;
        while (curr != head)
        {
            if ((curr->val >= insertVal) && (prev->val <= insertVal))
            {
                prev->next = new Node(insertVal);
                prev = prev->next;
                prev->next = curr;
                return head;
            }
            else if (curr->val<prev->val)
            {
                if ((insertVal<=curr->val) || (insertVal>=prev->val))
                {
                    prev->next = new Node(insertVal);
                    prev = prev->next;
                    prev->next = curr;
                    return head;
                }
                
            }
            prev = curr;
            curr = curr->next;
        }

        prev->next = new Node(insertVal);
        prev = prev->next;
        prev->next = curr;
        return head;
    }
};