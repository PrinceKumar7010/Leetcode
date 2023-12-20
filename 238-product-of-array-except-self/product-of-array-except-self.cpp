class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(),0);
int zc=0,pz=1,po=1;
for(int i=0;i<nums.size();i++){
    if(nums[i]!=0){

    pz=nums[i]*pz;
    
    zc++;
    }

    po=nums[i]*po;

}

if((nums.size()-zc)>1){
    return v;
}
if((nums.size()-zc)==1)
{
for(int i=0;i<nums.size();i++){
    if(nums[i]==0){
        nums[i]=pz;
        v[i]=nums[i];
        return v;
}

}
}

for(int i=0;i<nums.size();i++){
    nums[i]=pz/nums[i];
    v[i]=nums[i];
}
return v;
    }
};