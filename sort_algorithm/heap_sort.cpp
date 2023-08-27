/*
 * @Author: huangqianfei
 * @Date: 2022-10-02 08:03:49
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;


void heap(vector<int>& vec, int i, int length) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int max_index = i;

    if (left <= length && vec[left] > vec[max_index]) {
        max_index = left;
    }

    if (right <= length && vec[right] > vec[max_index]) {
        max_index = right;
    }

    if (i != max_index) {
        swap(vec[i], vec[max_index]);
        heap(vec, max_index, length);
    }
}

int main() {
    vector<int> vec = {1, 2, 4, 0, 3};
    int length = vec.size() - 1;


    for (int i = (length / 2); i >= 0; --i) {
        heap(vec, i, length);
    }

    for (int i = length; i > 0; --i) {
        swap(vec[i], vec[0]);
        --length;
        heap(vec, 0, length);
    }

    return 0;
}
