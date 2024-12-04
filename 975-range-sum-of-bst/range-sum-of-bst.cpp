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

    void DFS(TreeNode* root, int low, int high, int& result)
    {
        if (!root) return;
        if (root->val<low) DFS(root->right,low,high,result);
        else if (root->val>high) DFS(root->left,low,high,result);
        else
        {
            result+=root->val;
            DFS(root->left,low,high,result);
            DFS(root->right,low,high,result);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        DFS(root,low,high,result);
        return result;
    }
};