**矩阵中路径**
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
```cpp
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
                    flag = dfs (board, i, j, word, row, col);
                    if (flag) {
                        return flag;
                    }
                }
            }
        }
        return flag;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string word, int row, int col) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= row || j >= col || j < 0 || board[i][j] != word[index] || vis[i][j]) {
            return false;
        }
        ++index;
        vis[i][j] = true;
        bool flag = dfs(board, i + 1, j, word, row, col) ||
                    dfs(board, i - 1, j, word, row, col) ||
                    dfs(board, i, j + 1, word, row, col) ||
                    dfs(board, i, j - 1, word, row, col);
        if (!flag) {
            --index;
            vis[i][j] = false;
        }

        return flag;
    }
};
```
#### 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
**注意：这里的vis使用引用传递或者使用全局变量**
```cpp
class Solution {
public:
    int count = 0;
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dfs(0, 0, k, m, n, vis);
        return count;
    }
//vis 采用局部变量时候，记得采用引用，因为dfs回来时候会重置状态，全局变量不会。
    void dfs(int i, int j, int k, int m, int n, vector<vector<bool>>& vis) {
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || (dig(i) + dig(j)) > k) {
            return;
        }

        ++count;
        vis[i][j] = true;
        dfs(i + 1, j, k, m, n, vis);
        dfs(i - 1, j, k, m, n, vis);
        dfs(i, j + 1, k, m, n, vis);
        dfs(i, j - 1, k, m, n, vis);
    }

    int dig(int num) {
        int res = 0;
        while (num != 0) {
            int temp = num % 10;
            res += temp;
            num = num / 10;
        }
        return res;
    }
};
```

