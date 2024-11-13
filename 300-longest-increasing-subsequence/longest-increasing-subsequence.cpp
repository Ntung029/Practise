class Solution {
    public:
        int lengthOfLIS(vector<int>& nums)
        {
            vector<int> lis;
            for (const auto num: nums)
            {
                auto idx = std::lower_bound(lis.begin(),lis.end(),num);
                if (idx == lis.end())
                {
                    lis.push_back(num);
                }
                else
                {
                    // replace num in lis
                    *idx = num;
                }
            }
            return lis.size();
        }
};

class Solution3 {
public:
// monotonic stack doesn't work
    int lengthOfLIS(vector<int>& nums) {
        stack<int> st;
        int result = 0;
        for (auto num:nums)
        {
            while (!st.empty() && (num < st.top()))
            {
         //       cout << st.top() << " ";
                st.pop();
            }
           // cout << endl;
            st.push(num);
            int n  = st.size();
            result = max(result, n);
        }
        return result;
    }
};
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> container;
        container.push_back(nums[0]);
        for (int i = 1; i<nums.size(); i++)
        {
            auto idx = std::lower_bound(container.begin(), container.end(),nums[i]);
            // all values in the container smaller than the current value: add to container
            if (container.end() == idx)
            {
                container.push_back(nums[i]);
            }
            else
            {
                // replace the value in the container with the smaller value: num[i]
                *idx = nums[i];
            }
        }
        return container.size();
    }
};