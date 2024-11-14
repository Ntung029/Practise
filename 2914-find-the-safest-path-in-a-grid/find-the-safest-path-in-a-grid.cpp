struct Cell{
public:
    int x;
    int y;
    int distance;

    Cell(int vx, int vy, int vDistance): x(vx), y(vy), distance(vDistance){};
};


struct Comparator {
        bool operator()(Cell const &p1, Cell const &p2) {
            return p2.distance > p1.distance;
        }
    };

class Solution {
public:
    const vector<int> dx{0,1,-1,0};
    const vector<int> dy{1,0,0,-1};

    void constructDist(vector<vector<int>>& grid, vector<vector<int>>& dist)
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> qu;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for (int i = 0; i<row; i++)
        {
            for (int j = 0; j<col; j++)
            {
                if (grid[i][j] ==  1)
                {
                    qu.push({i,j});
                    dist[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        while (!qu.empty())
        {
            auto u = qu.front();
            qu.pop();
            for (int k = 0; k<4; k++)
            {
                int x = u.first +dx[k];
                int y = u.second + dy[k];
                if ((x>=0) && (x<row) && (y>=0) && (y<col) && !visited[x][y])
                {
                    qu.push({x,y});
                    visited[x][y] = true;
                    dist[x][y] = min(dist[x][y],dist[u.first][u.second]+1);
                }
            }
        }
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if ((grid[0][0] == 1) || (grid[row-1][col-1] ==1) || ((row <= 1)  && (col <=1) )) return 0;
        vector<vector<int>> dist(row,vector<int>(col,INT32_MAX));  
        constructDist(grid,dist);

        // using Dijkstra algorithm to find the path with maximum dist
        // dist[u][v] = min (dist[x][y],dist[u][v]); while dist[x][y] is the
        // max distance in the priority queue
        priority_queue<Cell, vector<Cell>, Comparator> qu;
        qu.push(Cell(0,0,dist[0][0]));

        vector<vector<bool>> visited(row,vector<bool>(col,false));
        visited[0][0] = true;
        while (!qu.empty())
        {
            auto c = qu.top();
            qu.pop();
            
            for (int k = 0; k<4; k++)    
            {
                int u = c.x+dx[k];
                int v = c.y+dy[k];
                if ((u>=0) && (u<row) && (v>=0) && (v<col) && !visited[u][v])
                {
                    visited[u][v] = true;
                    if (dist[u][v] > dist[c.x][c.y])
                    {
                        dist[u][v] = dist[c.x][c.y];
                    }
                    qu.push(Cell(u,v,dist[u][v]));   
                    if ((u == row-1) && (v == col -1))
                    {
                        return dist[u][v];
                    } 
                }
                
            }
        }
        return dist[row-1][col-1];

    }
};


class Solution3
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        //for bfs push coordinate of all thief into queue

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // BFS
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<pair<int, int>> mv = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}};

            for (auto m : mv)
            {
                int i = x + m.first;
                int j = y + m.second;
                if (i < 0 || j < 0 || i >= n || j >= n || dist[i][j] <= dist[x][y] + 1)
                    continue;
                q.push({i, j});
                dist[i][j] = 1 + dist[x][y];
            }
        }
        //Dijktra
        priority_queue<pair<int, pair<int, int>>> pq;
        vis.assign(n, vector<bool>(n, false));
        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = true;

        while (!pq.empty())
        {
            int val = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            vector<pair<int, int>> mv = {
                {1, 0},
                {0, 1},
                {-1, 0},
                {0, -1}};

            for (auto m : mv)
            {
                int i = x + m.first;
                int j = y + m.second;
                if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == true)
                    continue;

                vis[i][j] = true;
                dist[i][j] = min(dist[i][j], dist[x][y]);
                pq.push({dist[i][j], {i, j}});
            }
        }
        return dist[n - 1][n - 1];
    }
};