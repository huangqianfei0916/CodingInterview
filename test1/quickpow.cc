#include <iostream>
using namespace std;
#include <vector>


long quick_pow(int x, int n) {
    long res = 1;
    long temp = x;

    while (n != 0) {
        if ((n % 2) == 1) {
            res *= temp;
            res = res % 1000000007;
            --n;
        } else {
            temp = temp * temp;
            temp = temp % 1000000007;
            n = n / 2;
        }
    }
    return res;
}

int main() {
    long res = quick_pow(2, 4);
    cout << res << endl;
    vector<int> vec = {1, 2, 3, 4};

    swap(vec[1], vec[2]);
    cout << vec[1] << endl;
}