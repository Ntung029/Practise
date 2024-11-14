class Solution{
public:
    constexpr static int dx[4] = {1,0,0,-1};
    constexpr static int dy[4] = {0,1,-1,0};

    int findRoot(int x, vector<int> &par)
    {
        // compression path
        if (x != par[x])
        {
            par[x] = findRoot(par[x],par);
        }
        return par[x];
    }


    void unionJoin(int x, int y, vector<int>& par, vector<int>& rank, int& count)
    {
        int xRoot = findRoot(x, par);
        int yRoot = findRoot(y, par);
        if (xRoot == yRoot)
        {
            // already joined
            return;
        }

        if (rank[xRoot] > rank[yRoot])
        {
            // join yRoot to xRoot
            par[yRoot] = xRoot;
        }
        else if (rank[xRoot] < rank[yRoot])
        {
            par[xRoot] = yRoot;
        }
        else
        {
            // join yRoot to xRoot
            rank[xRoot]++;
            par[yRoot] = xRoot;
        }
        count--;
    }

    int getID (int x, int y, int N)
    {
        return x*N+y;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions)
    {
        int N = m*n;
        vector<int> par(N,-1);
        vector<int> rank(N,0);
        vector<int> ret;
        int count = 0;
        for (auto pos:positions)
        {
            int x = getID(pos[0],pos[1],n);
            if (-1 == par[x])
            {
                par[x] = x;
                count++;
            }

            for (int k = 0; k <4; k++)
            {
                int u = pos[0] + dx[k];
                int v = pos[1] + dy[k];
                if ((u>=0) && (u<m) && (v>=0) && (v<n) && (par[getID(u,v,n)] != -1))
                {
                    unionJoin(x,getID(u,v,n),par,rank,count);
                }
            }
            ret.push_back(count);
        }
        return ret;
    }
};

















class Solution2 {
public:
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};
    
    int findRoot(int x, vector<int> &par)
    {
        // compression path
        if (x != par[x])
        {
            par[x] = findRoot(par[x],par);
        }
        return par[x];
    }
    
    void unionJoin(int x, int y, vector<int> &par, vector<int> &rank, int &count)
    {
        int xRoot = findRoot(x,par);
        int yRoot= findRoot(y,par);
        if (xRoot == yRoot) return;
        
        if (rank[xRoot] > rank[yRoot])
        {
            par[yRoot] = xRoot;
        }
        else if (rank[xRoot] < rank[yRoot])
        { 
            par[xRoot] = yRoot;
        }
        else
        {
            par[yRoot] = xRoot;
            rank[xRoot]++;
        }
        count--;
    }
    
    int getID(int x, int y, int n)
    {
        return x*n+y;
    }
    
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        int N = m*n;
        vector<int> par(N,-1);
        vector<int> rank(N,0);
        
        int count = 0;
        vector<int> ret;
        for (auto &pos:positions)
        {
            int x = getID(pos[0],pos[1],n);
            if (par[x] == -1)
            {
                count++;
                par[x] = x;
            }
            for (int k = 0; k<4; k++)
            {
                int u = pos[0] + dx[k];
                int v = pos[1] + dy[k];
                
                if ((u>=0) && (u<m) && (v>=0) && (v<n) && (par[getID(u,v,n)] != -1))
                {
                    unionJoin(x,getID(u,v,n),par,rank,count);
                }
            }
            ret.push_back(count);
        }
        return ret;
    }
};