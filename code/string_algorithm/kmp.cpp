#include<iostream>
using namespace std;
#include<vector>

vector<int> getNext(string p);
int KMP(string str1, string p);

int main(){

    string str1 = "aa奶茶加盟";
    string str2 = "奶茶1";
    int flag = KMP(str1, str2);
    cout << "flag:" << flag << endl;
    int ans = str1.find(str2);
    
    if(ans == string::npos){
        cout << ans << "\t" << int(string::npos) << endl;
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

}

vector<int> getNext(string p){
    int len = p.size();
    vector<int> vec(len);
    int i = 0, j = -1;
    vec[0] = -1;
    while(i < len){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            vec[i] = j;
        }else{
            j = vec[j];
        }
    }

    return vec;
}

int KMP(string t, string p){
    int i = 0;
    int j = 0;
    int len1 = t.size();
    int len2 = p.size();
    vector<int> next = getNext(p);
    while(i < len1 && j < len2){
        if(j == -1 || t[i] == p[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }
    if(j == len2){
        return i - j;
    }else{
        return -1;
    }

}