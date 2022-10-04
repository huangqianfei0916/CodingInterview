/*
 * @Author: huangqianfei
 * @Date: 2022-09-30 20:18:19
 * @Description: 
 */

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int start, int end) {
    int index = start  + rand() % (end - start + 1);
    swap(vec[index], vec[end]);
    int small = start - 1;

    for (int i = start; i <= end; ++i) {
        if (vec[i] >= vec[end]) {
            ++small;
            if (i > small) {
                swap(vec[i], vec[small]);
            }
        }
    }
    return small;

}

void quick_sort(vector<int>& vec, int start, int end) {
    if (start > end) {
        return;
    }
    int index = partition(vec, start, end);
    if (index > start) {
        quick_sort(vec, start, index - 1);
    }
    if (index < end) {
        quick_sort(vec, index + 1, end);
    }
}

int main() {
    vector<int> vec = {2, 1, 3, 5, 4};
    quick_sort(vec, 0, vec.size() - 1);
    for (auto item : vec) {
        cout << item << "-" << endl;
    }

    return 0;
}