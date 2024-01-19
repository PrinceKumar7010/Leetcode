class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        int sze = s.size(); 
        string result = "";
        for(int start = 0; start < numRows; start++){
            bool downN = false; 
            if(start < numRows - 1){
                downN = true;
            }
            for(int roamingIndex = start; roamingIndex<sze; ){
                result += s[roamingIndex];
                if(downN){
                    int jump = numRows -1 - start;
                    //cout << "nextJump: " << 2*jump << "\n";
                    roamingIndex += 2*jump;
                }else{
                    int jump = start;
                    //cout << "nextJump: " << 2*jump << "\n";
                    roamingIndex += 2*jump;
                }

                if(start < numRows - 1 && start > 0){
                    downN = !downN;
                }
            }
        }
        return result;
    }
};