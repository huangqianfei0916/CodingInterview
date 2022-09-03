#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int count = 0;
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dfs(0, 0, k, m, n, vis);
        cout << count << endl;
        return count;
    }

    void dfs(int i, int j, int k, int m, int n, vector<vector<bool>> vis) {
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

int main() {
    Solution* s = new Solution();
    s->movingCount(3, 2, 17);
}