class Solution {
public:

    bool palind(string a){
     string h=a;
     reverse(a.begin(),a.end());

     return (h==a);

    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
         if(palind(words[i]))return words[i];


        }
        string a="";
        return a;


    }
};