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

    int maxPath(TreeNode* root, int& maxPathVal)
    {
        if (!root) return 0;
        int ret = root->val;
        int left = maxPath(root->left,maxPathVal);
        int right = maxPath(root->right,maxPathVal);
        ret = max(ret,max(left,right)+root->val);
        maxPathVal = max(max(maxPathVal, left+root->val+right),ret);
        return ret;
    
    }
    int maxPathSum(TreeNode* root)
    {
        int maxPathVal = INT32_MIN;
        int ret = maxPath(root,maxPathVal);
        return max(ret,maxPathVal);
    }
};




class Solution6 {
public:
    
    int maxPath(TreeNode* root, int &maxPathVal)
    {
        if (root == nullptr) return 0;
        int result = root->val;
        int left = maxPath(root->left,maxPathVal);
        int right = maxPath(root->right,maxPathVal);
        result = max(result, max(left,right)+root->val);
        maxPathVal = max(maxPathVal,max(result,root->val+left+right));
        return result;
    }
    int maxPathSum(TreeNode* root) {
        int maxPathVal = INT32_MIN;
        int result = maxPath(root,maxPathVal);
        return max(result,maxPathVal);
    }
};

class Solution2 {
public:
    
    int maxPath(TreeNode* root, int &maxPathVal)
    {
        if (nullptr == root)
        {
            return 0;
        }
        int left = maxPath(root->left, maxPathVal);
        int right = maxPath(root->right, maxPathVal);
        
        maxPathVal = max({maxPathVal,left+root->val, right+root->val,left+right+root->val,root->val});
        return max({root->val, left+root->val, right+root->val});
    }
    int maxPathSum(TreeNode* root) {
        if (nullptr == root)
        {
            return 0;
        }
        
        int ret = INT32_MIN;
        maxPath(root,ret);
        return ret;
    }
};