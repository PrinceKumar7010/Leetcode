class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subarr(nums.size() - (k-1));
        subarr[0] = accumulate(nums.begin(), nums.begin()+k, 0);
        for( int i = 1 ; i < nums.size() - (k-1) ; i++ )
            subarr[i] = subarr[i-1] - nums[i-1] + nums[i+k-1];
        
        vector<pair<int, int>> max_subarr(subarr.size());
        max_subarr[0] = {subarr[0], 0}; // val, index choosen
        for( int i = 1 ; i < max_subarr.size() ; i++ )
            if( max_subarr[i-1].first < subarr[i] )
                max_subarr[i] = {subarr[i], i};
            else
                max_subarr[i] = max_subarr[i-1];

        // 2 subarr
        vector<int> dp2(max_subarr.size(), 0);
        for( int i = k ; i < dp2.size() ; i++ ) 
            dp2[i] = max_subarr[i-k].first + subarr[i];

        vector<pair<int, int>> max_dp2(dp2.size());
        max_dp2[0] = {dp2[0], 0}; // val, index choosen
        for( int i = 1 ; i < max_dp2.size() ; i++ )
            if( max_dp2[i-1].first < dp2[i] )
                max_dp2[i] = {dp2[i], i};
            else
                max_dp2[i] = max_dp2[i-1];
        
        // 3 subarr
        vector<int> dp3(max_subarr.size(), 0);
        for( int i = 2*k ; i < dp3.size() ; i++ )
            dp3[i] = max_dp2[i-k].first + subarr[i];

        // backtrack
        vector<int> ans;
        int last = 0;
        for( int i = 0 ; i < dp3.size() ; i++ )
            if( dp3[last] < dp3[i] )
                last = i;

        ans.push_back(last);
        ans.push_back(max_dp2[last-k].second);
        last = max_dp2[last-k].second;
        ans.push_back(max_subarr[last-k].second);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};