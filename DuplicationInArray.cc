#include<iostream>
using namespace std;
#include<map>


// 方法1，通过map解决，时间复杂度和空间复杂度都是o(n)
bool method1(int numbers[], int length, int * duplication){
    if(length <= 0 || numbers == nullptr){
        return false;
    }
    map<int, int>map;
    for(int i=0;i<length;i++){
        if(map.find(*duplication)!=map.end()){
            
            int temp = map[numbers[i]];
            temp ++;
            map.insert(pair<int,int>(numbers[i],temp));
            return true;
        }else{
            map.insert(pair<int,int>(numbers[i],1));
        }
    }
    return false;
}

int main(){
    int array[] = {2,3,1,0,2,5,3};
    int length = sizeof(array)/sizeof(array[0]);
    int num = 2;
    bool res = method1(array,length,&num);
    cout << res;


    return 0;
}