class Solution {
public:
    int maxDepth(string s) {
        int c=0;
        int mx=0;
      

        for(int i=0;i<s.length();i++){
           
           if(s[i]=='('){
              
               c++;
               mx=max(c,mx);
               }
                if(s[i]==')'){
    
               c--;
             
               }

        }
        return mx;
    }
};