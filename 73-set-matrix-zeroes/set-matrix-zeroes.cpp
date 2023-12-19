class Solution {
public:

   
void setZeroes(vector<vector<int>>& m) {
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[0].size(); j++){
            if(m[i][j] == 0){
                for(int q=0; q<m[i].size(); q++){
                    if(m[i][q] != 0) {
                        if(m[i][q] != -1e9) {
                            m[i][q] = -1e9;
                        }
                    }
                }
                for(int q=0; q<m.size(); q++){
                    if(m[q][j] != 0) {
                        if(m[q][j] != -1e9) {
                        
                            m[q][j] = -1e9;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[0].size(); j++){
            if(m[i][j] == -1e9){
                
                m[i][j] = 0;
            }
        }
    }
}

};