#include <iostream>
#include <vector>
using namespace std;


void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partion(int a[], int start, int end){
    int index = rand()%(end - start + 1) + start;
    int small = start - 1;
    swap(a, index, end);
    for(int i = start; i <= end; i++){
        if(a[i] <= a[end]){
            small ++;
            if(i > small){
                swap(a, i ,small);
            }
        }
    }
    return small;
}

void QuickSort(int arr[], int start, int end){
    if(start > end){
        return;
    }


    int index = partion(arr, start, end);
    if(index > start){
        QuickSort(arr, start, index - 1);
    }
    if(index < end){
        QuickSort(arr, index + 1, end);
    }


}

int main(){
    int a[] = {30, 2, 1, 5, 4};
    QuickSort(a, 0, 4);
    int len = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < len; i++){
        cout << a[i];
    }

}
