#include <iostream>
#include <vector>
using namespace std;



int partiton(vector<int>& vec, int start, int end) {
    int index = start + rand() % (end - start + 1);
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

void quickSort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    int index = partiton(vec, start, end);

    if (index > start) {
        quickSort(vec, start, index - 1);
    }
    if (index < end) {
        quickSort(vec, index + 1, end);
    }
}

int main() {

    vector<int> vec = {1, 3, 2, 5, 4, 9};
    quickSort(vec, 0, vec.size());

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}