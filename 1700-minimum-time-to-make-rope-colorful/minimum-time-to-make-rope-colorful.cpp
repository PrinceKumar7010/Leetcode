class Solution {
public:
    int minCost(std::string s, std::vector<int>& neededTime) {
        int sum = 0;
        char curr = s[0];
        int maxTime = neededTime[0];

        for (int i = 1; i < neededTime.size(); i++) {
            if (curr == s[i]) {
                if (neededTime[i] > maxTime) {
                    sum += maxTime;
                    maxTime = neededTime[i];
                } else {
                    sum += neededTime[i];
                }
            } else {
                curr = s[i];
                maxTime = neededTime[i];
            }
        }
        return sum;
    }
};