class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int mx=prices[n-1];
        vector<int> v(n+1,-1);
        v[n-1]=mx;
        for(int j=n-2;j>=0;j--){
           
            mx=max(mx,prices[j]);
            v[j]=mx;

        }
        for(auto i:v){
            cout<<i<<" ";
        }
        int y=0;
        for(int i=0;i<prices.size();i++){
            y=max(y,v[i]-prices[i]);
        }
        return y;
    }
};