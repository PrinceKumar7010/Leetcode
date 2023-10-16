class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int e) {
        vector<bool> v;
        int max=arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max)max=arr[i];
        }
         for(int i=0;i<arr.size();i++){
        if((arr[i]+e)>=max)v.push_back(true);
        else{
            v.push_back(false);
        }

         }
         return v;



    }
};