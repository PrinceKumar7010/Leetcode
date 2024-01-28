class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) {
            return 1;
        }
        if (k == 1) {
            return n - 1;
        }
    std::vector<std::vector<long long>> list(2, std::vector<long long>(k + 1, 0));
        list[0][0] = 1;
        list[0][1] = 1;
        list[1][0] = 1;
        int j;
        int last = 0;
        int now = 0;
        for (int i = 3; i <= n; i++) {
            now = i % 2;
            int k_max = ((i - 1) * i) / 2;
            list[now][1] = i - 1; 
            int min = k < i ? k + 1 : i;
            list[now][2] = list[last][0] + list[last][1] + list[last][2];
            for (j = 3; j < min; j++) {
                list[now][j] = (list[now][j - 1] + list[last][j]) % 1000000007;
            }
            int count = 0;
            for (; j <= k; j++) {
                if (j >= k_max) {
                    list[now][k_max] = 1;
                    break;
                }
                list[now][j] = (list[now][j - 1] + list[last][j] - list[last][count] + 1000000007) % 1000000007;
                count++;
            }
            last = now;
        }
        int ans = list[now][k];
        return ans;
    }
};