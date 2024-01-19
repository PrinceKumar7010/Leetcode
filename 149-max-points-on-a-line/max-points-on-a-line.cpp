class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxOnTheLine = 0;
        int n = points.size();

        for (int idx1 = 0; idx1 < n; idx1++) {
            map<double, int> freq;
            for (int idx2 = 0; idx2 < n; idx2++) {
                if (idx1 == idx2) {
                    continue;
                }
                double slope = (double)(points[idx1][0] - points[idx2][0]) / (points[idx1][1] - points[idx2][1]);
                freq[slope]++;
                if (freq[slope] > maxOnTheLine) {
                    maxOnTheLine = freq[slope];
                }
            }
        }

        return maxOnTheLine + 1;
    }
};