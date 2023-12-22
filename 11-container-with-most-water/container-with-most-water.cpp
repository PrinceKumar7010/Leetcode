class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int mx=0;
        while(i<=j){
        int ar=(j-i)*min(height[i],height[j]);
        mx=max(mx,ar);
        if(height[i]<height[j])i++;
        else{ j--;}

        }
        return mx;
    }
};