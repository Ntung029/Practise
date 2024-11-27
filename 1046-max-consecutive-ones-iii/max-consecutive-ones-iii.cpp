class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int result = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                k--;
            }

            if (k<0)
            {
                k += 1-nums[l];
                l++;
            }
            result = max(result, i-l+1);
        }
        return result;
    }
};