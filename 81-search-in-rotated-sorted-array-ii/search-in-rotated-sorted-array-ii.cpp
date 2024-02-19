class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
         int i=0;
        int j=nums.size()-1;


        while(i<=j){

int mid=(i+j)/2;
if(nums[mid]==target)return true;
if(nums[mid]<target){
 i=mid+1;
}
if(nums[mid]>target){
 j=mid-1;
}



        }
        return false;


    
    }
};