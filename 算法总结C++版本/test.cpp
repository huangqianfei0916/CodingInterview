
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    set<char> charSet;
    int k = 0;

    for (int i = 0; i < s.size(); ) {
        set<char>::iterator it = charSet.find(s[i]);
        if (it != charSet.end()) {
            // contain
            charSet.erase(s[k++]);
        } else {
            // not contain
            charSet.insert(s[i]);
            ++i;
            int len = charSet.size();
            max_len = max(len, max_len);

        }
    }
    return max_len;

}

void testVector() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    for (int i = 0; i < 5; ++i) {
        cout << *vec.begin() << endl;
        vec.erase(vec.begin());
    }
    cout << "---" << endl;

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}

int main() {
    // string temp = "abcabcbb";
    // int d = lengthOfLongestSubstring(temp);
    // // cout << d;
    // testVector();
    // vector<int> vec;
    // vector<int> vec1;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(4);
    // vec.push_back(9);
    // int d = *max_element(vec.begin(), vec.end());
    // int target = 2533;
    // int first = 2533 / 1000;

    // vector<int>::iterator it = find(vec.begin(), vec.end(), first);
    // int flag = 0;
    // string df = to_string(target);
    // cout << df << endl;
    // for (int i = 0; i < df.size(); ++i) {
    //     cout << df[i] - '0' << endl;
    // }

    string sd = "test";
    char temp = sd[0];
    vector<char> d;
    d.push_back('t');
    if (d[0] == temp) {
        cout << "ds";
    }



}