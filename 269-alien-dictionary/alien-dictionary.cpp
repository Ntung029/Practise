class Solution {
public:
    pair<char,char> compareWords(string a, string b)
    {
        int i =0;
        if ((a.length() > b.length()) && (a.substr(0,b.length()) == b)) return {'*','*'};
        pair<char,char> result = {'-','-'};
       // cout <<a << " " << b << ": ";
        while ((i<a.length()) && (i<b.length()))
        {
            if (a[i] != b[i])
            {
             //   cout << a[i] << "->" << b[i] << endl;
                return {a[i],b[i]};
            }
            i++;
        }
        return result;
    }
    
    string alienOrder(vector<string>& words) {
        // need to build a graph from list of words
        // a < b: indgree[b] ++; and adj[a] add b

        
        vector<int> indegree(28,0);
        vector<vector<char>> adj;
        adj.resize(28);
        unordered_set<char> st;
        for (const auto& word:words)
        {
            for (const auto& ch:word)
            {
                st.insert(ch);
            }
        }
        
        
        for (int i = 0; i<words.size() -1; i++)
        {
            auto edge = compareWords(words[i],words[i+1]);
            if (edge.first == '*')
            {
                return "";
            }
            else if (edge.first != '-')
            {
               
                indegree[edge.second-'a']++;
                adj[edge.first-'a'].push_back(edge.second);
            }
            
        }
        
        queue<char> qu;
        for (char ch = 'a'; ch<='z'; ch++)
        {
            if ((st.end() != st.find(ch)) && (indegree[ch-'a'] == 0))
            {
                qu.push(ch);
              //  cout << ch << endl;
            }
        }
        
        string result;
        while (!qu.empty())
        {
            char u = qu.front();
            qu.pop();
            result += u;
            for (auto v:adj[u-'a'])
            {
                
                indegree[v-'a']--;
                if (indegree[v-'a'] == 0)
                {
                    qu.push(v);
                }
            }
        }
        // we need to know characters that appear in the list 
        if (result.size() < st.size()) return "";
        return result;
    }
};