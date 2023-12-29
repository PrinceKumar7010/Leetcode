class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v1;
        int n=nums.size();
       for(int i=0;i<pow(2,n);i++){
           vector<int> v;
for(int j=0;j<=n;j++){
if(i&(1<<j))v.push_back(nums[j]);

}
v1.push_back(v);


       }
       return v1;
    }
};