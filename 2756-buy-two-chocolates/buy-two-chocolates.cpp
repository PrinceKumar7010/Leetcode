class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int i=0,j=0;

        if(prices[0]+prices[1]>money)return money;
        else if(prices[0]+prices[1]<money)return money-(prices[0]+prices[1]);
        return 0;


    }
};