/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* solve(vector<vector<int>>& grid , int rstart , int rend , int cstart , int cend){
        int zeros = 0;
        int ones = 0;

        for(int i = rstart; i <= rend; i++){
            for(int j = cstart; j <= cend; j++){
                if(grid[i][j] == 1) ones++; 
                else zeros++;
            }
        }

       

        int expected = ((rend - rstart) + 1) * ((cend - cstart) + 1);
        cout<<zeros<<" "<<ones<<" "<<expected<<endl;

        int rmid = ((rend - rstart) / 2) + rstart;
        int cmid = ((cend - cstart) / 2) + cstart;

        if((zeros != expected) && (ones != expected)){
            Node* node = new Node(1 , 0);
            node->topLeft = solve(grid , rstart , rmid , cstart , cmid);
            node->topRight = solve(grid , rstart , rmid , cmid + 1 , cend);
            node->bottomLeft = solve(grid , rmid + 1 , rend, cstart , cmid);
            node->bottomRight = solve(grid , rmid + 1 , rend , cmid + 1 , cend);
            return node;

        }else if(expected == zeros){
            Node* node = new Node(0 , 1);
            return node;
        }

        Node* node = new Node(1 , 1);
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return solve(grid , 0 , n - 1 , 0 , n - 1);
    }
};