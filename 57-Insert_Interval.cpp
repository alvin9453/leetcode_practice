class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int new_interval_left = newInterval[0];
        int new_interval_right = newInterval[1];
        vector<int> overlapping_interval;
        int overlapping_interval_right = new_interval_right;
        int overlapping_interval_left = new_interval_left;

        for(auto interval : intervals)
        {
            if( interval[1] < new_interval_left )
            {
                result.push_back(interval);
            }
            else if(interval[0] > new_interval_right)
            {
                result.push_back(interval);
            }
            else
            {
                if( new_interval_left >= interval[0] || new_interval_right <= interval[1])
                {
                    overlapping_interval_right = max(overlapping_interval_right, interval[1]);
                    overlapping_interval_left = min(overlapping_interval_left, interval[0]);
                }
            }
        }
        overlapping_interval.push_back(overlapping_interval_left);
        overlapping_interval.push_back(overlapping_interval_right);

        result.push_back(overlapping_interval);

        result.sort();

        return result;
    }
};
