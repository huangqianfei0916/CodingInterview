#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<bool>> vis;
    int index = 0;
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vis.resize(row);

        for (int i = 0; i < row; ++i) {
            vis[i].resize(col);
        }

        bool flag = false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs (board, i, j, word, row, col)) {
                        return true;
                    }
                }
            }
        }
        return flag;
    }
    bool dfs(vector<vector<char>> board, int i, int j, string word, int row, int col) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= row || j >= col || j < 0 || board[i][j] != word[index] || vis[i][j]) {
            return false;
        }
        ++index;
        vis[i][j] = true;
        bool flag = false;
        flag = dfs(board, i + 1, j, word, row, col) ||
                    dfs(board, i - 1, j, word, row, col) ||
                    dfs(board, i, j + 1, word, row, col) ||
                    dfs(board, i, j - 1, word, row, col);
        if (!flag) { --index; vis[i][j] = false; }

        return flag;
    }

};

int main() {
    Solution s;
    vector<vector<char>> vec = 
{{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAB";
    bool d = s.exist(vec, word);
    cout << d << endl;
    return 0;
}