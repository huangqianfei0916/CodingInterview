#include<iostream>
using namespace std;
#include<vector>



void vector_demo(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);

    // 遍历
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << endl;
    }
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;
    }

    // 查找
    vector<int>::iterator it = find(vec.begin(), vec.end(), 2);
    if(it != vec.end()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    // 排序，降序只需要将起末颠倒即可
    sort(vec.rbegin(), vec.rend());
    // 反转
    reverse(vec.begin(), vec.end());
    // 大小
    cout << vec.size() << vec.empty() << endl;
    
    // 清空
    vec.clear();
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << endl;
    }
}


int main(){
    vector_demo();


    return 0;
}