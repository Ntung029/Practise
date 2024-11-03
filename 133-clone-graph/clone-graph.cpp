/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution{
public:
    Node* cloneGraph(Node* node)
    {
        // using BFS
        // DFS
        // DFS with stack

        if (!node) return nullptr;
        unordered_map<Node*,Node*> mp;
        queue<Node*> qu;
        
        auto cloneNode =  new Node(node->val);
        mp[node] = cloneNode;

        qu.push(node);
        
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            for (auto neighbor:curr->neighbors)
            {
                if (mp.end() == mp.find(neighbor))
                {
                    // clone neighbor
                    auto cNeighbor = new Node(neighbor->val);
                    mp[neighbor] = cNeighbor;
                    qu.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }
        return cloneNode;
    }
};

class Solution13 {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node)
    {
        //using DFS
        if (!node) return nullptr;
        if (mp.end() != mp.find(node))
        {
            return mp[node];
        }

        // clone node
        auto clonedNode = new Node(node->val);
        mp[node] = clonedNode;

        for (auto neighbor:node->neighbors)
        {
            clonedNode->neighbors.push_back(cloneGraph(neighbor));
        }
           return clonedNode;
    }
 
};

class Solutionx {
public:
    unordered_map<Node*,Node*> mp;
     Node* cloneGraph(Node* node)
     {
         // using BFS
         if (node == nullptr) return nullptr;
         queue<Node*> qu;
         qu.push(node);
         
         auto clonedNode = new Node(node->val);
         mp[node] = clonedNode;
         
         while (!qu.empty())
         {
             auto curr = qu.front();
             qu.pop();
             
             for (auto n:curr->neighbors)
             {
                 if (mp.end() == mp.find(n))
                 {
                     // cloned this node and add to the queue
                     auto clonedN = new Node(n->val);
                     mp[n] = clonedN;
                     qu.push(n);
                 }
                 
                 // node n is cloned, add to the cloned neighbor list
                 mp[curr]->neighbors.push_back(mp[n]);
             }
             
         }
         return clonedNode;
     }
      
  
  

    
    
    
    
    
    
    
    Node* cloneGraph2(Node* node)
    {
        // using DFS
        if (nullptr == node) return nullptr;
        if (mp.end() != mp.find(node))
        {
            return mp[node];
        }
        
        // clone the current node
        auto clonedNode = new Node(node->val);
        mp[node] = clonedNode;
        
        
        // clone the neighbors node
        for (auto n:node->neighbors)
        {
            auto clonedN = cloneGraph(n);
            
            clonedNode->neighbors.push_back(clonedN);
        }
        
        return clonedNode;
    }
};

class Solution7 {
public:
    unordered_map<Node*,Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (nullptr == node) 
        {
            return nullptr;
        }
        
        
        // node has not visited
        if (mp.end() == mp.find(node))
        {
            return mp[node];
        }
        
        auto cloned = new Node(node->val);
        mp[node] = cloned;
        
        
        for (auto u:node->neighbors)
        {
            cloned->neighbors.push_back(cloneGraph(u));
        }
        return cloned;
    }
};



class Solution5 {
public:
    unordered_map<Node*,Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (nullptr == node)
        {
            return node;
        }
        
        queue<Node *> qu;
        qu.push(node);
        
        // clone curr node
        auto clonedNode = new Node(node->val);

        // mark curr as cloned
        mp[node] = clonedNode;
        
        
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            
            
            for (auto n:curr->neighbors)
            {
                if (mp.end() == mp.find(n))
                {
                    qu.push(n);
                    auto clonedN = new Node(n->val);
                    mp[n] = clonedN;
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }
            
        }
        return clonedNode;

    }
};

class Solution3 {
public:
    unordered_map<Node*,Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (nullptr == node)
        {
            return node;
        }

        queue<Node*> qu;
        qu.push(node);

        auto cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            // traverse to all neighbour nodes and clone them
            for (auto nNode:curr->neighbors)
            {
                if (mp.end() == mp.find(nNode))
                {
                    // not visited
                    auto cloneNNode = new Node(nNode->val);
                    mp[nNode] = cloneNNode;
                    qu.push(nNode);
                }

                mp[curr]->neighbors.push_back(mp[nNode]);
            }
        }


        return cloneNode;
    }
};


class Solution2 {
public:
    unordered_map<Node*,Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (nullptr == node)
        {
            return node;
        };

        if (mp.end() != mp.find(node))
        {
            // node is visited, return the cloned node
            return mp[node];
        }

        // not is not vistited, create the cloned node
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode; // marked as visited

        // traverse the neighbour nodes and add the cloned node to the neighbour list
        for (auto nNode:node->neighbors)
        {
            cloneNode->neighbors.push_back(cloneGraph(nNode));
        }
        return cloneNode;
    }
};