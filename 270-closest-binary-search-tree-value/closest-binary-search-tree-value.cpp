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
    void findClosestValue(TreeNode* root, double target, int& result, double& minVal)
    {
        if (nullptr == root) return;
        if (abs(target-(double)root->val)< minVal)
        {
            minVal = abs(target-(double)root->val);
            result = root->val;
        }
        else if (abs(target-(double)root->val)==minVal)
        {
            result = min(result,root->val);
        }

        if (root->val>target)
        {
            findClosestValue(root->left,target,result,minVal);
        }
        else if (root->val<target)
        {
            findClosestValue(root->right,target,result,minVal);
        }
        else
        {
            result = root->val;
            return;
        }
    }
    
    int closestValue(TreeNode* root, double target) {
        int result = INT32_MIN;
        double minVal = INT32_MAX;
        findClosestValue(root,target,result,minVal);
        return result;
    }
};