class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        if (intervals.empty()) return result;
        result.push_back(intervals[0]);
        for (int i = 1; i<intervals.size(); i++)
        {
            if (result.back()[1] >= intervals[i][0])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ret;
        sort(intervals.begin(),intervals.end());
        if (intervals.empty()) return ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i< intervals.size(); i++)
        {
            if (intervals[i][0] <= ret.back()[1])
            {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
        
    }
};


class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(),intervals.end());
        for (const auto& interval:intervals)
        {
            if (ret.empty()) ret.push_back({interval[0],interval[1]});
            else
            {
                if (interval[0]<=ret.back()[1])
                {
                    ret.back()[1] = max(ret.back()[1],interval[1]);
                }
                else
                {
                    ret.push_back({interval[0],interval[1]});
                }
            }
        }    
        return ret;
    }
};