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

class Solution{
public:
    TreeNode* last =nullptr;

    void DFS(TreeNode* root)
    {
        if (!root) return;
        auto left = root->left;
        auto right = root->right;
        if (last)
        {
            last->right = root;
            last->left = nullptr;
        }
        last = root;
        DFS(left);
        DFS(right);
    }
    void flatten (TreeNode* root)
    {
       DFS(root);
    }
};

 class SolutionM{
    public:
    TreeNode* last;
    TreeNode* head;

    void flatten(TreeNode* root) {
        last = nullptr;
        head = nullptr;
        DFS(root);
    }

    void DFS(TreeNode* root){
        if (nullptr == root);
        auto left = root->left;
        auto right = root->right;

        if (nullptr == last) head = root;
        else
        {
            last->right = root;
            last->left = nullptr;
        }
        last = root;
        DFS(left);
        DFS(right);
    }
 };

class Solutionx{
    public:
    
    void flatten(TreeNode* root) {
        last = nullptr;
        head = nullptr;
        DFS(root);
    }
    private:
        TreeNode* last;
        TreeNode* head;
    void DFS(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }
        
        auto left = root->left;
        auto right = root->right;
        
        if (nullptr == last)
        {
            head = last;
        }
        else
        {
            last->right = root;
            last->left = nullptr;
        }
        last = root;
        DFS(left);
        DFS(right);
    }
};


class Solution13{
    public:
    TreeNode* head;
    TreeNode* last;
    void DFS(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }
        
        auto left = root->left;
        auto right = root->right;
        
        if (nullptr == last)
        {
            head = root;
        }
        else
        {
            last->right = root;
            last->left = nullptr;
        }
        
        last = root;
        DFS(left);
        DFS(right);
    }
    
    
    void flatten(TreeNode* root) {
        last = nullptr;
        head = nullptr;
        DFS(root);
    }

};



class Solution6{
public:
    TreeNode* last;
    TreeNode* head;
    
    void DFS(TreeNode* root) {
        if (nullptr == root)
        {
            return;
        }
        
        auto left = root->left;
        auto right = root->right;
        
        if (last)
        {
            last->right = root;
            last->left = nullptr;
        }
        else
        {
            head = root;
        }
        
        last = root;
        
        DFS(left);
        DFS(right);
    }
    void flatten(TreeNode* root) {
        last = nullptr;
        head = nullptr;
        DFS(root);
    }
};

class Solution5{
public:
    void DFS(TreeNode* root)
    {
        if (nullptr == root) return;
        auto left = root->left;
        auto right = root->right;
        if (last)
        {
            last->right = root;
            last->left = nullptr;
        }
        else
        {
            head = root;
        }
        last = root;
        DFS(left);
        DFS(right);

    }
    void flatten(TreeNode* root) {
        head = nullptr;
        last = nullptr;
        DFS(root);
    }


private:
    TreeNode* head; // to be return
    TreeNode* last; // last visited node
};


class Solution2 {
public:
    TreeNode* head;
    TreeNode* last;
    
    void DFS(TreeNode* root)
    {
        if (root)
        {
            TreeNode* right = root->right;
            TreeNode* left = root->left;
            if (last)
            {
                last->right = root;
                last->left = nullptr;
            }
            else
            {
                head = root;
            }
            last = root;
            DFS(left);
            DFS(right);
        }
    }
    void flatten(TreeNode* root) {
        head = nullptr;
        last = nullptr;
        DFS(root);
    }
};