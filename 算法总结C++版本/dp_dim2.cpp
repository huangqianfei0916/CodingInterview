#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<vector<int> >vec_all) {
    for (int i = 0; i < vec_all.size(); ++i) {
        for (int j = 0; j < vec_all[i].size(); ++j) {
            cout << vec_all[i][j] << " ";
        }
        cout << endl;
    }

}
vector<vector<int> > generate(int numRows) {
    vector<vector<int> > vec_all(numRows);
    for (int i = 0; i < numRows; ++i) {
        vec_all[i].resize(i + 1);
    }
    // 初始化
    for (int i = 0 ; i < numRows; ++i) {
        vec_all[i][0] = 1;
        vec_all[i][i] = 1;
    }
    for (int i = 2; i < numRows; ++i) {
        for (int j = 1; j < i; ++j) {
            vec_all[i][j] = vec_all[i - 1][j] + vec_all[i - 1][j - 1];
        }
    }
    print_vec(vec_all);
    return vec_all;
}

// 最长公共子序列
vector<vector<int> > longSubSeq(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int> > vec_all(len1 + 1, vector<int>(len2 + 1));
    for (int i = 0; i < len1; ++i) {
        vec_all[i][0] = 0;
    }

    for (int i = 0; i < len2; ++i) {
        vec_all[0][i] = 0;
    }

    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (str1[i] == str2[j]){
                vec_all[i + 1][j + 1] = vec_all[i][j] + 1;
            } else {
                vec_all[i + 1][j + 1] = max(vec_all[i + 1][j], vec_all[i][j + 1]);
            }
        }
    }
    print_vec(vec_all);
    return vec_all;
}

// 最长公共子串
int longSubStr(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int> > vec_all(len1 + 1, vector<int>(len2 + 1));
    for (int i = 0; i < len1; ++i) {
        vec_all[i][0] = 0;
    }

    for (int i = 0; i < len2; ++i) {
        vec_all[0][i] = 0;
    }
    int res = 0;
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (str1[i] == str2[j]){
                vec_all[i + 1][j + 1] = vec_all[i][j] + 1;
            } else {
                vec_all[i + 1][j + 1] = 0;
            }

            res = max(res, vec_all[i + 1][j + 1]);
        }
    }
    print_vec(vec_all);
    cout << res;
    return res;
}

// editDistance
int editDistance(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int> > vec_all(len1 + 1, vector<int>(len2 + 1));
    for (int i = 0; i < len1; ++i) {
        vec_all[i][0] = i;
    }

    for (int i = 0; i < len2; ++i) {
        vec_all[0][i] = i;
    }
    int res = 0;
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (str1[i] == str2[j]){
                vec_all[i + 1][j + 1] = vec_all[i][j];
            } else {
                vec_all[i + 1][j + 1] = min(vec_all[i][j] + 1, min(vec_all[i + 1][j] + 1, vec_all[i][j + 1] + 1));
            }
        }
    }
    print_vec(vec_all);
    return res;
}

int main() {
    // generate(5);
    // longSubSeq("abcde", "ace");
    // longSubStr("helloword", "loop");
    editDistance("horse", "ros");

    return 0;
}