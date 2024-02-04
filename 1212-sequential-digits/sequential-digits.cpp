#include <vector>
#include <string>

class Solution {
public:
    int len(int n) {
        int c = 0;
        while (n > 0) {
            c++;
            n /= 10;
        }
        return c;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<char> ref = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        vector<int> res;

        int lowLen = len(low);
        int highLen = len(high);

        for (int len = lowLen; len <= highLen; len++) {
            for (int start = 0; start <= 9 - len; start++) {
                string numStr;
                for (int i = start; i < start + len; i++) {
                    numStr += ref[i];
                }
                int num = stoi(numStr);
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        
        return res;
    }
};