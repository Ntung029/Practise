/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// class Codec {
// public:
//     // in-order
//     string serialize(TreeNode* root, string& result)
//     {
//         result = serialize(root->left, result);
//         if (nullptr == root) result += "# ";
//         // using preorder: root, left, right
//         else
//         {
//             result+= to_string(root->val) + " ";
//         }   
//         result = serialize(root->right, result);
//         return result;
//     }
    
//     string serialize(TreeNode* root)
//     {
//         string result;
//         if (nullptr == root) return result;
//         // using DFS
        
//         return serialize(root, result);
//     }


//     TreeNode* deserialize(stringstream& ss)
//     {
//         string val;
//         ss >> val;
//         if ("#" == val) return nullptr;
//         //cout << val << endl;
//         auto curr = new TreeNode(stoi(val));
//         curr->left = deserialize(ss);
//         curr->right = deserialize(ss);
//         return curr;
//     }

//     TreeNode* deserialize(string data)
//     {
//         if (data.empty()) return nullptr;
//         stringstream ss(data);
//         string val;
//         ss >> val;

//         TreeNode* root = new TreeNode(stoi(val));
//         stack<TreeNode*> st;
//         st.push(root);


//         while (ss)
//         {
//             auto curr = st.top();
//             ss >> val;
//             if (val != "#")
//             {
//                 curr->left = new TreeNode(stoi(val));
//             }
//         }
//     }

// };



class Codec {
    public:
    string serialize(TreeNode* root)
    {
        // using BFS
        string result;
        queue<TreeNode*> qu;
        qu.push(root);
        
        
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            if (nullptr == curr)
            {
                result += "# ";
            }
            else
            {
                result += to_string(curr->val) + " ";
                qu.push(curr->left);
                qu.push(curr->right);
            }
        }
        
        return result;
    
    }
    
    
    TreeNode* deserialize(string& s)
    {
        if (s.empty()) return nullptr;
        
        stringstream ss(s);
        string val;
        ss >> val;
        
        if ("#" == val) return nullptr;
        
        queue<TreeNode*> qu;
        
        auto root = new TreeNode(stoi(val));
        qu.push(root);
        
        while ((ss) && (!qu.empty()))
        {
            auto curr = qu.front();
            qu.pop();
            
            
            if (nullptr == curr) break;
            
            
            ss >> val;    
            if ("#" != val)
            {
                curr->left = new TreeNode(stoi(val));
                qu.push(curr->left);
            }
            else
            {
                curr->left = nullptr;
            }
            
            
            ss >> val;
            if ("#" != val)
            {
                curr->right = new TreeNode(stoi(val));
                qu.push(curr->right);
            }
            else
            {
                curr->right = nullptr;
            }
        }
        
        return root;
    }
};

class Codec5 {
public:
    string serialize(TreeNode* root)
    {
        string result;
        if (nullptr == root) return result;
        // using DFS
        
        return serialize(root, result);
    }


    TreeNode* deserialize(stringstream& ss)
    {
        string val;
        ss >> val;
        if ("#" == val) return nullptr;
        //cout << val << endl;
        auto curr = new TreeNode(stoi(val));
        curr->left = deserialize(ss);
        curr->right = deserialize(ss);
        return curr;
    }

    TreeNode* deserialize(string data)
    {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        // string val;
        // ss >> val;

        // TreeNode* root = new TreeNode(stoi(val));
        // stack<TreeNode*> st;
        // st.push(root);
        return deserialize(ss);

        // while (ss)
        // {
        //     auto curr = st.top();
        //     ss >> val;
        //     if (val != "#")
        //     {
        //         curr->left = new TreeNode(stoi(val));
        //     }
        // }
    }
private:
    string serialize(TreeNode* root, string& result)
    {
        if (nullptr == root) result += "# ";
        // using preorder: root, left, right
        else
        {
            result+= to_string(root->val) + " ";
            result = serialize(root->left, result);
            result = serialize(root->right, result);
        }
        return result;
    }
};

class Codec4 {
public:
    string serialize(TreeNode* root)
    {
        string result;
        if (nullptr == root)
        {
            return result;
        }
        
        // using BFS
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            
            if (nullptr != curr)
            {
                // using space as delimiter
                result = result + to_string(curr->val) + " ";
                
                qu.push(curr->left);
                qu.push(curr->right);
            }
            else
            {
                result += "# ";
            }
        }
        return result;
    }
    
    
    TreeNode* deserialize(string data)
    {
        if (data.length() == 0)
        {
            return nullptr;            
        }
        stringstream ss(data);
        string val;
        queue<TreeNode*> qu;
        
        ss >> val;
        if (val == "#")
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        qu.push(root);
        
        while (!qu.empty() && ss)
        {
            auto curr = qu.front();
            qu.pop();
            
            ss >> val;
            
            if (val != "#")
            {
                curr->left = new TreeNode(stoi(val));
                qu.push(curr->left);
            }
            else
            {
                curr->left = nullptr;
            }
            
            
            ss >> val;
            
            if (val != "#")
            {
                curr->right = new TreeNode(stoi(val));
                qu.push(curr->right);
            }
            else
            {
                curr->right = nullptr;
            }
            
        }
        
        return root;
    }
private:
};


class Codec7 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // using inroder : root->left->right
        string result;
        if (nullptr ==  root)
        {
            return result;
        }
        BFSHelper(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        stringstream ss(data);
        string val;

        ss >> val;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty() && ss)
        {
            auto curr = qu.front();
            qu.pop();

            ss >> val;

            if (val == "#")
            {
                curr->left = nullptr;
            }
            else
            {
                curr->left = new TreeNode(stoi(val));
                qu.push(curr->left);
            }

            ss >> val;
            
            if (val == "#")
            {
                curr->right = nullptr;
            }
            else
            {
                curr->right = new TreeNode(stoi(val));
                qu.push(curr->right);
            }
        }

        return root;
    }
    
private:
    void BFSHelper(TreeNode* root, string& s)
    {
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            if (nullptr != curr)
            {
                s = s+to_string(curr->val) + " ";
                qu.push(curr->left);
                qu.push(curr->right);
            }
            else
            {
                s += "# ";
            }
        }
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));