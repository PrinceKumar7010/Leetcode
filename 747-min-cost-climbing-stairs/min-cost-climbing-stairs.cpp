class Solution {
public:
    int ans(vector<int>& cost,int n){
      
        if(n<=1) return cost[0];
        for(int i=2;i<n;i++)cost[i]+=min(cost[i-1],cost[i-2]);
            return min(cost[n-1],cost[n-2]);
         }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return ans(cost,n);
    }
};