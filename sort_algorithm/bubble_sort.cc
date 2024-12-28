/*
 * Copyright (c) 2024 by huangqianfei@tju.edu.cn All Rights Reserved. 
 * @Author: huangqianfei@tju.edu.cn
 * @Date: 2024-11-26 22:01:33
 * @Description: 
 */
#include <iostream>
using namespace std;
#include <vector>

void bubble_sort(vector<int>& vec) {

    int len = vec.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j + 1], vec[j]);
            }
        }
    }
}
int main() {

    vector<int> vec = {2, 3, 1, 7, 6, 5, 4};
    bubble_sort(vec);
    for (auto& item : vec) {
        cout << item << endl;
    }
}
