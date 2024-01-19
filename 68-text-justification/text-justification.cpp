class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string s;
        vector<string> linewords;
        int len = 0;

        for(auto word: words){
            if(len + word.size() + linewords.size() - 1 >= maxWidth){
                if(linewords.size() == 1){
                    s += linewords[0];
                    while(s.size() < maxWidth){
                        s += " ";
                    }
                }
                else{
                    int strlen = len;
                    int extra = maxWidth - strlen;
                    int space = extra / (linewords.size() - 1);
                    int rem = extra % (linewords.size() - 1);

                    for(int j=0;j<linewords.size();j++){
                        s += linewords[j];
                        if(j == linewords.size() - 1){
                            continue;
                        }
                        int k = 0;
                        while(k < space){
                            s += " ";
                            k++;
                        }
                        if(rem > 0){
                            s += " ";
                            rem--;
                        }
                    }
                }
                
                ans.push_back(s);
                len = 0;
                s.clear();
                linewords.clear();
                linewords.push_back(word);
                len += word.size();
            }
            else{
                len += word.size();
                linewords.push_back(word);
            }
        }

        string last;
        for(int j=0;j<linewords.size();j++){
            last += linewords[j];
            if(j == linewords.size() - 1){
                continue;
            }
            last += " ";
        }
        while(last.size() < maxWidth){
            last += " ";
        }
        ans.push_back(last);

        return ans;
    }
};