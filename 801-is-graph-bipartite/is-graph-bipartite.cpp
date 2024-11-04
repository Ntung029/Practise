enum class Color{
    W,B,R
};

class Solution {
public:
    // using DFS
    void DFS(int u, bool isBlue, const vector<vector<int>>& graph, vector<Color>& color, bool& isGraphBipartite)
    {
        color[u] = isBlue? Color::B : Color::R;
        //cout << u  << endl;
        isBlue = !isBlue;
        for (const auto v:graph[u])
        {
            if (color[u] == color[v])
            {
                isGraphBipartite = false;
                return;
            }
            else if (color[v] == Color::W)
            {
                DFS(v,isBlue,graph,color,isGraphBipartite);
            }
        } 
    }

    bool isBipartite(vector<vector<int>>& graph) {    
        int N = graph.size();
        vector<Color> color(N,Color::W);
        bool isGraphBipartite = true;
        for (int i = 0; i<N; i++)
        {
            bool isBlue = true;
            if (Color::W == color[i])
            {
                
                DFS(i,isBlue,graph,color,isGraphBipartite);
                
                if (!isGraphBipartite) return isGraphBipartite;
            }
        }
        return isGraphBipartite;
    }
};


class Solution5 {
public:
    bool BFS(int i, vector<Color>& color, vector<vector<int>>& graph)
    {
        queue<int> qu;
        qu.push(i);
        color[i] = Color::B;
        bool isBlue = true;
        while (!qu.empty())
        {
            isBlue = !isBlue;
            int nq = qu.size();
            for (int k = 0; k<nq; k++)
            {
                int i = qu.front();
                qu.pop();
                
                for (const auto j:graph[i])
                {
                    if (color[j] == Color::W)
                    {
                        qu.push(j);
                        if (isBlue)
                        {
                            color[j] = Color::B;
                        }
                        else
                        {
                            color[j] = Color::R;
                        }
                    }
                    else if (color[i] == color[j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<Color> color(N,Color::W);
        for (int i = 0; i<N; i++)
        {
            if (color[i] == Color::W)
            {
                if (!BFS(i,color,graph))
                {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution6 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        //using BFS
        int N = graph.size();
        vector<int> color(N,2); //R0/B1/W2
        queue<int> qu;
        
        for (int i = 0; i<N; i++)
        {
            if (color[i] == 2)
            {
                qu.push(i);
                color[i] = 0;
                while (!qu.empty())
                {
                    int n = qu.size();
                    
                    for (int k = 0; k<n; k++)
                    {
                        int u = qu.front();
                        qu.pop();
                        for (auto v: graph[u])
                        {
                            if (color[v] == color[u])  return false;
                            if (color[v] ==2)
                            {   
                                color[v] = 1-color[u];
                                qu.push(v);
                            }
                        }
                    }
                }
            }
        }
        return true;
        
    }
};

class Solution2 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N,2); // R0/G1/W2

        stack<int> st;

        for (int i = 0; i<N; i++)
        {
            if (color[i] == 2)
            {
                st.push(i);
                color[i] = 1;
                while (!st.empty())
                {
                    int u = st.top();
                    st.pop();
                    for (const auto& v:graph[u])
                    {
                        if (color[v] == color[u])
                        {
                            return false;
                        }
                        else if (color[v] == 2)
                        {
                            color[v] = 1-color[u];
                            st.push(v);
                        }
                    }
                }
                
            }
        }

        return true;
    }
};