class Solution {
public:
    bool canJump(vector<int> &temp) 
    {
        if(temp[0]==0 && temp.size()==1)//SINCE ALREADY AT LAST
          return true;
        vector<int>arr=temp;
        int n=arr.size();
        for(int i=1;i<n;i++)
            arr[i]=max(arr[i-1],arr[i]+i);//STORE THE MAX INDEX THAT CAN BE REACHED
        //IF THE ARR IS ONLY FROM 0 TO i      
        for(int i=0;i<n;i++)
        {
            if(arr[i]==i && temp[i]==0)//IF AT ith INDEX MAX INDEX REACHED IS i AND SINCE temp[i]==0
            //HENCE LOCKED AND CANNOT MOVE FURTHER
              return false;
            if(arr[i]>=n-1)//IF THE INDEX REACHED IS >= LAST INDEX THEN TRUE
              return true;
        }
        return false;
    }
};