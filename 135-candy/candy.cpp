class Solution {
public:
int candy(vector<int>& ratings) {
    vector<int>candies(ratings.size(), 1);
    for(int i=1;i<ratings.size();i++){
        if(ratings[i]>ratings[i-1])
            candies[i]=candies[i-1]+1;
    }
    for(int i=ratings.size()-1;i>0;i--){
        if(ratings[i-1]>ratings[i] && candies[i-1]<=candies[i])
            candies[i-1]=candies[i]+1;
    }
    int ans=0;
    for(int i=0;i<candies.size();i++)
        ans+=candies[i];
    return ans;
}
};