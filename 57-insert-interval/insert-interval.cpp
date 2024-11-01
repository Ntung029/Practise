class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int n = intervals.size();
        int l = 0;
        int r = n-1;
        while (l<=r)
        {
            int mid = (l+r)/2;
            if (intervals[mid][0]>=newInterval[0])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        // Insert newInterval at the found position
        intervals.insert(intervals.begin() + l, newInterval);
        
        // Merge overlapping intervals
        vector<vector<int>> ret;


        
        // insert the right portion
        for (int i = 0; i<intervals.size(); i++)
        {
            if ((ret.empty()) ||(ret.back()[1] < intervals[i][0]))
            {
                
                ret.push_back(intervals[i]);
            }
            else
            {
               ret.back()[1] = max(ret.back()[1],intervals[i][1]);
            }
        }
        return ret;
    }
};