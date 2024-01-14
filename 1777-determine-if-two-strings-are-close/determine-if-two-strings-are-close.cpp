class Solution {
public:
    bool closeStrings(string word1, string word2) {
      vector<int> v1(26,0);
        vector<int> v2(26,0);
        vector<int> v11(26,0);
        vector<int> v21(26,0);

        for (auto i:word1){
            v1[i-'a']++;
            v11[i-'a']=1;
        }
         for (auto i:word2){
            v2[i-'a']++;
            v21[i-'a']=1;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return ((v1==v2)and(v11==v21));

    }
};