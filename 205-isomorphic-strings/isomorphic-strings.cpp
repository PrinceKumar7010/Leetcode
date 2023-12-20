class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
        return false;
    }

    std::unordered_map<char, char> sToT;
    std::unordered_map<char, char> tToS;

    for (int i = 0; i < s.size(); ++i) {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT.count(sChar)) {
            if (sToT[sChar] != tChar) {
                return false;
            }
        } else {
            sToT[sChar] = tChar;
        }

        if (tToS.count(tChar)) {
            if (tToS[tChar] != sChar) {
                return false;
            }
        } else {
            tToS[tChar] = sChar;
        }
    }

    return true;
 
    }
};