class Solution {
public:
    int findRoot(int x, vector<int> &par)
    {
        if (x != par[x])
        {
            par[x] = findRoot(par[x],par);
        }
        return par[x];
    }
    
    void unionJoin(int x, int y, vector<int>&rank, vector<int> &par, int &count)
    {
        int xRoot = findRoot(x,par);
        int yRoot = findRoot(y,par);
        
        if (xRoot == yRoot) return;
        count--;
        
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
    }
    
    
    bool isCommonEmail(vector<string> &a, vector<string> &b)
    {
        for (int i = 1; i<a.size(); i++)
        {
            for (int j = 1; j<b.size(); j++)
            {
                if (a[i].compare(b[j]) == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> par(n);
        for (int i = 0; i<n ; i++)
        {
            par[i] = i;
        }
        vector<int> rank(n,0);
        int count = n;
        unordered_map<string,int> mp;
        for (int i = 0; i<n; i++)
        {
            for (int j = 1; j<accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if (mp.find(email) == mp.end())
                {
                    //first time seeing this email
                    mp[email] = i;
                }
                else
                {
                    // join current account with the account that this email belongs to
                    unionJoin(i,mp[email],rank,par,count);
                }
            }
          /*  
            for (int j = i+1; j<n; j++)
            {
                if (isCommonEmail(accounts[i],accounts[j]))
                {
                    unionJoin(i,j,rank,par,count);
                }
            }
            */
        }
        
        unordered_map<int,set<string>> ret(n);
        
        for (int i = 0; i<n; i++)
        {
            int u = findRoot(i,par);
            for (int k = 1; k< accounts[i].size();k++)
            {   
                ret[u].insert(accounts[i][k]);
            }
        }
        vector<vector<string>> result;
        for (auto &account:ret)
        {
            string name = accounts[account.first][0];

            vector<string> newAccount;
            newAccount.push_back(name);

            for (auto &email:account.second)
            {
                newAccount.push_back(email);    
            }
            result.push_back(newAccount);
            
        }
        return result;
    }
};