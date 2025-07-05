//https://leetcode.com/problems/word-search/

class Solution {
public:
    int n, m;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool find(vector<vector<char>>& board, int i, int j, int ind, string word) {
        if (ind == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$' || board[i][j] != word[ind]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for (auto &dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if (find(board, new_i, new_j, ind + 1, word)) {
                return true;
            }
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        if (n == 0) return false;
        m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
