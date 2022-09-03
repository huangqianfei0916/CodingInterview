#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    vector<vector<int> > vec_all;
    vector<int> vec;
    vector<bool> vis;
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) {
            return vec_all;
        }

        vis.resize(nums.size());
        dfs(nums, 0);
        return vec_all;
    }

    void dfs(vector<int>& nums, int begin) {
        if (vec.size() == nums.size()) {
            vec_all.push_back(vec);
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            // if (vis[i]) {
            //     continue;
            // }
            vec.push_back(nums[i]);
            vis[i] = true;
            dfs(nums, i + 1);
            vis[i] = false;
            vec.pop_back();
        }

    }

};
#include <cmath>
int main() {
    vector<int> vec = {1, 2, 3};
    Solution* s = new Solution();
    s->permute(vec);

    return 0;
}