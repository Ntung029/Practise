/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;
    void DFSHelper(Node* root)
    {
        if(!root) return;
        DFSHelper(root->left);
        if (last)
        {
            last->right = root;
            root->left = last;
        }
        else
        {
            first = root;
        }
        last = root;
        DFSHelper(root->right);
    }

    Node* treeToDoublyList(Node* root)
    {
        if (nullptr == root) return root;
        DFSHelper(root);
        last->right = first;
        first->left = last;
        return first;
    }
};

class Solution21 {
public:
    Node* first = nullptr; // smallest
	Node* prev = nullptr; // largest

    //using stack
    // travel to left most
	void DFSHelper(Node* root)
    {
        auto curr = root;
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
    }

    Node* treeToDoublyList(Node* root){
        if (nullptr == root) return nullptr;
        DFSHelper(root);
        first = st.top();
        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();
            prev = curr;
            if (curr->right)
            {
                DFSHelper(curr->right);
            }
            if (!st.empty())
            {
               // cout << "stTop" << st.top()->val << endl;
                st.top()->left = prev;
                prev->right = st.top();
            }
        }
        prev->right =first;
        first->left = prev;
        return first;
    }

    private:
    stack<Node*> st;
};

class Solution19 {
public:
    Node* treeToDoublyList19(Node* root){
        last = nullptr;
        head = nullptr;
        if (nullptr == root) return nullptr;
        DFS(root);
        last->right = head;
        head->left = last;
        return head;
    }
private:
    Node* last;
    Node* head;
    void DFS(Node* root)
    {
        if (nullptr == root) return;
        DFS(root->left);
        if (nullptr == last)
        {
            head = root;
        }
        else
        {
            last->right = root;
            root->left = last;
        }
        last = root;
        DFS(root->right);
    }

};

class Solution17 {
public:
    void DFSHelper(Node* root,stack<Node*>& st)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
    Node* treeToDoublyList(Node* root){
        // iterator
        if (nullptr == root) return nullptr;
        Node* prev = nullptr;
        Node* head = nullptr;
        stack<Node*> st;
        
        // DFS pre-order
        DFSHelper(root,st);

        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();
            cout << curr->val <<  endl;

            if (nullptr == prev)
            {
                head = curr;
            }
            else
            {
                prev->right = curr;
                curr->left = prev;
            }
            prev = curr;

            if (curr->right)
            {
                DFSHelper(curr->right,st);
            }
        }
        head->left = prev;
        prev->right = head;
        return head;
    }
};

class Solution13 {
public:
    Node* last;
    Node* head;
    
    void DFS(Node* root)
    {
        if (nullptr == root) return;
        if (root->left)
        {
            DFS(root->left);
        }
        
        
        // get the head node
        if (nullptr == last)
        {
            head = root;
        }
        
        if (last)
        {
            last->right = root;
            
            root->left = last;
        }
        
        last = root;
        
        if (root->right)
        {
            DFS(root->right);
        }
    }
    
    Node* treeToDoublyList(Node* root){
        last = nullptr;
        head = nullptr;
        if (nullptr == root) return head;
        DFS(root);
        // update last and head
        last->right = head;
        head->left = last;
        
        return head;
    }
};

class Solution11 {
public:
    Node* last = nullptr;
    Node* first = nullptr;
    void DFS (Node* root)
    {
        if (nullptr == root) return;
        DFS(root->left);
        if (nullptr == last)
        {
            first = root;
        }
        else
        {
            root->left = last;
            last->right = root;
            last = root;
        }
        last = root;
        DFS(root->right);
    }
    Node* treeToDoublyList(Node* root){
        if (nullptr == root) return nullptr;
        DFS(root);
        first->left = last;
        last->right = first;
        return first;
    }
};


class Solution7 {
public:
    
    Node* last = nullptr;
    Node* head = nullptr;
    
    void DFS(Node* root)
    {
        if (nullptr == root) return;
        DFS(root->left);
        if (nullptr == last)
        {
            head = root;
        }
        else
        {
            last->right = root;
            root->left = last;
        }
        last = root;
        DFS(root->right);
    }
    
    Node* treeToDoublyList(Node* root){
        DFS(root);
        last->right = head;
        head->left = last;
        return head;
    }
};



class Solution2 {
public:
    Node* first = nullptr; // smallest
    Node* last = nullptr; // largest

    void helper(Node* root)
    {
        if (root)
        {
            helper(root->left);
        

            if (last)
            {
                last->right = root;
                root->left = last;
            }
            else
            {
                first = root;
            }

            last = root;
            helper(root->right);
        }
    }

    Node* treeToDoublyList(Node* root) {
        if (nullptr == root) return root;
        helper(root);
        // close DLL
        last->right = first;
        first->left = last;
        return first;

    }
};