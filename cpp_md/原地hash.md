#### [剑指 Offer 03. 数组中重复的数字](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
这原地hash的特例，不用forwhile将num移动到自己对应位置
```cpp
int findRepeatNumber(vector<int>& nums) {

    for (int i = 0; i < nums.size(); ) {

        if (i == nums[i]) {
            ++i;
            continue;
        }

        if (nums[i] == nums[nums[i]]) {
            return nums[i];
        } else {
            swap(nums[i], nums[nums[i]]);
        }
    }
    return -1;
}
```
#### [442. 数组中重复的数据](https://leetcode.cn/problems/find-all-duplicates-in-an-array/)
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。
for(while())结构将num调整到自己应该在的位置，然后不在自己位置的就是重复的。
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> vec;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                vec.push_back(nums[i]);
            }
        }
        return vec;

    }
};
```
#### [448. 找到所有数组中消失的数字](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/)
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> vec;
        for (int i = 0; i < nums.size(); ++i) {

            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 != nums[i]) {
                vec.push_back(i + 1);
            }
        }
        return vec;

    }
};
```
## 41-缺失的第一个正数-原地hash
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
解析将数据放到正确的位置，然后在判断nums[i] ==  i  +1
[3,4,-1,1]
-1,4,3,1
-1,1,3,4
1,-1,3,4
这一题和剑指offer03区别在于，03题可以不用while多次判断调整数组，这题因为存在缺失，要用while，同时判断num的取值范围。
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {

            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
```
#### [189. 轮转数组](https://leetcode.cn/problems/rotate-array/)
给你一个数组，将数组中的元素向右轮转 k_ _个位置，其中 k_ _是非负数。
**输入:** nums = [1,2,3,4,5,6,7], k = 3 **输出:** [5,6,7,1,2,3,4]
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (nums.size() == 0) {
            return;
        }
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
#### [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)（原地）
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {

            if (nums[i] == nums[j]) {
                continue;
            } else {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;

    }
};
```
#### [27. 移除元素](https://leetcode.cn/problems/remove-element/)(原地)
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {

            if (nums[i] == val) {
                continue;
            }  else {
                nums[j] = nums[i];
                ++j;
            }
        }
    return j;
    }

};
```
