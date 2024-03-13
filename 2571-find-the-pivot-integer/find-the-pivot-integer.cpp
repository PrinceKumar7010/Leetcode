class Solution {
public:


    int cal(int x){
        return (x*(x+1))/2;
    }
    int pivotInteger(int n) {
     int sum=0; 
     for(int i=n;i>=0;i--){
        sum+=i;
          if(cal(i)==sum)return i;
          
     }
     return -1;
    }
};