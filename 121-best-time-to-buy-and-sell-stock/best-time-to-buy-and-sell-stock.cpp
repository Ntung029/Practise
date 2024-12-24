class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto minPrice = prices[0];
        int result = -1;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            result = max(prices[i]-minPrice,result);
        }
        return result;
    }
};