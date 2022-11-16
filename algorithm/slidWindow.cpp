#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值
vector<int> getSlidMax(vector<int> vec, int size) {
    vector<int> vec_res;
    if (vec.size() == 0) {
        return vec_res;
    }

    deque<int> dq;
    for (int i = 0; i < vec.size(); ++i) {

        while(dq.size() != 0 && vec[dq.back()] < vec[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (dq.front() == i - size) {
            dq.pop_front();
        }

        if (i >= size - 1) {
            vec_res.push_back(vec[dq.front()]);
        }
    }
    return vec_res;
}

void print_vec(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
int getUnsortArr(vector<int> vec) {
    vector<int> vec_copy;
    for (int i = 0; i < vec.size(); ++i) {
        vec_copy.push_back(vec[i]);
    }
    sort(vec_copy.begin(), vec_copy.end());
    print_vec(vec_copy);
    int l = 0;
    int r = vec_copy.size() - 1;
    bool left_flag = false;
    bool right_flag = false;

    while (l < r) {
        if (vec[l] == vec_copy[l]) {
            ++l;
        } else {
            left_flag = true;
        }
        if (vec[r] == vec_copy[r]) {
            --r;
        } else {
            right_flag = true;
        }

        if (left_flag && right_flag) {
            break;
        }
    }

    return (r - l + 1);
}

// 求排序数组中某一个数字出现的次数
int getFirst(vector<int> vec, int target) {
    int l = 0;
    int r = vec.size() - 1;
    int mid = (l + r) / 2;

    while (l <= r) {
        mid = (l + r) / 2;
        if (vec[mid] == target) {
            if (mid > 0 && vec[mid - 1] != target || mid == 0) {
                return mid;
            } else {
                r = mid - 1;
            }

        } else if (target < vec[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}

int getLast(vector<int> vec, int target) {
    int l = 0;
    int r = vec.size() - 1;
    int mid = (l + r) / 2;

    while (l <= r) {
        mid = (l + r) / 2;
        if (vec[mid] == target) {
            if (mid < (vec.size() - 1) && vec[mid + 1] != target || mid == (vec.size() - 1)) {
                return mid;
            } else {
                l = mid + 1;
            }

        } else if (target < vec[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}


// 3sum:先排序再双指针，注意过滤重复结果
vector<vector<int> > vec_all;
vector<vector<int> > threeSum(vector<int>& nums) {
    if (nums.size() == 0) {
        return vec_all;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i< nums.size(); ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                vector<int> vec;
                vec.push_back(nums[i]);
                vec.push_back(nums[l]);
                vec.push_back(nums[r]);
                vec_all.push_back(vec);
                while (l < r && nums[l] == nums[l+1]) {
                    ++l;
                }
                while (l < r && nums[r] == nums[r-1]) {
                    --r;
                }
                ++l;
                --r;
            } else if (sum < 0) {
                ++l;
            } else {
                --r;
            }
        }
    }
    return vec_all;

}


int main() {
    vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(4);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(15);

    vector<int> vec_des = getSlidMax(vec1, 3);
    getUnsortArr(vec1);
    int a = getFirst(vec1, 4);
    cout << a << endl;
    int b = getLast(vec1, 4);
    cout << b << endl;

}
