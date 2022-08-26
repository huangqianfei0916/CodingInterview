#include <iostream>  
#include <algorithm>  
using namespace std; 
#include <vector>



vector<char> vec;
vector<vector<char>> vec_all;
vector<bool> vis;


void dfs(string num) {

    if (vec.size() == num.size()) {
        vec_all.push_back(vec);
        return
    }

    for (int i = 0; i < num.size(); ++i) {
        if (vis[i]) {
            continue;
        }
        vec.push_back(num[i]);
        vis[i] = true;
        dfs(num);
        vis[i] = false;
        vec.pop_back();
    }

}

void run_dfs(string num) {

    int len = num.size();
    vis.resize(len);

    dfs(num);

    for (int i = 0 ; i < vec_all.size(); ++i) {
        for (int j = 0; j < vec_all[i].size(); ++j) {
            cout << vec_all[i][j];
        }
        cout << endl;
    }
    
}

int main()  
{  
    // int num[3]={9,2,3};  
    // do  
    // {  
    //     cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;  
    // }while(next_permutation(num,num+3));  

    // cout << "---" << endl;
    // for (int i = 0; i < sizeof(num)/sizeof(num[0]); ++i) {
    //     cout << num[i] << endl;
    // }

    string num = "1234";
    run_dfs(num);
    return 0;  
}  