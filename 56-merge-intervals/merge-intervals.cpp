class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        sort(intervals.begin(), intervals.end()); // O(n*log(n)) runtime
        int last = 0; // O(1) memory
        int j;
        for (int i = 0; i < intervals.size();) {
            j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                j++;
            }
            if (last != i) {
                intervals[last] = intervals[i];
            }
            last++;
            i = j;
        }
        // vector<vector<int>> result(intervals.begin(), intervals.begin() + last);
        // return result;
        intervals.erase(intervals.begin() + last, intervals.end());
        return intervals;
    }
};