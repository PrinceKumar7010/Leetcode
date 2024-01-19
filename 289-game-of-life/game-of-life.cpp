class Solution {
public:
    int m;
    int n;
    vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dy = {1, -1, 0, 1, -1, 0, 1, -1};
    bool isValid(vector<vector<int>>& board, int i, int j){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    vector<int> countNeighbours(vector<vector<int>>& board, int i, int j){
        int live = 0;
        int dead = 0;

        for(int k=0;k<8;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(board, x, y)){
                if(board[x][y] == 1 || board[x][y] == 3){
                    live++;
                }
                else{
                    dead++;
                }
            }
        }
        return {live, dead};
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<int> neighbours = countNeighbours(board, i, j);
                int live = neighbours[0];
                int dead = neighbours[1];
                if(board[i][j] == 1 && (live<2 || live>3)){
                    board[i][j] = 3;
                }
                else if(board[i][j] == 0 && live==3){
                    board[i][j] = 2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 3){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else{
                    continue;
                }
            }
        }
    }
};