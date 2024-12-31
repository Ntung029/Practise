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
    bool isCompleteTree(TreeNode* root) {
        // using BFS, at level k, there will be k^2 node
        // check if missing left node
        if (!root) return true;
        queue<TreeNode*> qu;
        qu.push(root);
        int k = 1;
        bool isMissing = false;
        while (!qu.empty())
        {
            int n = qu.size();
            for (int i = 0; i<n; i++)
            {
                auto curr = qu.front();
                qu.pop();

                if (!curr->left) isMissing = true;
                
                if (curr->left)
                {
                    qu.push(curr->left);
                    if (isMissing) return false;
                }

                if (!curr->right) isMissing = true;
                
                if (curr->right)
                {
                    qu.push(curr->right);
                    if (isMissing) return false;
                }
            }
            k++;
        }
        return true;
    }
};