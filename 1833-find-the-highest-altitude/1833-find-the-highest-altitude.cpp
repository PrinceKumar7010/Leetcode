class Solution {
public:
    int largestAltitude(vector<int>& gain) {
int i=0;
int max=INT_MIN;
int sum=0;
while(i<gain.size()){
int s=gain[i];
sum=s+sum;
if(sum>max)max=sum;
i++;
}
if(max<0)return 0;

return max;

    }
};