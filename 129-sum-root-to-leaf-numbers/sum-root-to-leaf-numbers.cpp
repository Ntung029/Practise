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
    void dfs(TreeNode* root, long long val, long long& result)
    {
        if (nullptr == root) return;

        val+=root->val;

        if ((!root->left) && (!root->right))
        {
            result+=val;
        }

        dfs(root->left,val*10,result);
        dfs(root->right,val*10,result);

    }
    int sumNumbers(TreeNode* root) {
        long long result = 0;
        dfs(root,0,result);
        return result;
    }
};