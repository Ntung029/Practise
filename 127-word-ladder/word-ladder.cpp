class Solution {
public:
    
    bool isConnected(const string& a, const string& b)
    {
        if (a.length() != b.length())
            return false;
        
        int count = 0;
        for (int i = 0; i<a.length(); i++)
        {
            if (a[i] != b[i]) count++;
            if (count>1) return false;
        }
        return count == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // using BFS to find the shortest path between beginWord and endWord
        unordered_set<string> visited;
        queue<string> qu;
        qu.push(beginWord);
        visited.insert(beginWord);
        int count = 0;
        while (!qu.empty())
        {
            int n = qu.size();
            count++;
            for (int i = 0; i<n; i++)
            {
                auto curr = qu.front();
                qu.pop();
                
                for (const auto& w:wordList)
                {
                    if ((visited.end() == visited.find(w)) && (isConnected(curr,w)))
                    {
                        if (w == endWord) return count+1;
                        qu.push(w);
                        visited.insert(w);
                    }
                }
            }
            
        }
        return 0;
    }
};

class Solution2 {
public:
    
    bool isConnected(const string& a, const string& b)
    {
        int countDiff = 0;
        if (a.length() != b.length()) return false;
        for (int i=0; i< a.length(); i++ )
        {
            if (a[i] != b[i]) countDiff++;
            if (countDiff > 1) return false;
        }
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Using BFS to find the shortest path from beginWord to endWord
        unordered_set<string> isTravelled;
        queue<string> qu;
        qu.push(beginWord);
        isTravelled.insert(beginWord);
        int count = 0;
        while (!qu.empty())
        {
            count++;
            int n = qu.size();
            for (int i = 0; i< n; i++)
            {
                auto curr = qu.front();
                //cout << count << " "<< curr << endl;
                qu.pop();
                if (curr == endWord) return count;    
                
                for (const auto& w:wordList)
                {
                    if ((isTravelled.end() == isTravelled.find(w)) && (isConnected(curr,w)))
                    {
                        isTravelled.insert(w); // mark as visited
                        qu.push(w);
                    }
                }
            }
        }
        return 0;
    }
};