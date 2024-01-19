class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int c=1;
int start=points[0][0];
int end= points[0][1];
  
        for(int i=1;i<points.size();i++){
               if(points[i][0]>=start&&end>=points[i][0]){
                 start=points[i][0];
                 end=min(points[i][1],end);
                   continue;
               }else {
                   
                   start=points[i][0];
                   end=points[i][1];
                   
                   c++;
               }
        

        }
        return c;
    }
};