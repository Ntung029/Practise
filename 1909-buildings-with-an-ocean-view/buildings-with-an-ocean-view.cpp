class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int maxRight = INT32_MIN;
        list<int> li;
        for (int i = heights.size()-1; i>=0; i--)
        {
            if (heights[i] > maxRight)
            {
                li.push_front(i);
                maxRight = heights[i];
            }
        }
        vector<int> result(li.begin(), li.end());
        return result;
    }
};