class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>> mp;
        for (int i = 0; i<mat.size(); i++)
        {
            for (int j = 0; j<mat[i].size(); j++)
            {
                if (mp.end() == mp.find(i+j))
                {
                    mp.insert({i+j,vector<int>{}});
                }

                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> result;
        for (int i = 0; i< (mat.size()+mat[0].size()-1); i++)
        {
            if (i%2==0)
            {
                reverse(mp[i].begin(), mp[i].end());
            }
            result.insert(result.end(), mp[i].begin(), mp[i].end());
        }
        return result;
    }
};