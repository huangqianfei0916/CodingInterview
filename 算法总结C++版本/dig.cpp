#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
using namespace std;
    
int dig (int m) {
    
    int res = 0;
    while (m != 0) {
        int temp = m % 10;
        res += temp;
        m = m / 10;
    }
    return res;
}

int dig1 (int m) {
    int len = to_string(m).size();
    set<int> char_set;

    while (m != 0) {
        int temp = m % 10;
        char_set.insert(temp);
        m = m / 10;
    }

    return char_set.size() == len ? 1 : 0;
}
    
int maximumSum(vector<int>& nums) {
    int max_value = -1;
    map<int, vector<int>> m;
    
    for (int i = 0; i < nums.size(); ++i) {
        int temp = dig(nums[i]);
        m[temp].push_back(nums[i]);
    }
    
    for (auto it = m.begin(); it != m.end(); ++it) {
        vector<int> value = it->second;
        if (value.size() < 2) {
            continue;
        } else {
            int m1 = 0;
            int m2 = 0;
            for (auto item: value) {
                m2 = max(m2, item);
                if (m2 > m1) {
                    swap(m1, m2);
                }
            }
            max_value = max(max_value, m1 + m2);
        }
    }
    
    return max_value;
}


int dig2 (int m) {
    string m_str = to_string(m);
    int len = m_str.size();
    set<int> char_set;

    for (int i = 0; i < m_str.size(); ++i)
    {
        char_set.insert(int(m_str[i] - '0'));
    }

    return char_set.size() == len ? 1 : 0;

}


int dig3(int n) {
    if (n == 0) return 1;
    else if (n == 1) return 10;
    else {
        int cnt = 10, j = 9;
        for (int i = 0; i < n - 1; ++i)
        {
            j = j * (9 - i);
            cnt = cnt + j;
        }
        return cnt;
    }
}

int test(int n) {
    int count = 0;

    while(n) {
        n = (n / 10);
        ++count;
    }
    return count - 1;
}




int main() {
    // vector<int> d = {9, 2, 2, 5};
    // swap(d[0], d[1]);
    // cout << d[0];

    // int a = 10, b = 20;
    // decltype(a + b) c;
    // cout << typeid(c).name() << endl;

    cout << test(135) << endl;
    int n = test(135);

    int res = 0;
    res += dig3(n);
    cout << res << endl;

    int df = 135 - pow(10, n);

    for (int i = pow(10, n); i <= 135; ++i) {
        if (dig1(i) == 1) {
            ++res;
        }
    }
    cout << res - 1;




}