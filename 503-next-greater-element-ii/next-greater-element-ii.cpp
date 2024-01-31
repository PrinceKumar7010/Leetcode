class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(2*n,-1);
        vector<int> nums1=nums;
        
        for(int i=0;i<n;i++){
nums1.push_back(nums[i]);
        }

        stack<int>st;

        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums1[i])st.pop();

            if(!st.empty())v[i]=st.top();
            st.push(nums1[i]);
        }
   
    for(int i=0;i<n;i++)v.pop_back();
         return v;
    }
};