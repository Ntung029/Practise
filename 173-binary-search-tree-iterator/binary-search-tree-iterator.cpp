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


class BSTIterator{
    public:
       BSTIterator(TreeNode* root)
       {
            DFSHelper(root);
       }

       bool hasNext()
       {
            return !st.empty();
       }

       int next()
       {
            if (st.empty()) return INT32_MIN;

            auto curr = st.top();
            st.pop();

            if (curr->right)
            {
                DFSHelper(curr->right);
            }

            return curr->val;
       }

    private:
        stack<TreeNode*> st;
        void DFSHelper(TreeNode* root)
        {
            auto curr = root;
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
        }
};

class BSTIterator11{
public:
    BSTIterator11(TreeNode* root)
    {
        DFSHelper(root);
    }

    int next()
    {
        auto curr = st.top();
        st.pop();

        if (curr->right)
        {
            DFSHelper(curr->right);
        }
        return curr->val;
    }

    bool hasNext()
    {
        return (!st.empty());
    }

private:
    stack<TreeNode*> st;
    void DFSHelper(TreeNode* root)
    {
        auto curr = root;
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
    }
};

class BSTIterator7{
public:
    BSTIterator7(TreeNode* root)
    {
        DFSHelper(root);   
    }
    
    int next()
    {
        auto curr = st.top();
        st.pop();
        if (curr->right)
        {
            DFSHelper(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext()
    {
        return (!st.empty());
    }
    
    
private:
    stack<TreeNode*> st;
    void DFSHelper(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root= root->left;
        }
    }
};


class BSTIterator6 {
public:
    BSTIterator6(TreeNode* root) {
        leftMostTraverse(root);
    }
    
    bool hasNext()
    {   
        return (!st.empty());
    }

    int next()
    {
        auto curr = st.top();
        st.pop();
        if (curr->right)
        {
            leftMostTraverse(curr->right);
        }
        
        return curr->val;
    }


    
private:
    stack<TreeNode*> st;
    void leftMostTraverse(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};



class BSTIterator10 {
public:
    BSTIterator10(TreeNode* root) {
        leftMostTraverse(root);
    }
    
    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {
        auto curr = st.top();
        st.pop();
        if (curr->right)
        {
            leftMostTraverse(curr->right);   
        }
        return curr->val;
    }


    
private:
    stack<TreeNode*> st;

    void leftMostTraverse(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

};


class BSTIterator2 {
public:
    BSTIterator2(TreeNode* root) {
        leftMostInorder(root);
    }
    
    int next() {
        auto curr = st.top();
        st.pop();
        if (curr->right)
        {
            leftMostInorder(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
private:
    stack<TreeNode*> st;
    void leftMostInorder(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */