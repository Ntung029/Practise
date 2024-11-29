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
    
    
       
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if (nullptr == root) return result;
        queue<TreeNode*> qu;
        qu.push(root);
        
        
        while (!qu.empty())
        {
            result.push_back(qu.front()->val); // first node of the new level
            int n = qu.size();
            for (int i = 0; i<n; i++)
            {
                auto curr = qu.front();
                qu.pop();
                
                if (curr->right)
                {
                    qu.push(curr->right);
                }
                
                if (curr->left)
                {
                    qu.push(curr->left);
                }
            }
            
        }
        
        return result;
    }
};

class Solution7 {
public:
    void rightSideView(TreeNode* root, int level, vector<int>& result)
    {
        if (level == result.size())
        {
            result.push_back(root->val);
        }
        
        // always go to the right node
        if (root->right) 
        {
            rightSideView(root->right,level+1,result); 
        }
        
        if (root->left) 
        {
            rightSideView(root->left,level+1,result);
        }
            
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        rightSideView(root,0,result);
        return result;
    }
};

class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int n = qu.size();
            for (int i = 0; i<n; i++)
            {
                auto curr = qu.front();
                qu.pop();
                if (i == n-1)
                {
                    result.push_back(curr->val);
                }
                
                if (curr->left) qu.push(curr->left);
                if (curr->right) qu.push(curr->right);
            }
            
        }
        return result;
    }
};