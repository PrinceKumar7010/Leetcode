class Solution {
public:
    vector<int> countBits(int n) {
vector<int> v;
     for(int i=0;i<=n;i++){
         int cn=0;
         int y=i;
        while(y){
            if(y&1==1)cn++;
            y=y>>1;
        }
        v.push_back(cn);
     } 
     
return v;
    }
};