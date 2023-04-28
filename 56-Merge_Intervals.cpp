class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;

        vector<vector<int>> results;

        sort(intervals.begin(), intervals.end());

        results.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(results.back()[1] >= intervals[i][0])
            {
                // Overlapping => merge by changing the end of interval
                results.back()[1] = max(intervals[i][1], results.back()[1]);
            }
            else
            {
                results.push_back(intervals[i]);
            }
        }

        return results;
    }
};
