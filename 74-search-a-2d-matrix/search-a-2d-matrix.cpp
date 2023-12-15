class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int row=matrix.size();
        int col=matrix[0].size();


        int s=0;
        int l=row*col-1;
        int m=s+(l-s)/2;
        while(s<=l){
        int e=matrix[m/col][m%col];
        if(e==t){
            return 1;
        }
if(e<t)s=m+1;
else{
    l=m-1;
}
m=s+(l-s)/2;

        }
return 0;


        
    }
};