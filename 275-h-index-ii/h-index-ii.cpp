class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        int low = 0;
        int high = n-1;
        int ans = 0;

        while(low<=high){

            int mid = low + (high-low)/2;

            if(n-mid==citations[mid]) return citations[mid];

            else if(n-mid<citations[mid]){
                ans = n-mid;
                high = mid-1;
            }

            else low = mid+1;

        }

        return ans;
    }
};