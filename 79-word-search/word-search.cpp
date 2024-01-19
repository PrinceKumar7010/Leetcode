class Solution {
public:
    // Recursive function to traverse the board and search for the word
    // Parameters:
    //   - board: the board of characters
    //   - n, m: dimensions of the board
    //   - word: the word to search for
    //   - wordIndex: current index in the word
    //   - used: matrix to track used cells in the board
    //   - bx, by: current position on the board
    //   - answer: reference to a boolean indicating if the word is found
    void trav(vector<vector<char>>& board, int n, int m, string word, int wordIndex, vector<vector<bool>>& used, int bx, int by, bool& answer) {
        // If the answer is already found, return early
        if (answer) return;

        // If we reached the end of the word, set answer to true and return
        if (wordIndex == word.size()) {
            answer = true;
            return;
        }

        // Check the cell below
        if (bx != n - 1 && !used[bx + 1][by] && board[bx + 1][by] == word[wordIndex]) {
            used[bx + 1][by] = true;
            trav(board, n, m, word, wordIndex + 1, used, bx + 1, by, answer);
            used[bx + 1][by] = false;
        }

        // Check the cell above
        if (bx != 0 && !used[bx - 1][by] && board[bx - 1][by] == word[wordIndex]) {
            used[bx - 1][by] = true;
            trav(board, n, m, word, wordIndex + 1, used, bx - 1, by, answer);
            used[bx - 1][by] = false;
        }

        // Check the cell to the right
        if (by != m - 1 && !used[bx][by + 1] && board[bx][by + 1] == word[wordIndex]) {
            used[bx][by + 1] = true;
            trav(board, n, m, word, wordIndex + 1, used, bx, by + 1, answer);
            used[bx][by + 1] = false;
        }

        // Check the cell to the left
        if (by != 0 && !used[bx][by - 1] && board[bx][by - 1] == word[wordIndex]) {
            used[bx][by - 1] = true;
            trav(board, n, m, word, wordIndex + 1, used, bx, by - 1, answer);
            used[bx][by - 1] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        // Matrix to track used cells in the board
        vector<vector<bool>> used(n, vector<bool>(m, false));

        // Variable to store the final answer
        bool answer = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell matches the first letter of the word and the answer is not found yet
                if (board[i][j] == word[0] && !answer) {
                    // Mark the cell as used and start the traversal
                    used[i][j] = true;
                    trav(board, n, m, word, 1, used, i, j, answer);
                    used[i][j] = false; // Unmark the cell after traversal
                }
            }
        }
        return answer;
    }
};