class Solution {
public:
    const int dx[8] = {0,0,1,1,1,-1,-1,-1};
    const int dy[8] = {-1,1,-1,0,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        // sanitity check
        if (grid[0][0] != 0) return -1;
        queue<pair<int,int>> qu;
        qu.push({0,0});
        grid[0][0] = 2;
        int count = 0;
        while (!qu.empty())
        {
            int n = qu.size();
            count ++;
            
            for (int k = 0; k <n; k++)
            {
                auto curr = qu.front();
                qu.pop();

                if ((curr.first == nRow-1) && (curr.second == nCol-1))
                {
                    return count;
                }
                for (int i = 0; i<8; i++)
                {
                    int u = curr.first+dx[i];
                    int v = curr.second+dy[i];
                    if ((u>=0) && (u<nRow) && (v>=0) && (v<nCol) && (grid[u][v] == 0))
                    {
                        grid[u][v] = 2; // mark as visited
                        qu.push({u,v});
                    }
                }
            }
        }
        return -1;
    }
};