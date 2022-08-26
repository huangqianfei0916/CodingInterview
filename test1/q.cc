#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

int partion(vector<int>& vec, int start, int end) {
    int index = start + rand() % (end - start + 1);
    swap(vec, index, end);
    int small = start -1;
    for (int i = start; i <= end; ++i) {
        if (vec[i] >= vec[end]) {
            small++;
            if (i > small) {
                swap(vec, i, small);
            }
        }
    }
    return small;
}

void QuickSort(vector<int>& vec, int start, int end) {
    if (start > end) {
        return;
    }
    int index = partion(vec, start, end);

    if (index > start) {
        QuickSort(vec, start, index - 1);
    }
    if (index < end) {
        QuickSort(vec, index + 1, end);
    }

}


bool isPalindrome(string s) {
    string sgood;
    for (char ch: s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend());
    return sgood == sgood_rev;
}


int main() {
    // vector<int> vec = {30, 2, 1, 5, 4};
    // QuickSort(vec, 0, vec.size() - 1);
    // for (int i = 0; i < vec.size(); ++i) {
    //     cout << vec[i] << endl;
    // }

    cout << abs(-1);
}