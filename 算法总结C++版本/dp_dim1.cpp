#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 单词切分
dp[0]:空可以被表示
dp[i]:截止第i的字符串，时候可以被表示
d[i] = ture 的条件是 ：d[j] = ture并且s[j, i]在hash表中存在。
以s = "leetcode", wordDict = ["leet", "code"] 为例子
当i = 8, j = 4, dp[4]=true，表示leet可以被表示，同时，code在 wordDict中就表示可以被表示
*/

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            string temp = s.substr(j, i - j);
            
            vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), temp);
            if (dp[j] && it != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    // for (int i = 0; i < dp.size(); ++i) {
    //     cout << dp[i] << endl;
    // }
    
    return dp[s.size()];

}
