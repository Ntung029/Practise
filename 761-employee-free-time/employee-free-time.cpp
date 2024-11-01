/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    void mergeIntervals(vector<Interval>& s, Interval a)
    {
        // merge intervala to s
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        map<int,int> mp;
        int N = schedule.size();
        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j< schedule[i].size(); j++)
            {
                int s = schedule[i][j].start;
                int e = schedule[i][j].end;
                if (mp.end() != mp.find(s))
                {
                    mp[s] = max(mp[s],e);
                }
                else
                {
                    mp[s] = e;
                }
            }
        }

        // find the free schedule
        vector<Interval> result;
        int prev = -1;
        for (const auto it:mp)
        {
            if ((prev !=-1) && (it.first>prev))
            {
                result.push_back(Interval(prev,it.first));
            }
            prev = max(prev,it.second);
        }
        return result;
    }

    vector<Interval> employeeFreeTime2(vector<vector<Interval>> schedule) {
        /*
            -1 1 3 4 10 100
        */

        map<int,int> mp;
        int N = schedule.size();
        for (int i = 0; i<N; i++)
        {
            for (int j = 0; j<schedule[i].size(); j++)
            {
                int s = schedule[i][j].start;
                int e = schedule[i][j].end;
                if (mp.end() != mp.find(s))
                {
                    mp[s] = max(mp[s],e);
                }
                else
                {
                    mp[s] = e;
                }
            }
        }
        vector<Interval> res;
        int prev = -1;
        for (auto& it:mp)
        {
            if ((prev !=-1) && (prev < it.first))
            {
                res.push_back(Interval(prev,it.first));
            }
            prev = max(prev,it.second);
        }
        return res;
    }
};