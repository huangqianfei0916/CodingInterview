#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    Solution(){

    }
    int rows = 0;
    int cols = 0;
    int count = 0;
    int movingCount(int m, int n, int k) {
        rows=m;
        cols=n;
        vector<vector<bool> > vis(m, vector<bool>(n));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=false;
            }
        }

        count=check(0, 0, k, vis);
        cout << count << endl;
        return count;
    }

    int check(int row, int col, int target, vector<vector<bool> >& vis){
        if(row < 0 || row >= rows || col < 0 || col >= cols || vis[row][col] == true || (dig(row)+dig(col)) > target){
            return 0;
        }
        vis[row][col]=true;
        count++;
        cout << row << "-" << col << "-" << count << endl;
        check(row + 1, col, target, vis);
        check(row - 1, col, target, vis);
        check(row, col - 1, target, vis);
        check(row, col + 1, target, vis);
        return count;
    }
    
    int dig(int num){
        int sum = 0;
        while(num!=0){
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
};

long quickPow(int m, int n) {
    long res = 1;
    long tt = m;
    while (n != 0) {
        if ((n & 1) == 1) {
            res *= tt;
            res = res % 1000000007;
        }
        tt *= tt;
        tt = tt % 1000000007;
        n = n / 2;

    }
    return res;
}

int main() {
    Solution s;
    // s.movingCount(3, 2, 17);
    long res = quickPow(2, 3);
    cout << res;

}