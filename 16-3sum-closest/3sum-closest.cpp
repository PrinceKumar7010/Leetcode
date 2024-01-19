class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
    
       int sum=0;
       int ans;

        for(int i=0; i<nums.size(); i++)
        {
            int starting=i+1;
            int ending=nums.size()-1;
            while(starting<ending)
            {
                 sum=nums[i]+nums[starting]+nums[ending];
                if(sum==target)
                {
                    return sum;
                }
                if(sum<target)
                {
                    starting++;
                }
                else
                {
                    ending--;
                }
                if(abs(sum-target)<abs(ans-target))
                {
                    ans=sum;
                }

            }
           
        }
         return ans;
       
      
        
    }
};