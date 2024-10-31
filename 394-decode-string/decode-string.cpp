class Solution {
public:
    bool isDigit(const char ch)
    {
        return (ch>='0') && (ch <= '9');
    }
    
    bool isAlphabet(const char ch)
    {
        return ((ch>='A') && (ch <= 'Z')) || ((ch>='a') && (ch <= 'z'));
    }

    string decodeString(string s)
    {
        int currNum = 0;
        string currStr;
        stack<int> numSt;
        stack<string> strSt;
        string prev;
        for (const auto ch:s)
        {
            if (isDigit(ch))
            {
                currNum = currNum*10+ch-'0';
            }
            else if (isAlphabet(ch))
            {
                currStr+=ch;
            }
            else if (ch == '[')
            {
                numSt.push(currNum);
                currNum = 0;
                strSt.push(currStr);
                currStr.erase();
            }
            else if (ch == ']')
            {
                prev=strSt.top();
                strSt.pop(); 
                int num = numSt.top();
                numSt.pop(); 
                for (int i = 0; i<num; i++ )
                {
                    prev+=currStr;
                }
                currStr= prev;
            }
            else
            {
                // error
            }
        }   
        return currStr;
    }
};






class Solution2 {
public:
    bool isDigits(const char ch)
    {
        return (ch>='0') && (ch <= '9');
    }
    
    bool isAlphabets(const char ch)
    {
        return ((ch>='A') && (ch <= 'Z')) || ((ch>='a') && (ch <= 'z'));
    }
    
    string decodeString(string s) {
        int currNum = 0;
        string currStr;
        string preStr;
        stack<int> numSt;
        stack<string> strSt;
        for (const auto& ch:s)
        {
            if (isDigits(ch))
            {
                currNum = currNum*10 + (ch - '0');
            }
            else if (isAlphabets(ch))
            {
                currStr+=ch;
            }
            else if (ch == '[')
            {
                numSt.push(currNum);
                currNum = 0;
                strSt.push(currStr);
                currStr.erase();
            }
            else if (ch == ']')
            {
                preStr = strSt.top();
                strSt.pop();
                // assume string is valid, here numSt is not empty
                int repeat = numSt.top();
                numSt.pop();
                
                for (int i = 0; i<repeat; i++)
                {
                    preStr +=currStr;
                }
                currStr = preStr;
            }
            else
            {
                return "Invalid character";
            }
        }
        return currStr;
    }
};