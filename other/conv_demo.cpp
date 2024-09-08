#include<iostream>
using namespace std;
#include<vector>
#include<math.h>


/*
 进制之前的转化，以为10进制和2进制之间的转化为例子；
22  -> 10110
其中22 % 2 每次取余数，然后将结果反转可以得到对应的2进制
1 * 2^4 + 1 * 2^2 + 1 * 2^1 = 22

22 -> 26(8进制)
2 * 8^1 + 6 * 8^0 = 22
*/

string conv(int m, int n);
string reverse_conv(string m, int n);

int main() {
    string res = conv(12, 2);
    cout << res << endl;
    cout << "-------" << endl;
    string final = reverse_conv(res, 2);
}

// 将10进制转化为其他进制，m为数字，n为要转化的进制
string conv(int m, int n) {
    bool flag = true;
    vector<int> vec;
    string hex = "0123456789ABCDEF";
    string res = "";

    if (m < 0) {
        m = -m;
        flag = false;
    }

    while (m!=0) {
        int temp = m % n;
        temp = hex.find(to_string(temp));
        vec.push_back(temp);
        m = m / n;
    }
    reverse(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
    }
    
    if (flag) {
        return res;
    } else {
        return "-" + res;
    }
}

// 将其他进制转化为10进制，m为当前数字，n为当前进制
string reverse_conv(string m, int n) {
    string res = "";
    double sum = 0;
    int k = 0;
    int len = m.size() - 1;
    for (int i = len; i >= 0; --i) {
        int temp = m[i] - '0';
        sum += temp * pow(n, k);
        ++k;
    }
    cout << sum << endl;
    return res;
}