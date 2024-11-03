        // Mark visiting node is GREY, visited Node is BLACK and free node is WHITE
enum class Color{
    BLACK,
    WHITE,
    GREY
};


class Solution {
public:
    void DFS(int u, const vector<vector<int>>& adj, vector<Color>& color, bool& isCycle,stack<int> &st)    
    {
        color[u] = Color::GREY;
        for (const auto v:adj[u])
        {
            if (Color::GREY == color[v]) 
            {
                isCycle = true;
                return;
            }

            if (Color::WHITE == color[v])
            {
                DFS(v,adj,color,isCycle,st);
            }
        }
        color[u] = Color::BLACK;
        st.push(u);
    }

     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);

         for (const auto& it:prerequisites)
         {
            adj[it[1]].push_back(it[0]);
         }

         stack<int> st;
         vector<Color> color(numCourses,Color::WHITE);
         bool isCycle = false;
         for (int i = 0; i < numCourses; i++)
         {
            if (Color::WHITE == color[i])
            {
                DFS(i,adj,color,isCycle,st);
            }
         }


          // The revert of the stack is the course schedule
        vector<int> ret;
        if (isCycle) return ret;

        while (!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
     }
};

class Solution2{
public:
   void DFS (int i, vector<Color> &visited, const vector<vector<int>> & adj, stack<int> &st, bool &isPossible)
   {
       visited[i] = Color::GREY;

       for (const auto& j:adj[i])
       {
           if (Color::GREY == visited[j]) // detect a loop, impossible to generate course schedule
           {
               isPossible = false;
               return;
           }
           else if (Color::WHITE == visited[j])
           {
               DFS(j,visited,adj,st,isPossible);
           }
       }

       // when traverse all child nodes, mark the node as visited and add to stack
       visited[i] = Color::BLACK;
       st.push(i);
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Using DFS and stack to find the schedule
        // Only add the node to the stack after visiting all child nodes. 
        // Mark visiting node is GREY, visited Node is BLACK and free node is WHITE
        // build the adjection matrix
        vector<vector<int>> adj(numCourses);
        for (const auto& p:prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }
        vector<Color> visited(numCourses,Color::WHITE);
        stack<int> st;
        bool isPossible = true;
        for (int i = 0; i< numCourses; i++)
        {
            if (visited[i] == Color::WHITE)
            {
                DFS(i,visited,adj,st, isPossible);
            }
        }

        // The revert of the stack is the course schedule
        vector<int> ret;
        if (!isPossible) return ret;

        while (!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        return ret;

    }
    vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
        /* Topological sort
        build a graph with:
            adj: neighbour nodes
            indegree: Number of dependencies
            Start with course that has 0 dependencies; indegree[i] == 0;
            Go to the adj Nodes and remove dependencies, if zero, add to the queue. Continue until queue is empty
        */
        
        vector<vector<int>> adj;
        adj.resize(numCourses);
        vector<int> indegree(numCourses,0);
        for (const auto& p:prerequisites)
        {
            indegree[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        
        queue<int> qu;
        vector<int> ret;
        for (int i = 0; i< numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
                ret.push_back(i);
            }
        }
        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            for (const auto& next:adj[curr])
            {
                indegree[next]--;
                if (indegree[next] == 0) 
                {
                    qu.push(next);
                    ret.push_back(next);
                }
            }
        }
        vector<int> emptyRet;
        return ((ret.size() == numCourses) ? ret : emptyRet);
    }
};