/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int getHeight(Node *p)
    {
        int ret = 0;
        while (p)
        {
            p = p->parent;
            ret++;
        }
        return ret;
    }


    Node* lowestCommonAncestor3(Node* p, Node * q) {
        auto cP = p;
        auto cQ = q;
        int hP = getHeight(cP);
        int hQ = getHeight(cQ);
        if (hP < hQ) 
        {
            swap(p,q);
            swap(hP,hQ);
        }
        // hP > hQ
        // move p node to be at the same height as q node
        while ((hP>hQ) && (nullptr != p))
        {
            p = p->parent;
            hP--;
        }

        while ((p != q) && (p) && (q))
        {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }

    
    void visit(Node *curr, unordered_set<Node*> &visited)
    {
        if (curr == nullptr)
        {
            return;
        }
        visited.insert(curr);
        visit(curr->parent,visited);
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        std::unordered_set<Node*> visited;
        visit(p,visited);
        while (q != nullptr)
        {
            if (visited.end() != visited.find(q))
            {
                return q;
            }
            q = q->parent;
        }
        return nullptr;
    }
};