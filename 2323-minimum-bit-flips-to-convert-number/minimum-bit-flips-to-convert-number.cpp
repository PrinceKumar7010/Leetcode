class Solution {
public:
    int minBitFlips(int start, int goal) {
     bitset <32> a(start);
     bitset <32> b(goal);
     int c=0;
     cout<<a<<endl<<b;
     for(int i=0;i<32;i++){
         if(a[i]!=b[i])c++;
     }
     return c;


    }
};