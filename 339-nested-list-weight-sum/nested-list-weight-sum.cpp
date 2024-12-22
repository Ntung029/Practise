/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        // using queue
        queue<NestedInteger> qu;
        for (const auto it:nestedList)
        {
            qu.push(it);
        }
        int level = 0;
        int sum = 0;
        while (!qu.empty())
        {
            level++;
            int n = qu.size();
            for (int i = 0; i<n; i++)
            {
                auto it = qu.front();
                qu.pop();
                if (it.isInteger())
                {
                    sum+=level*it.getInteger();
                }
                else
                {
                    for (const auto v:it.getList())
                    {
                        qu.push(v);
                    }
                }
            }
        }
        return sum;
    }
};