"""leetcode-39:原数组无重复元素+每个元素可重复使用->LeetCode-39
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
你可以按 任意顺序 返回这些组合。candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
"""

class Solution {
public:
    vector<vector<int>> vec_all;
    vector<int> vec;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 这里sort是因为，如果不排序的话像【2，7，3，6】判断2+7>7，后面的就不会判断了
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, candidates.size(), 0);
        return vec_all;
    }

    void dfs(vector<int> candidates, int target, int len, int begin){
        if(target == 0){
            vec_all.push_back(vec);
        }
        for(int i = begin; i < len; ++i){
            if(target - candidates[i] < 0){
                break;
            }

            vec.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], len, i);
            vec.pop_back();
        }

    }
};


"""leetcode-40:原数组有重复元素+每个元素不可重复使用
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
"""
class Solution {
public:
    vector<vector<int>> vec_all;
    vector<int> vec;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, candidates.size(), 0);
        return vec_all;
    }
    void dfs(vector<int> candidates, int target, int len, int begin){
        if(target == 0){
            vec_all.push_back(vec);
        }
        for(int i = begin; i < len; ++i){
            if(target - candidates[i] < 0){
                break;
            }
            if(i > begin && candidates[i] == candidates[i-1]){
                continue;
            }

            vec.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], len, i + 1);
            vec.pop_back();
        }
    }
};

"""leetcode-46:无重复序列的全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
"""

class Solution {
public:
    vector<vector<int>> vec_all;
    vector<int> vec;
    vector<int> vis;
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            vis.push_back(0);
        }
        dfs(nums, len, 0);
        return vec_all;

    }

    void dfs(vector<int> nums, int len, int begin){
        if(vec.size() == len){
            vec_all.push_back(vec);
        }

        for(int i = 0;i < len; i++){
            if(vis[i] == 1){
                continue;
            }
            vec.push_back(nums[i]);
            vis[i] = 1;
            dfs(nums, len, begin);
            vis[i] = 0;
            vec.pop_back();

        }
    }
};

"""leetcode-47:可重复序列的全排列
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
"""

class Solution {
public:
    vector<vector<int>> vec_all;
    vector<int> vec;
    vector<int> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            vis.push_back(0);
        }
        sort(nums.begin(), nums.end());
        dfs(nums, len, 0);
        return vec_all;
    }

    void dfs(vector<int> nums, int len, int begin){
        if(vec.size() == len){
            vec_all.push_back(vec);
            return;
        }
        for(int i = begin; i < len; i++){
            if(vis[i] == 1){
                continue;
            }
            if(i > begin && nums[i] == nums[i-1] && vis[i - 1] == 0){
                continue;
            }
            vec.push_back(nums[i]);
            vis[i] = 1;
            dfs(nums, len, begin);
            vis[i] = 0;
            vec.pop_back();
        }
    }
};