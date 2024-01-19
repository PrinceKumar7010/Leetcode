class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        int i,j;
        for(i=0;i<intervals.size();i++)
        {
            if(intervals[i][1]<newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int> tmp;
                if(newInterval[0]<intervals[i][0])
                    tmp.push_back(newInterval[0]);
                else
                    tmp.push_back(intervals[i][0]);
                for(j=i;j<intervals.size();j++)
                {
                    if(newInterval[1]<=intervals[j][1])
                    {
                        if(newInterval[1]<intervals[j][0])
                        {
                            tmp.push_back(newInterval[1]);
                        }
                        else
                        {
                            tmp.push_back(intervals[j][1]);
                            j++;
                        }
                        ans.push_back(tmp);
                        break;
                    }
                }
                if(j==intervals.size() && tmp.size()==1)
                {
                    tmp.push_back(newInterval[1]);
                    ans.push_back(tmp);
                }
                break;
            }
        }
        for(i=j;i<intervals.size();i++)
            ans.push_back(intervals[i]);

        cout << newInterval.size() << endl;
        if(newInterval[0]>intervals[intervals.size()-1][1])
        {
            ans.push_back(newInterval);
        }
        return ans;
    }
};