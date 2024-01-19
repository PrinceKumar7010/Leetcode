class Solution {
public:
    void dfs(vector<vector<char>>& board,int row,int col,vector<vector<int>>&visted){
        int ver[4]={-1,1,0,0};
        int hor[4]={0,0,-1,1};
        int r=board.size();
        int c=board[0].size();
        visted[row][col]=1;
            for(int i=0;i<4;i++){
                int nrow=row+ver[i];
                int ncol=col+hor[i];
                if(nrow>0 && nrow<r && ncol>0 && ncol<c && visted[nrow][ncol]!=1 && board[nrow][ncol]=='O'){
                    dfs(board,nrow,ncol,visted);
                }
            }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>>visted(row,vector<int>(col,0));
        for(int i=0;i<col;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i,visted);
            }
            if(board[row-1][i]=='O'){
                dfs(board,row-1,i,visted);
            }
        }
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,visted);
            }
            if(board[i][col-1]=='O'){
                dfs(board,i,col-1,visted);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visted[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};