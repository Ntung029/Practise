class Solution2 {
public:
    Solution2(vector<int>& w) {
        //arr.push_back(0);
        total = 0;
        for (int i = 0; i<w.size(); i++)
        {
            total+=w[i];
            arr.push_back(total);
        }
    }
    
    int pickIndex() {
        int target =  rand() % arr.back();
        //cout << target << endl;
        return lower_bound(arr.begin(), arr.end(),target) - arr.begin();
    }
    vector<int> arr;
    int total;
};


class Solution {
    vector<int> prefixSums;

public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }
    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        return lower_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */