找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 

限制：

2 <= n <= 100000

解法一：通过set辅助实现
时间复杂度：o(N)
空间复杂度：o(N)

```cpp
int findRepeatNumber(vector<int>& nums) {
    set<int> nums_set;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums_set.find(nums[i]) == nums_set.end()) {
            nums_set.insert(nums[i]);
        } else {
            return nums[i];
        }
    }

    return -1;
}
```

解法二：原地hash
时间复杂度：o(N)
空间复杂度：o(1)
```cpp
int findRepeatNumber(vector<int>& nums) {


    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] != nums[nums[i]]) {
            swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (i != nums[i]) {
            return nums[i];
        }
    }

    return -1;
}
```
