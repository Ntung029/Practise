class Solution {
public:
    
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int N = costs.size();
        vector<long long> dp(N,LONG_LONG_MAX);
        dp[0] = 0;
        stack<int> ge;
        stack<int> lt;

        for (int i = 0; i<N; i++)
        {
            while ((!ge.empty()) && (nums[ge.top()]<=nums[i]))
            {
                dp[i] = min(dp[i],dp[ge.top()]+costs[i]);
                ge.pop();
            }
            ge.push(i);

            while ((!lt.empty()) && (nums[lt.top()]>nums[i]))
            {
                dp[i] = min(dp[i],dp[lt.top()]+costs[i]);
                lt.pop();
            }
            lt.push(i);
        }
        return dp[N-1] == LONG_LONG_MAX ? -1:dp[N-1];
    }
};

class Solution2 {
public:
    
    long long minCost(vector<int>& nums, vector<int>& costs) {
        vector<long long> dp(costs.size(),LONG_LONG_MAX);
        dp[0] = 0;
        stack<int> ge;
        stack<int> lt;
        

        for (int i = 0; i<costs.size(); i++)
        {
            // increasing monotonic stack
            while (!ge.empty() && (nums[ge.top()] <= nums[i]))
            {
                dp[i] = min(dp[i],dp[ge.top()] + costs[i]);
                ge.pop();
            }
            ge.push(i);
            // decreasing monotinic stack
            while (!lt.empty() && (nums[lt.top()] > nums[i]))
            {
                dp[i] = min(dp[i],dp[lt.top()] + costs[i]);
                lt.pop();
            }
            lt.push(i);
        }
        return dp[costs.size()-1];
    }
};