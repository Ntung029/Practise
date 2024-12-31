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
    vector<int> largestValues(TreeNode* root) {
        // using BFS
        vector<int> result;
        if (nullptr == root) return result;

        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int n = qu.size();
            int maxLevel = INT32_MIN;
            for (int i = 0; i<n; i++)
            {
                auto curr = qu.front();
                qu.pop();
                maxLevel = max(maxLevel,curr->val);
                if (curr->left) qu.push(curr->left);
                if (curr->right) qu.push(curr->right);
            }
            result.push_back(maxLevel);
        }
        return result;
    }
};