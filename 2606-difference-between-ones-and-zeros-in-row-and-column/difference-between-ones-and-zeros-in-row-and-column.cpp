class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        vector<int> c0(g[0].size()), c1(g[0].size()), r0(g.size()), r1(g.size());

        for (int i = 0; i < g.size(); i++) {
            int z = 0, o = 0;
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == 0) z++;
                else o++;
            }
            r0[i] = z;
            r1[i] = o;
        }

        for (int j = 0; j < g[0].size(); j++) {
            int z = 0, o = 0;
            for (int i = 0; i < g.size(); i++) {
                if (g[i][j] == 0) z++;
                else o++;
            }
            c0[j] = z;
            c1[j] = o;
        }

        vector<vector<int>> diff(g.size(), vector<int>(g[0].size()));
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                diff[i][j] = r1[i] + c1[j] - r0[i] - c0[j];
            }
        }
        return diff;
    }
};
