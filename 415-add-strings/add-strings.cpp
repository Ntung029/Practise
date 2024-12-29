class Solution {
public:

    
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry = 0;
        int i = 0;
        int a = 0;
        int b = 0;
        string result;
        while ((i<num1.size()) || (i<num2.size()) || (carry>0))
        {
            if (i>=num1.size())
            {
                a = 0;
            }
            else
            {
                a = num1[i]-'0';
            }

            if (i>=num2.size())
            {
                b = 0;
            }
            else
            {
                b = num2[i]-'0';
            }

            int val = a+b+carry;
            result = to_string(val%10) + result;
            carry = val/10;
            i++;
        }
        return result;
    }
};