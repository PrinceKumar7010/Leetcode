class Solution {
public:
    int hammingWeight(uint32_t n) {
       int mx=0;
       while(n){
           if((n&1)==1)mx++;
           n=n>>1;
       }
       return mx; 
    }
};