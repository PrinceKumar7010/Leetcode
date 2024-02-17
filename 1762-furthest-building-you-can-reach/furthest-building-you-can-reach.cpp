class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<long long> pq;
        long long sum = 0;
        long long last = -1;
        for(int i = 1; i<n; i++){
            long long next = heights[i] - heights[i-1];
            if(next > 0){
                pq.push(next);
                sum += next;
            }
            if(sum > bricks){
                if(ladders > 0){
                    sum -= pq.top();
                    pq.pop();
                    ladders--;
                }
                else return i - 1;
            }
        }
        return n-1;
    }
};