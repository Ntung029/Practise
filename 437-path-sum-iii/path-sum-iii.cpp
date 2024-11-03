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
        void countPathSum(TreeNode* root, long long targetSum, long long sum, unordered_map<long long, long long> mp, long long& count)
        {
            if (!root) return;
            sum+=root->val;
            cout << sum << endl;
            if (sum == targetSum) count++;

            if (mp.end() != mp.find(sum-targetSum)) count+=mp[sum-targetSum];
            mp[sum]++;

            countPathSum(root->left,targetSum,sum,mp,count);
            countPathSum(root->right,targetSum,sum,mp,count);
        }

        int pathSum(TreeNode* root, int targetSum)
        {
            long long count = 0; 
            unordered_map<long long, long long> mp;
            countPathSum(root,targetSum,0, mp, count);
            return count;
        }
};

class Solution2 {
public:
    void CountPathSum(TreeNode* root, long long targetSum, long long currSum, long long& totalPaths, unordered_map<long long,long long> mp)
    {
        if (nullptr == root)
        {
            return;
        }

        currSum+=root->val;
        if (currSum == targetSum) totalPaths++;

        if (mp.end() != mp.find(currSum-targetSum))
        {
            totalPaths+=mp[currSum-targetSum];
        }

        mp[currSum]++;
        CountPathSum(root->left,targetSum,currSum,totalPaths,mp);
        CountPathSum(root->right,targetSum,currSum,totalPaths,mp);

    }
    
    int pathSum(TreeNode* root, int targetSum) {
        long long totalPaths = 0;
        long long currSum = 0;
        unordered_map<long long,long long>mp;
        CountPathSum(root,targetSum,currSum,totalPaths,mp);
        return totalPaths;      
    }
};