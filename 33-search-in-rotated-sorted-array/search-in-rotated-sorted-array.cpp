class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int i=0;
        int j=nums.size()-1;


        while(i<=j){

int mid=(i+j)/2;
if(nums[mid]==target)return mid;
if(nums[i]<=nums[mid]){
    if(nums[mid]>=target && target>=nums[i]){
      j=mid-1;
    }
    else i=mid+1;
}
if(nums[j]>=nums[mid]){
    if(nums[mid]<=target && target<=nums[j]){
      i=mid+1;
    }
    else j=mid-1;
}



        }
        return -1;


    }
};