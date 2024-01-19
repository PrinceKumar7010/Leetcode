class Solution {
public:
    int compareVersion(string v1, string v2) {
        string a = "", b = "";
        int n = v1.size(), m = v2.size();
        int i = 0, j = 0;
        while(i < n || j < m) {
            int x = 0, y = 0;
            while(i < n && v1[i] != '.') {
                x = x * 10 + (v1[i++] - '0');
            }
            while(j < m && v2[j] != '.') {
                y = y * 10 + (v2[j++] - '0');
            }
            if(x < y) return -1;
            else if(x > y) return 1;
            i++;
            j++;
        }
        return 0;
    }
};