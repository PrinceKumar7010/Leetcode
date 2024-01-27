class Solution {
public:
    int compress(vector<char>& c) {
        char x = c[0];
        int l = 1;
        if (c.size() <= 1)
            return c.size();
        string p = "";

        for (int i = 1; i < c.size(); i++) {
            if (c[i] == x) {
                l++;
            }
            if (c[i] != x) {
                p += x;
                if(l>1){
                string h = to_string(l);
                p += h;}
                l = 1;
            }
            x = c[i];
        }
        p += x;
        if (l >1) {
            string countStr = to_string(l);
            p += countStr;
        }
        c.clear();
        for(int i=0;i<p.length();i++){
          c.push_back(p[i]);
        }
       
        return p.length();
    }
};