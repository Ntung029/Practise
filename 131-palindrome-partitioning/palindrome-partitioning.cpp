class Solution {
public:
    vector<vector<string>> partition(string s) {
        int N = s.length();
        vector<vector<bool>> isPalinDrome(N, vector<bool>(N,false));
        vector<vector<string>> result;
        vector<string> curr;
        DFS(0,s,curr,isPalinDrome,result);
        return result;
    }

    void DFS(int start, string& s, vector<string>& curr, vector<vector<bool>>& isPalinDrome,
    vector<vector<string>>& result)
    {
        if (start>=s.length())
        {
            result.push_back(curr);
        }

        for (int end = start; end<s.length(); end++)
        {
            if (s[start] == s[end])
            {
                if ((end-start<=2) || (isPalinDrome[start+1][end-1]))
                {
                    isPalinDrome[start][end] = true;
                    curr.push_back(s.substr(start,end-start+1));
                    DFS(end+1,s,curr,isPalinDrome,result);
                    curr.pop_back();
                }
            }
        }
    }

};