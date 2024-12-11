class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int count = 0;
        for (auto ch:s)
        {
            if (ch == '(') open++;
            else if (ch == ')') open--;
            if (open<0) 
            {
                count++;
                open = 0;
            }
        }
        return count+open;
    }
};