class Solution {
public:
    int minEditPalindrome(string s, string r)
    {
        int n = s.length();
        // init
        vector<vector<int>> dp(n+1,vector<int>(n+1,10000));
        for (int i = 0; i<n+1; i++)
        {
            dp[i][0] = i;
            dp[0][i] = i;
        }
        cout << dp[0][0] << endl;

        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=n; j++)
            {
                if (s[i-1] == r[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j])+1;
                }
                //cout << i << " " << j << " " << " " << s[i-1] << " " << r[j-1] << " " << dp[i][j] << endl;
            }
        }
        return dp[n][n];
    }
    bool isValidPalindrome(string s, int k) {
        string r = s;
        reverse(r.begin(),r.end());
        int minEdit = minEditPalindrome(s,r);
        cout << minEdit;
        return (minEdit<=2*k);
    }
};