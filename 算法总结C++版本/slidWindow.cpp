#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 滑动窗口中最大值
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

int main() {
    vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(2);
    vec1.push_back(6);
    vec1.push_back(2);
    vec1.push_back(5);
    vec1.push_back(1);

    vector<int> vec_des = getSlidMax(vec1, 3);

    for (int i = 0; i < vec_des.size(); ++i) {
        cout << vec_des[i] << endl;
    }

}
