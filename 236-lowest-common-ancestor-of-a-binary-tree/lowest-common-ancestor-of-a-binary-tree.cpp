/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            if (!root) return root;
            if ((root->val == p->val) || (root->val == q->val)) return root;
            auto left = lowestCommonAncestor(root->left,p,q);
            auto right = lowestCommonAncestor(root->right,p,q);
            if (left && right) return root;
            return left ? left :right;
        }
};



class Solution7 {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        if ((root->val == p->val) || (root->val == q->val)) return root;
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root->right,p,q);
        if ((left) && (right)) return root;
        return left? left: right;
    }
};

		class Solution3 {
		public:
		    struct TreeNode *findNode(TreeNode* root, TreeNode*p, TreeNode*q, bool &v1, bool &v2)
		    {
		        if (root == nullptr) return nullptr; // special error code
		        if (root == p)
		        {
		            v1 = true;
		                return root;
		        }
		        if (root == q)
		        { 
		            v2 = true;
		            return root;
		        }
		        
		        TreeNode *leftNode = findNode(root->left,p,q,v1,v2);
		        TreeNode *rightNode = findNode(root->right,p,q,v1,v2);
		        
		        if (leftNode && rightNode)
		            return root;
		        
		        
		        return leftNode? leftNode : rightNode;
		        
		    }
		    
		    bool findNode(TreeNode* root, TreeNode* p)
		    {
		        if (root == nullptr)
		        {
		            return false;
		        }
		        
		        return ((root == p) || findNode(root->left,p) || findNode(root->right,p));
		    }
		    
		    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		        /*
		            at curr node
		                If 1 node is on the left and 1 node is on the right: found 
		                if curr Node is p/q; and found the other node: found
		            findNode: return true if found the node    
		        */
		        
		        if (root == nullptr) return nullptr;
		        
		        bool v1 = false;
		        bool v2 = false;
		        
		        TreeNode* lca =  findNode(root,p,q,v1,v2);
		        if ((v1 && v2) || (v1 && findNode(lca,p)) || (v2 && findNode(lca,q)))
		       {
		           return lca;
		       }
		        return nullptr;
		    }
};

class Solutionx {
public:

    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (nullptr == root)
        {
            return nullptr;
        }

        if ((root->val == p->val) || (root->val == q->val)) return root;
        // both p and q are on the left of root
        if ((root->val > p->val) && (root->val > q->val))
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if ((root->val < p->val) && (root->val < q->val))
        {
            // both on the right
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            // one on the left and one on the right: root is the LCA
            return root;
        }
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (nullptr == root) return root;
        if ((root->val == p->val) || (root->val ==q->val)) return root;

        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        
        if (left && right) return root;
        return left? left:right;
    }
    
    TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p->val>q->val) swap(p,q);
        int n1 = p->val;
        int n2 = q->val;
        while (root != nullptr)
           {
               if ((root->val >= n1) && (root->val <=n2))
               {
                   return root;
               }

               if (root->val < n1)
               {
                   root = root->right;
               }

               if (root->val > n2)
               {
                   root = root->left;
               }
           }
        return nullptr;
    }
};