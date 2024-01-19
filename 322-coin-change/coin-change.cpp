class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int value[10001];
        value[0] = 0;
        for (int x = 1; x <= amount; x++)
        {
            value[x] = 1e5;
            for (auto c : coins)
            {
                if (x - c >= 0)
                {
                    value[x] = min(value[x], value[x - c] + 1);
                }
            }
        }

        return (value[amount] == 1e5)?-1:value[amount];
    }
};