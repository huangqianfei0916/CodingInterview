#include <iostream>
using namespace std;
#include <vector>

void swap(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void heap(vector<int>& vec, int i, int len) {
    
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left <= len && vec[left] > vec[largest]) {
        largest = left;
    }
    if (right <= len && vec[right] > vec[largest]) {
        largest = right;
    }
    if (i != largest) {
        swap(vec, i, largest);
        heap(vec, largest, len);
    }
}

void test(vector<int>& vec) {

    int len = vec.size() - 1;
    for(int i = len/2 - 1; i >= 0; --i){
        heap(vec, i, len);
    }
    for (int i = len; i > 0; --i) {
        swap(vec, i, 0);
        len--;
        heap(vec, 0, len);
    }
    
}

int main() {
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    test(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

}

