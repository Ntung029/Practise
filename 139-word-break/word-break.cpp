class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.length();
        vector<bool> isValid(N,false);
        isValid[0] = true;
        unordered_set<string> st;
        for (const auto& word:wordDict)
        {
            st.insert(word);
        }
        for (int i = 1; i<=N; i++)
        {
            for (int j = 0; j<i; j++)
            {
                if (isValid[j] && (st.end() != st.find(s.substr(j,i-j))))
                {
                    isValid[i] = true;
                    if (i == N)
                    {
                        return true;
                    }
                }
            }
        }
        return isValid[N];
    }
};


class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // using BFS: each character in s is one node
        // find path from s0 to sN;
        // s0 connect to sI if s.substr(0->i) in wordDict
        if (s.empty()) return false;

        int N = s.length();
        vector<bool> isFree(N,true);
        queue<int> qu;
        qu.push(0);
        isFree[0] = false;
        unordered_set<string> st;
        for (const auto& word:wordDict)
        {
            st.insert(word);
        }
        while (!qu.empty())
        {
            int u = qu.front();
            qu.pop();
            for (int v = u+1; v<=N; v++)
            {
                if ((isFree[v]) && (st.end() != st.find(s.substr(u,v-u))))
                {
                    cout << v << endl;
                    isFree[v] = false;
                    if (v == N)
                    {
                        return true;
                    }
                    qu.push(v);
                }
            }
        }
        return false;
    }
};