class Solution {
public:    
    set<vector<int>> st;
    void helper(int i, vector<int> &nums, vector<int> temp){
        if(i<0){
            sort(temp.begin(),temp.end());
            st.insert(temp);
        return;
        }
        helper(i-1,nums,temp);
        temp.push_back(nums[i]);
        helper(i-1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> result;
        vector<int> temp;
        int n=nums.size();
        helper(n-1,nums,temp);
        for(auto it : st){
            result.push_back(it);
        }
    return result;        
    }
};