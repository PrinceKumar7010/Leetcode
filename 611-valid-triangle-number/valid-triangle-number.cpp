class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //Two pointers approach
        //for a b c to form a triangle we should satisfy 3 conditions 
        // a+b>c b+c>a c+a>b
        //let us assume a<b<c ...then no need of checking two conditions 
        // as c is already greater even if we add b or a it is still 
        // be greater
        if(nums.size() < 3){
            return 0;
        }
        sort(nums.begin(),nums.end());

        // now we know c is always greater than a b

        int left,right,ans=0;
        for(int i=2;i<nums.size();i++){
            left=0;
            right=i-1;
            while(left < right){
                if(nums[left]+nums[right] > nums[i]){
                    ans=ans+(right-left);
                    right--;
                }
                else left++;
            }
        }
        return ans;


    }
};