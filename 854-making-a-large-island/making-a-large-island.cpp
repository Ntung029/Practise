class UnionJoin{
public:
    UnionJoin(int n){
        N = n;
        par.resize(N,0);
        for (int i = 0; i<N; i++)
        {
            par[i] = i;
        }

        rank.resize(N,0);
        count.resize(N,1);
    }

    int getPar(int x)
    {
        if (x != par[x])
        {
            par[x] = getPar(par[x]);
        }
        return par[x];
    }

    void join(int x, int y)
    {
        int rootX = getPar(x);
        int rootY = getPar(y);
        if (rootX == rootY) return;
        if (rank[rootX] > rank[rootY])
        {
            par[rootY] = rootX;
            count[rootX]+=count[rootY];
        }
        else if (rank[rootY] > rank[rootX])
        {
            par[rootX] = rootY;
            count[rootY]+=count[rootX];
        }
        else
        {
            par[rootY] = rootX;
            rank[rootX]++;
            //total nodes 
            count[rootX]+=count[rootY];
        }
    }

    int getCount(int x)
    {
        return count[getPar(x)];
    }

    int getMaxIsland()
    {
        int result = 0;
        for (const auto x:count)
        {
            result = max(result,x);
        }
        return result;
    }

private:
    vector<int> par;
    vector<int> rank;
    // keep track the size of the island
    vector<int> count;
    int N;
};

class Solution {
public:
    vector<int> dx{0,1,0,-1};
    vector<int> dy{1,0,-1,0};

    int largestIsland(vector<vector<int>>& grid) {
    // using Union join, keep track the size of the island  
        int nRow = grid.size();
        int nCol = grid[0].size();
        int N = nRow*nCol;
        auto unionJoin = UnionJoin(N);
        for (int i=0; i<nRow; i++)
        {
            for (int j=0; j<nCol; j++)
            {
                if (grid[i][j]==1)
                {
                    //cout << "ij:" << i << " " << j << endl;
                    for (int k=0; k<4; k++)
                    {
                        int u = i+dx[k];
                        int v = j+dy[k];
                        if ((u>=0) && (u<nRow) && (v>=0) && (v<nCol) && (grid[u][v]==1))
                        {
                           // cout << "uv:" << u << " " << v << endl;
                            unionJoin.join(getId(i,j,nCol), getId(u,v,nCol));
                        }
                    }
                }
            }
        }

        // get the size of the largest island
        int result = unionJoin.getMaxIsland();
        
        
        for (int i=0; i<nRow; i++)
        {
            for (int j=0; j<nCol; j++)
            {
                if (grid[i][j]==0)
                {
                   // cout << "ij:" << i << " " << j << endl;
                    int sumCount = 0;

                    // keep track the set of connected islands when fliping cell i,j
                    unordered_set<int> group;
                    for (int k=0; k<4; k++)
                    {
                        int u = i+dx[k];
                        int v = j+dy[k];
                        if ((u>=0) && (u<nRow) && (v>=0) && (v<nCol) && (grid[u][v]==1))
                        {
                           // cout << "uv:" << u << " " << v << " "<< unionJoin.getPar(getId(u,v,nCol)) << endl;
                            if (group.end() == group.find(unionJoin.getPar(getId(u,v,nCol))))
                            {
                                sumCount+=unionJoin.getCount(getId(u,v,nCol));
                                group.insert(unionJoin.getPar(getId(u,v,nCol)));
                            }
                        }
                    }
                    
                    result = max(result,sumCount+1);
                }
            }
        }
        return result;
    }

    int getId(int row, int col, int nCol)
    {
        return nCol*row+col;
    }
};