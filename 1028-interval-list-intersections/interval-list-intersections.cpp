class Solution {
public:

    vector<vector<int>> intervalIntersection2(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        while ((i<firstList.size()) && (j<secondList.size()))
        {
            int left = max (firstList[i][0],secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if (left<=right)
            {
                result.push_back({left,right});
            }
            if (firstList[i][1] > secondList[j][1])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return result;
    }
    
    
    
    
    
    
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        while ((i<firstList.size()) && (j<secondList.size()))
        {
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);

            if (left<=right)
            {
                result.push_back({left,right});
            }

            if (firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};