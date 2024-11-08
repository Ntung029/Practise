class Solution3 {
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

// using Trie
constexpr int N = 27;
struct TrieNode{
    bool isEndWord;
    TrieNode* children[N];
    TrieNode(){
        isEndWord = false;
        for (int i = 0; i<N; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Solution{
public:
    void insert(TrieNode* root, const string& word)
    {
        auto curr = root;
        for (auto ch:word)
        {
            if (nullptr == curr->children[ch-'a'])
            {
                curr->children[ch-'a'] = new TrieNode();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isEndWord = true;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        // construct the trie
        
        auto root = new TrieNode();
        for (const auto& word:wordDict)
        {
            insert(root,word);
        }

        vector<bool> dp(s.size(),false);
        for (int i = 0; i<s.size(); i++)
        {
            if ((i == 0) || (dp[i-1]))
            {
                auto curr = root;
                for (int j = i; j<s.length(); j++)
                {
                    if (nullptr == curr->children[s[j]-'a'])
                    {
                        break;
                    }

                    curr = curr->children[s[j]-'a'];
                    if (curr->isEndWord) dp[j] = true;
                }
            }
        }
        return dp[s.length()-1];
    }
};
