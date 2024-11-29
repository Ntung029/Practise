class Solution {
vector<int> dx{1,0,0,-1};
vector<int> dy{0,1,-1,0};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> qu;
        int nRow = heights.size();
        int nCol = heights[0].size();
        vector<vector<int>> result;
        vector<vector<int>> color(nRow,vector<int>(nCol,0));
        // 0: free
        // 1: reach by Pacific
        // 2: reach by both

        // using BFS
        for (int i = 0; i<nRow; i++)
        {
            qu.push({i,0});
            color[i][0] = 1;
        }

        for (int j = 0; j<nCol; j++)
        {
            qu.push({0,j});
            color[0][j] = 1;
        }

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            for (int k = 0; k<4; k++)
            {
                int u = curr.first+dx[k];
                int v = curr.second+dy[k];
                if ((u>=0) && (u<nRow) && (v>=0) && (v<nCol) && (color[u][v] == 0) 
                && (heights[curr.first][curr.second] <= heights[u][v]))
                {
                    qu.push({u,v});
                    color[u][v] = 1;
                }
            }
        }
        // for (int i = 0; i< nRow; i++)
        // {
        //     for (int j = 0; j<nCol; j++)
        //     {
        //         cout << color[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<vector<int>> colorA(nRow,vector<int>(nCol,0));
        for (int i = 0; i<nRow; i++)
        {
            qu.push({i,nCol-1});
            colorA[i][nCol-1] = 1;
            if (color[i][nCol-1] == 1)
            {
                result.push_back({i,nCol-1});
                color[i][nCol-1] = 2;
            }
        }

        for (int j = 0; j<nCol; j++)
        {
            qu.push({nRow-1,j});
            colorA[nRow-1][j] = 1;

            if (color[nRow-1][j] == 1)
            {
                result.push_back({nRow-1,j});
                color[nRow-1][j] = 2;
            }
        }

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            for (int k = 0; k<4; k++)
            {
                int u = curr.first+dx[k];
                int v = curr.second+dy[k];
                if ((u>=0) && (u<nRow) && (v>=0) && (v<nCol) && (colorA[u][v] == 0) 
                && (heights[curr.first][curr.second] <= heights[u][v]))
                {
                    qu.push({u,v});
                    colorA[u][v] = 1;
                    if (color[u][v] == 1)
                    {
                        result.push_back({u,v});
                        color[u][v] = 2;
                    }
                }
            }
        }

        // for (int i = 0; i< nRow; i++)
        // {
        //     for (int j = 0; j<nCol; j++)
        //     {
        //         cout << colorA[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return result;
    }
};