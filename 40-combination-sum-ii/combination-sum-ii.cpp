class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& coin, int target) {
        sort(coin.begin(), coin.end());
        vector<vector<int>> v;
        vector<int> m;
        printCombination(coin, target, m, v, 0);
        return v;
    }
    void printCombination(vector<int> coin, int amount, vector<int> &m, vector<vector<int>> &v, int idx)
{
    if (amount == 0)
    {
        v.push_back(m);
        return;
    }
    for (int i = idx; i < coin.size(); i++)
    {
        if (idx != i  &&coin[i - 1] == coin[i]  )
        {
        continue;
        }
        if (amount < coin[i])
        {
            break;
        }
            m.push_back(coin[i]);
            printCombination(coin, amount - coin[i], m, v, i + 1);
            m.pop_back();
    }
}
};