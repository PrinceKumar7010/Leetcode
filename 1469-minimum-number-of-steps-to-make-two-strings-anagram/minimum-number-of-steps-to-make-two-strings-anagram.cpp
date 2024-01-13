class Solution {
public:
    int minSteps(string s, string t) {
       vector <int> fr(26,0);
       int sum=0;
       for(int i=0;i<s.length();i++){
           fr[s[i]-'a']++;
       }
        for(int i=0;i<t.length();i++){
                fr[t[i]-'a']--;
            }
      for(auto i: fr){
          if(i>0)sum+=i;
      }
return sum;

    }
};