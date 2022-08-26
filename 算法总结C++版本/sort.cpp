#include <iostream>
#include <vector>
#include <map>
using namespace std;

// void swap(vector<int>& vec, int i, int j) {
//     int temp = vec[i];
//     vec[i] = vec[j];
//     vec[j] = temp;
// }

int partion(vector<int>& vec, int start, int end) {
    int index = start + rand() % (end - start + 1);
    // swap(vec, index, end);
    swap(vec[index], vec[end]);
    int small = start -1;
    for (int i = start; i <= end; ++i) {
        if (vec[i] <= vec[end]) {
            small++;
            if (i > small) {
                // swap(vec, i, small);
                swap(vec[i], vec[small]);
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

int main() {
    vector<int> vec = {30, 2, 1, 5, 4};
    QuickSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }


}