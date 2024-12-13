/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    unordered_map<TreeNode*,int> h;

    void getHeight(TreeNode* root, int sign, int height)
    {
        if (nullptr == root)
        {
            return;
        }
        h[root] = height*sign;
        getHeight(root->left,sign,height+1);
        getHeight(root->right,sign,height+1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (nullptr == root) return result;
        h[root] = 0;
        getHeight(root->left,-1,1);
        getHeight(root->right,1,1);
        for (const auto& it:h)
        {
            if (abs(it.second - h[target]) == k)
            {
                result.push_back(it.first->val);
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        auto curr = root;
        dfsBuildGraph(curr, nullptr);

        queue<pair<TreeNode*,int>> qu;
        qu.push({target,0});
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        vector<int> result;
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            if (curr.second == k)
            {
                result.push_back(curr.first->val);
            }
            for (auto next:graph[curr.first])
            {
                if (visited.end() == visited.find(next))
                {
                    qu.push({next,curr.second+1});
                    visited.insert(next);
                }
            }
        }
        return result;
    }
private:
    unordered_map<TreeNode*, list<TreeNode*>> graph;

    void dfsBuildGraph(TreeNode* curr, TreeNode* par)
    {
        if ((curr) && (par))
        {
            graph[curr].push_back(par);
            graph[par].push_back(curr);
        }

        if ((curr) && (curr->left))
        {
            dfsBuildGraph(curr->left,curr);
        }

        if ((curr) && (curr->right))
        {
            dfsBuildGraph(curr->right,curr);
        }
    }
};