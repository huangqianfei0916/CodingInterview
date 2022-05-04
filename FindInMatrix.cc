#include <iostream>
using namespace std;


bool find_method(int* matrix,int rows,int cols, int number) {
    if (matrix == nullptr) {
        return false;
    }
    int i = 0;
    int j = cols - 1;
    while (i<rows && j>0) {
        if (matrix[i*cols+j] < number) {
            i++;
        } else if (matrix[i*cols+j] > number) {
            j --;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int a[]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    bool res = find_method(a,4,4,111);
    cout << res;

    return 0;
}